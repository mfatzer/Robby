/*
 * TimerA.h
 *
 *  Created on: 21.06.2015
 *      Author: Martin
 */

#ifndef TIMERA_H_
#define TIMERA_H_

#include "Logger.h"
#include "TimerIf.h"

class TimerA : public TimerIf {
public:
	TimerA();
	virtual ~TimerA();

	virtual void initialize();
	virtual void setISR(TimerExecutable* timerExecutable);
	virtual void runISR();

	virtual void enableInterrupt();
	virtual void disableInterrupt();

	virtual void setTimerPeriod(unsigned int period);
	virtual void resetTimer();

private:
	const Logger m_logger;
	TimerExecutable* m_timerExecutable;
};

// Instanz erzeugen
extern TimerA LeoTimer1;

#endif /* TIMERA_H_ */
