#ifndef __PRINT__

#define __PRINT__

#include <stringToIOPort.h>
#include <stdarg.h>
#include <string.h>

int vprintf(const char* format, va_list args);
int printf(const char* format, ...);
int vsnprintf(char* t, int m, const char* format, va_list args);
int snprintf(char* t, int m, const char* format, ...);

#endif

