#include "openag_pwm_actuator.h"

PwmActuator::PwmActuator(int pin, bool is_active_low, float threshold) {
  _pin = pin;
  _is_active_low = is_active_low;
  _threshold = threshold;
  status_level = OK;
  status_msg = "";
}

void PwmActuator::begin() {
  pinMode(_pin, OUTPUT);
}

void PwmActuator::update() {}

void PwmActuator::set_cmd(std_msgs::Float32 cmd) {
  float val = cmd.data;
  if (val < 0 || val > 1) {
    status_level = WARN;
    status_msg = "Invalid command received";
    return;
  }
  else {
    status_level = OK;
    status_msg = "";
  }
  val = _threshold + (1-_threshold)*val;
  if (_is_active_low) {
    val = 1-val;
  }
  int pwm_value = val*255;
  analogWrite(_pin, pwm_value);
}
