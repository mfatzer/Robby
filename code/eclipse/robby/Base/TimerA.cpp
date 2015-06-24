/*
 * TimerA.cpp
 *
 *  Created on: 21.06.2015
 *      Author: Martin
 */

#include "TimerA.h"
#include "Arduino.h"


const unsigned int MIN_SPEED_PERIOD = 65535;
TimerA LeoTimer1;


ISR(TIMER1_COMPA_vect) {
	LeoTimer1.runISR();
}

TimerA::TimerA()
: m_logger("Timer1"), m_timerExecutable(NULL)
{
}

TimerA::~TimerA() {
}

// Timer Prescaler auf 8 -> 2MHz
// TimerCounter wird automatisch geresettet
// TimerCounter wird auf 0 gesetzt
void TimerA::initialize() {
	TCCR1A = 0;
	TCCR1B = (1 << WGM12) | (1 << CS11);

	setTimerPeriod(MIN_SPEED_PERIOD);
	resetTimer();
	m_logger.log("initialize()");
}

void TimerA::setISR(TimerExecutable* timerExecutable) {
	m_timerExecutable = timerExecutable;
	m_logger.log("setISR()");
}

void TimerA::runISR() {
	if (m_timerExecutable != NULL) {
		m_timerExecutable->execute();
		m_logger.log("runISR()");
	}
	else {
		m_logger.log("runISR() NULL");
	}
}

void TimerA::enableInterrupt() {
	TIMSK1 |= (1 << OCIE1A);
	m_logger.log("enableInterrupt()");
}

void TimerA::disableInterrupt() {
	TIMSK1 &= ~(1 << OCIE1A);
	m_logger.log("disableInterrupt()");
}

void TimerA::setTimerPeriod(unsigned int period) {
	if (period > MIN_SPEED_PERIOD) {
		period = MIN_SPEED_PERIOD;
	}
	OCR1A = period;
	if (TCNT1 > period) {
		resetTimer();
	}
	Serial.print(period);
	m_logger.log("setTimerPeriod()");
}

void TimerA::resetTimer() {
	TCNT1 = 0;
	m_logger.log("resetTimer()");
}
