#include <interruptController.h>
#include <ints.h>

void initialize_interrupt_controller() {
	uint8_t IC4 = 1;
	uint8_t SNGL = 0; 
	uint8_t LTIM = 0;

	uint8_t byte = (IC4 << 0) + (SNGL << 1) + (LTIM << 3) + (1 << 4);
	
	out8(MASTER_COMMAND_PORT, byte);
	out8(SLAVE_COMMAND_PORT, byte);

	out8(MASTER_DATA_PORT, 32);
	out8(SLAVE_DATA_PORT, 40);

	out8(MASTER_DATA_PORT, (1 << 2));
	out8(SLAVE_DATA_PORT, 2);

	out8(MASTER_DATA_PORT, (1 << 0));
	out8(SLAVE_DATA_PORT, (1 << 0));

	lock_all();
	enable_ints();
}

		















