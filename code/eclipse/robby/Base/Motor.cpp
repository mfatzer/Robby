/*
 * Motor.cpp
 *
 *  Created on: 21.06.2015
 *      Author: Martin
 */

#include "Motor.h"

const unsigned int MAX_SPEED_TIMER_PERIOD = 2700;
const unsigned int MIN_SPEED_TIMER_PERIOD = 65535;
const unsigned int MAX_SPEED = 255;
const unsigned int MIN_SPEED = 0;


long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

Motor::Motor(const char* name, const int stepPin, const int directionPin, const bool reverseDirection, TimerIf& timer)
: m_logger(name), m_stepperMotor(name, stepPin, directionPin, reverseDirection), m_timer(timer)
{
}

Motor::~Motor() {
	m_timer.disableInterrupt();
}

void Motor::setup() {
	m_stepperMotor.setup();

	m_timer.initialize();
	m_timer.setISR(this);
	m_timer.enableInterrupt();

	m_logger.log("setup()");
}

void Motor::execute() {
	m_stepperMotor.step();
}

void Motor::setDirection(MotorDirection dir) {
	m_stepperMotor.setDirection(dir);
	m_logger.log("setDirection()");
}

void Motor::setSpeed(unsigned int speed) {
	if (speed > MAX_SPEED) {
		speed = MAX_SPEED;
	}
	unsigned int timerPeriod = map(speed, MIN_SPEED, MAX_SPEED, MIN_SPEED_TIMER_PERIOD, MAX_SPEED_TIMER_PERIOD);
	m_timer.setTimerPeriod(timerPeriod);
	m_logger.log("setSpeed()");
}
