
#ifndef _AMotor_h_
#define _AMotor_h_

#include <inttypes.h>
#include <avr/io.h>

//#define MOTORDEBUG 1

#define MICROSTEPS 16                       // 8 or 16

#define MOTOR12_64KHZ _BV(CS20)             // no prescale
#define MOTOR12_8KHZ _BV(CS21)              // divide by 8
#define MOTOR12_2KHZ _BV(CS21) | _BV(CS20)  // divide by 32
#define MOTOR12_1KHZ _BV(CS22)              // divide by 64

#define MOTOR34_64KHZ _BV(CS00)             // no prescale
#define MOTOR34_8KHZ _BV(CS01)              // divide by 8
#define MOTOR34_1KHZ _BV(CS01) | _BV(CS00)  // divide by 64

#define DC_MOTOR_PWM_RATE   MOTOR34_8KHZ    // PWM rate for DC motors
#define STEPPER1_PWM_RATE   MOTOR12_64KHZ   // PWM rate for stepper 1
#define STEPPER2_PWM_RATE   MOTOR34_64KHZ   // PWM rate for stepper 2
    


// Bit positions in the 74HCT595 shift register output
#define MOTOR1_A 2
#define MOTOR1_B 3
#define MOTOR2_A 1
#define MOTOR2_B 4
#define MOTOR4_A 5
#define MOTOR4_B 7
#define MOTOR3_A 0
#define MOTOR3_B 6

// Constants that the user passes in to the motor calls
#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4

// Arduino pin names for interface to 74HCT595 latch
#define MOTORLATCH 12
#define MOTORCLK 4
#define MOTORENABLE 7
#define MOTORDATA 8

class AMotorController
{
  public:
    AMotorController(void);
    void enable(void);
    friend class AF_DCMotor;
    void latch_tx(void);
    uint8_t TimerInitalized;
};

class A_DCMotor
{
 public:
  A_DCMotor(uint8_t motornum, uint8_t freq = DC_MOTOR_PWM_RATE);
  void run(uint8_t);
  void setSpeed(uint8_t);

 private:
  uint8_t motornum, pwmfreq;
};


uint8_t getlatchstate(void);

#endif
