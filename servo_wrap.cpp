#include "servo_wrap.h"

void ServoWrap::attach(uint8_t pin)
{
    _servo.attach(pin);
}
void ServoWrap::attach(uint8_t pin, uint8_t min, uint8_t max)
{
    _servo.attach(pin);
    this->min = min;
    this->max = max;
}

uint8_t ServoWrap::getMin()
{
    return min;
}
uint8_t ServoWrap::getMax()
{
    return max;
}

void ServoWrap::setMin(uint8_t min)
{
    this->min = min;
}

void ServoWrap::setMax(uint8_t max)
{
    this->max = max;
}

uint8_t ServoWrap::read()
{
    return map(_servo.read(), min, max, 0, 100);
}

void ServoWrap::write(uint8_t percent)
{
    if (percent > 100 && percent < 0)
        return;
    _servo.write(map(percent, 0, 100, min, max));
}
