/*
 * TimerC.h
 *
 *  Created on: 21.06.2015
 *      Author: Martin
 */

#ifndef TIMERC_H_
#define TIMERC_H_

#include "Logger.h"
#include "TimerIf.h"


class TimerC : public TimerIf {
public:
	TimerC();
	virtual ~TimerC();

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
extern TimerC LeoTimer3;

#endif /* TIMERC_H_ */
