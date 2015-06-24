/*
 * Logger.cpp
 *
 *  Created on: 21.06.2015
 *      Author: Martin
 */

#include "Logger.h"
#include "Arduino.h"


Logger::Logger(const char* contextName)
: m_contextName(contextName)
{
}

Logger::~Logger() {
}

void Logger::log(char* info)const {
	Serial.print(m_contextName);
	Serial.print(":");
	Serial.println(info);
}

