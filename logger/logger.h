#ifndef LOGGER_H
#define LOGGER_H

void log_info(const char* info, const char* complement);

void log_error(const char* error, const char* complement);

void __normalize_terminal();

#endif