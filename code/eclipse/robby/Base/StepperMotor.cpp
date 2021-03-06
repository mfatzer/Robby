/*
 * StepperMotor.cpp
 *
 *  Created on: 20.06.2015
 *      Author: Martin
 */

#include "StepperMotor.h"
#include "Arduino.h"

void delay_1us();
MotorDirection reverseDirection(MotorDirection dir);


StepperMotor::StepperMotor(const char* name, const int stepPin, const int directionPin, const bool reverseDirection)
: m_logger(name), m_stepPin(stepPin), m_directionPin(directionPin), m_reverseDirection(reverseDirection)
{
	setDirection(STOP);
}

StepperMotor::~StepperMotor() {
}

void StepperMotor::setup() {
	pinMode(m_stepPin, OUTPUT);
	pinMode(m_directionPin, OUTPUT);
	digitalWrite(m_stepPin, LOW);
	digitalWrite(m_directionPin, LOW);
	m_logger.log("setup()");
}

void StepperMotor::step() {
	// do nothing if motor is stopped
	if (m_direction == STOP) {
		return;
	}
	digitalWrite(m_stepPin, HIGH);
	delay_1us();
	digitalWrite(m_stepPin, LOW);
	m_logger.log("step()");
}

void StepperMotor::setDirection(MotorDirection dir) {
	m_direction = resolveDirection(dir);

	if (m_direction == FORWARD) {
		digitalWrite(m_directionPin, HIGH);
	}
	else if (m_direction == BACKWARD) {
		digitalWrite(m_directionPin, LOW);
	}
	m_logger.log("setDirection()");
}

MotorDirection StepperMotor::resolveDirection(MotorDirection dir) {
	if (m_reverseDirection) {
		return reverseDirection(dir);
	}
	else {
		return dir;
	}
}

// 16 single cycle instructions = 1us at 16Mhz
void delay_1us()
{
  __asm__ __volatile__ (
	"nop" "\n\t"
	"nop" "\n\t"
	"nop" "\n\t"
	"nop" "\n\t"
	"nop" "\n\t"
	"nop" "\n\t"
	"nop" "\n\t"
	"nop" "\n\t"
	"nop" "\n\t"
	"nop" "\n\t"
	"nop" "\n\t"
	"nop" "\n\t"
	"nop" "\n\t"
	"nop" "\n\t"
	"nop" "\n\t"
	"nop" "\n\t");
}

MotorDirection reverseDirection(MotorDirection dir) {
	if (dir == FORWARD) {
		return BACKWARD;
	}
	else if (dir == BACKWARD) {
		return FORWARD;
	}
	return STOP;
}


