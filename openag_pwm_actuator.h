#ifndef OPENAG_PWM_ACTUATOR_H
#define OPENAG_PWM_ACTUATOR_H

#include "Arduino.h"
#include <std_msgs/Float32.h>
#include <openag_module.h>

class PwmActuator : public Module {
  public:
    // Constructor
    PwmActuator(int pin, bool is_active_low, float threshold);

    // Public functions
    void begin();
    void update();
    void set_cmd(std_msgs::Float32 cmd);

  private:
    // Private variables
    int _pin;
    bool _is_active_low;
    float _threshold;
};

#endif
