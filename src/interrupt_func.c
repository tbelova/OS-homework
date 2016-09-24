#include <stringToIOPort.h>
#include <interruptController.h>

void interruptHandler(int n) {
	if (n == 32) {
		string_to_io_port("== 32\n");
	} else if (n == 0) {
		string_to_io_port("== 0\n");
	} else {
		string_to_io_port("???\n");
	}
	
	if (n >= 32 && n < 48) {
		out8(MASTER_COMMAND_PORT, (1 << 5));
		if (n >= 40) 
			out8(SLAVE_COMMAND_PORT, (1 << 5));
	} 

}

