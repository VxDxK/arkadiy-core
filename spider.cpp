#include "spider.h"
void Spider::attachServos(ServoWrap* servs) { this->servos = servs; }

void Spider::safeTimeStepForward()
{
    safeTimeWrite(10, 100, 300);
    safeTimeWrite(9, 100, 300);
    safeTimeWrite(10, 70);

    safeTimeWrite(1, 100, 300);
    safeTimeWrite(0, 20, 300);
    safeTimeWrite(1, 70);

    for (int iLoveThisFukenRobot = 0; iLoveThisFukenRobot < 60; iLoveThisFukenRobot += 5) {
        safeTimeWrite(0, 20 + iLoveThisFukenRobot, 0);
        safeTimeWrite(9, 100 - iLoveThisFukenRobot, 0);
    }

    spiderDelay(1000);

    safeTimeWrite(7, 100, 300);
    safeTimeWrite(6, 100, 300);
    safeTimeWrite(7, 70);

    safeTimeWrite(4, 100, 300);
    safeTimeWrite(3, 20, 300);
    safeTimeWrite(4, 70);

    for (int iLoveThisFukenRobot = 0; iLoveThisFukenRobot < 60; iLoveThisFukenRobot += 5) {
        safeTimeWrite(3, 20 + iLoveThisFukenRobot, 0);
        safeTimeWrite(6, 100 - iLoveThisFukenRobot, 0);
    }

    spiderDelay(1000);
}

void Spider::stepForward()
{
    servos[10].write(100);
    spiderDelay(2000);
    servos[9].write(100);
    spiderDelay(300);
    servos[10].write(70);

    spiderDelay(500);

    servos[1].write(100);
    spiderDelay(2000);
    servos[0].write(20);
    spiderDelay(300);
    servos[1].write(70);

    spiderDelay(2000);

    for (int i = 0; i < 50; i++) {
        servos[0].write(20 + i);
        servos[9].write(100 - i);
        spiderDelay(10);
    }

    spiderDelay(2000);

    servos[7].write(100);
    spiderDelay(2000);
    servos[6].write(100);
    spiderDelay(300);
    servos[7].write(70);

    spiderDelay(500);

    servos[4].write(100);
    spiderDelay(2000);
    servos[3].write(20);
    spiderDelay(300);
    servos[4].write(70);

    spiderDelay(2000);

    for (int i = 0; i < 50; i++) {
        servos[3].write(20 + i);
        servos[6].write(100 - i);
        spiderDelay(10);
    }

    spiderDelay(2000);
};

void Spider::safeTimeWrite(int servoId, int percent, int afterDelay = 1000)
{
    servos[servoId].write(percent);
    while (true) {
        if (abs(servos[servoId].read() - percent) <= 1) {
            break;
        }
    }

    spiderDelay(afterDelay);
};

void Spider::upLeg()
{
    servos[0].write(0);
    spiderDelay(1000);
    servos[3].write(15);
    servos[4].write(80);
    servos[5].write(70);
};

void Spider::spiderDelay(int timing)
{
    unsigned long start = millis();
    while (true) {
        if (millis() - start >= timing)
            return;
    }
};

void Spider::defaultPosition()
{
    for (int i = 0; i < 4; i += 3) {
        servos[i].write(50);
        servos[i + 1].write(70);
        servos[i + 2].write(0);
    }
    spiderDelay(500);
    for (int i = 6; i < 12; i += 3) {
        servos[i].write(50);
        servos[i + 1].write(70);
        servos[i + 2].write(0);
    }
};

void Spider::startPosition()
{
    for (int i = 0; i < 12; i += 3) {
        servos[i].write(0);
        servos[i + 1].write(50);
        servos[i + 2].write(50);
    }
};

void Spider::standUp()
{
    for (int i = 1; i < 5; i += 3) {
        servos[i + 6].write(100);
        servos[i + 1].write(0);
        servos[i].write(100);
        servos[i + 1 + 6].write(0);
    }
    spiderDelay(2000);

    for (int i = 1; i < 5; i += 3) {
        servos[i].write(70);
        servos[i + 6].write(70);
    }

    spiderDelay(1000);

    defaultPosition();
};
