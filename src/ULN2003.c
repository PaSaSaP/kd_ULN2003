#include <Arduino.h>
#include "ULN2003.h"

int stepperMotor_inputPins[4] = {-1, -1, -1, -1};
int stepperMotor_duration = 50;
int8_t stepperMotor_sequence[][4] = {
    {LOW, LOW, LOW, HIGH},
    {LOW, LOW, HIGH, HIGH},
    {LOW, LOW, HIGH, LOW},
    {LOW, HIGH, HIGH, LOW},
    {LOW, HIGH, LOW, LOW},
    {HIGH, HIGH, LOW, LOW},
    {HIGH, LOW, LOW, LOW},
    {HIGH, LOW, LOW, HIGH}
};

void stepperMotor_init(int in1, int in2, int in3, int in4) {
    stepperMotor_inputPins[0] = in1;
    stepperMotor_inputPins[1] = in2;
    stepperMotor_inputPins[2] = in3;
    stepperMotor_inputPins[3] = in4;

    for (int i = 0; i < 4; ++i) {
        pinMode(stepperMotor_inputPins[i], OUTPUT);
    }

    stepperMotor_duration = 50;
}

void stepperMotor_setStepDuration(int duration) {
    stepperMotor_duration = duration;
}

void stepperMotor_step(int noOfSteps) {
    int factor = abs(noOfSteps) / noOfSteps; // 1 or -1, direction
    noOfSteps = abs(noOfSteps);

    for (int i = 0; i < noOfSteps / 8; ++i) {
        for (int p = 0; p < 8 && p < noOfSteps - i * 8; ++p) {
            delay(stepperMotor_duration);
            for (int d = 0; d < 4; ++d) {
                digitalWrite(stepperMotor_inputPins[d], 
                    stepperMotor_sequence[(int)(3.5 - (3.5 * factor) + (factor * p))][d]);
            }
        }
    }
}

