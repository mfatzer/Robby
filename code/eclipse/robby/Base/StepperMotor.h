/*
 * StepperMotor.h
 *
 *  Created on: 20.06.2015
 *      Author: Martin
 */

#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

#include "Logger.h"
#include "MotorDirection.h"

class StepperMotor {
public:
	StepperMotor(const char* name, const int stepPin, const int directionPin, const bool reverseDirection);
	virtual ~StepperMotor();

	void setup();
	void step();
	void setDirection(MotorDirection dir);

private:
	MotorDirection resolveDirection(MotorDirection dir);

private:
	const Logger m_logger;
	const int m_stepPin;
	const int m_directionPin;
	const bool m_reverseDirection;
	volatile int m_direction;
};

#endif /* STEPPERMOTOR_H_ */
