#ifndef SERVO_WRAP_H
#define SERVO_WRAP_H
#include "Servo.h"
#include "stdint.h"
#include <Arduino.h>

class ServoWrap {
public:
    void attach(uint8_t pin);
    void attach(uint8_t pin, uint8_t min, uint8_t max);

    uint8_t getMin();
    uint8_t getMax();

    void setMin(uint8_t min);
    void setMax(uint8_t max);

    uint8_t read();

    void write(uint8_t percent);

private:
    Servo _servo;
    uint8_t min { 0 };
    uint8_t max { 180 };
};

#endif // SERVO_WRAP