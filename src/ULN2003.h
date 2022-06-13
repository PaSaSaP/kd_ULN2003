#ifndef HEADER_ULN2003_H_
#define HEADER_ULN2003_H_

#ifdef __cplusplus
extern "C" {
#endif

void stepperMotor_init(int in1, int in2, int in3, int in4);
void stepperMotor_setStepDuration(int duration);
void stepperMotor_step(int noOfSteps);

#ifdef __cplusplus
}
#endif

#endif /* HEADER_ULN2003_H_ */

