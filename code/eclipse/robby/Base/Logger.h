/*
 * Logger.h
 *
 *  Created on: 21.06.2015
 *      Author: Martin
 */

#ifndef LOGGER_H_
#define LOGGER_H_

class Logger {
public:
	Logger(const char* contextName);
	virtual ~Logger();

	virtual void log(char* info) const;

private:
	const char* m_contextName;
};

#endif /* LOGGER_H_ */
