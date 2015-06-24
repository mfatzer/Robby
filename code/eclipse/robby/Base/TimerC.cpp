/*
 * TimerC.cpp
 *
 *  Created on: 21.06.2015
 *      Author: Martin
 */

#include "TimerC.h"
#include "Arduino.h"


const unsigned int MIN_SPEED_PERIOD = 65535;
TimerC LeoTimer3;


ISR(TIMER3_COMPA_vect) {
	LeoTimer3.runISR();
}

TimerC::TimerC()
: m_logger("Timer3"), m_timerExecutable(NULL)
{
}

TimerC::~TimerC() {
}

// Timer Prescaler auf 8 -> 2MHz
// TimerCounter wird automatisch geresettet
// TimerCounter wird auf 0 gesetzt
void TimerC::initialize() {
	TCCR3A = 0;
	TCCR3B = (1 << WGM32) | (1 << CS31);
	setTimerPeriod(MIN_SPEED_PERIOD);
	resetTimer();
	m_logger.log("initialize()");
}

void TimerC::setISR(TimerExecutable* timerExecutable) {
	m_timerExecutable = timerExecutable;
	m_logger.log("setISR()");
}

void TimerC::runISR() {
	if (m_timerExecutable != NULL) {
		m_timerExecutable->execute();
		m_logger.log("runISR()");
	}
	else {
		m_logger.log("runISR() NULL");
	}
}

void TimerC::enableInterrupt() {
	TIMSK3 |= (1 << OCIE1A);
	m_logger.log("enableInterrupt()");
}

void TimerC::disableInterrupt() {
	TIMSK3 &= ~(1 << OCIE1A);
	m_logger.log("disableInterrupt()");
}

void TimerC::setTimerPeriod(unsigned int period) {
	if (period > MIN_SPEED_PERIOD) {
		period = MIN_SPEED_PERIOD;
	}
	OCR3A = period;
	if (TCNT3 > period) {
		resetTimer();
	}
	m_logger.log("setTimerPeriod()");
}

void TimerC::resetTimer() {
	TCNT3 = 0;
	m_logger.log("resetTimer()");
}
