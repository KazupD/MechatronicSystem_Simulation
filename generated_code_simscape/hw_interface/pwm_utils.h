#define PWM_CHIP_PATH_0 "/sys/class/pwm/pwmchip0"
#define PWM_CHIP_PATH_1 "/sys/class/pwm/pwmchip1"
#define PWM_PIN_MAX_LEN 2

void export_pwm_pin_0(int pwm_pin);

void set_pwm_period_0(int period_ns, int pwm_pin);

void set_pwm_duty_cycle_0(int duty_cycle_ns, int pwm_pin);

void enable_pwm_0(int period_ns, int pwm_pin);


void export_pwm_pin_1(int pwm_pin);

void set_pwm_period_1(int period_ns, int pwm_pin);

void set_pwm_duty_cycle_1(int duty_cycle_ns, int pwm_pin);

void enable_pwm_1(int period_ns, int pwm_pin);
