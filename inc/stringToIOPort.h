#ifndef __STRINGTOIOPORT__

#define __STRINGTOIOPORT__

#include <ioport.h>

void initialize_io_port();
int string_to_io_port(const char* s);
void put(char c);

#endif
