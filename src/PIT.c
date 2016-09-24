#include <PIT.h>

#define COMMAND_PORT 0x43
#define DATA_PORT 0x40

void initialize_PIT() {
	uint16_t init = 0xffff; 
	
	out8(COMMAND_PORT, (1 << 4) | (1 << 5) | (2 << 1));
	out8(DATA_PORT, init % 256);
	out8(DATA_PORT, init / 256);

	unlock(0);
}








