#include <stringToIOPort.h>
#include <interruptController.h>
#include <print.h>

void interruptHandler(int n) {
	printf("interrupt id = %d\n", n);
	if (n >= 32 && n < 48) {
		out8(MASTER_COMMAND_PORT, (1 << 5));
		if (n >= 40) 
			out8(SLAVE_COMMAND_PORT, (1 << 5));
	} 
}

