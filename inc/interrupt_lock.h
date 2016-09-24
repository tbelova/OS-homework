#ifndef __LOCK__
#define __LOCK__

#include <ioport.h>

#define MASTER_COMMAND_PORT 0x20 
#define MASTER_DATA_PORT    0x21
#define SLAVE_COMMAND_PORT  0xA0
#define SLAVE_DATA_PORT     0xA1

void lock(int b);
void unlock(int b);
void lock_all();
void unlock_all();

#endif



