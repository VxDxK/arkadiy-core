#include "servo_wrap.h"
#include "spider.h"

#define SERVO_COUNT 12

ServoWrap servos[SERVO_COUNT];
int ports[SERVO_COUNT] = { 9, 10, 12, 8, 11, 13, 7, 5, 3, 6, 4, 2 };
Spider spider;

String message;

void setup()
{
    Serial.begin(9600);
    servos[0].attach(ports[0], 0, 100);
    servos[1].attach(ports[1], 0, 85);
    servos[2].attach(ports[2], 175, 0);

    servos[3].attach(ports[3], 180, 80);
    servos[4].attach(ports[4], 165, 80);
    servos[5].attach(ports[5], 0, 180);

    servos[6].attach(ports[6], 0, 100);
    servos[7].attach(ports[7], 0, 100);
    servos[8].attach(ports[8], 172, 0);

    servos[9].attach(ports[9], 180, 80);
    servos[10].attach(ports[10], 180, 80);
    servos[11].attach(ports[11], 20, 180);

    spider.attachServos(servos);

    spider.defaultPosition();
}


void loop()
{
    while (Serial.available()) {
        char incomingChar = Serial.read();
        if (incomingChar == '\n') {
            if (message == "sp") {
                Serial.print("Start position");
                spider.startPosition();
            } else if (message == "su") {
                Serial.print("Stand up");
                spider.standUp();
            } else if (message == "ruka") {
                Serial.print("Hi bro :)");
                spider.upLeg();
            } else if (message == "go") {
                Serial.print("GO GO GO!!!");
                spider.defaultPosition();
                spider.safeTimeStepForward();
            } else if (message == "def") {
                Serial.print("Default position");
                spider.defaultPosition();
            }

            message = "";
        } else {
            message += incomingChar;
        }
    }
}
