/*
 * TimerIf.h
 *
 *  Created on: 21.06.2015
 *      Author: Martin
 */

#ifndef TIMERIF_H_
#define TIMERIF_H_

class TimerExecutable;

class TimerIf {
public:
	virtual ~TimerIf() {;};

	virtual void initialize()=0;
	virtual void setISR(TimerExecutable* timerExecutable)=0;
	virtual void runISR()=0;

	virtual void enableInterrupt()=0;
	virtual void disableInterrupt()=0;

	virtual void setTimerPeriod(unsigned int period)=0;
	virtual void resetTimer()=0;
};


class TimerExecutable {
public:
	virtual ~TimerExecutable() {;}
	virtual void execute() = 0;
};

#endif /* TIMERIF_H_ */
