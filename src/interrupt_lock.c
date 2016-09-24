#include <interrupt_lock.h>

int MASTER_MASK = 0;
int SLAVE_MASK = 0;

void mask() {
	out8(MASTER_DATA_PORT, MASTER_MASK);
	out8(SLAVE_DATA_PORT, SLAVE_MASK);
}

void lock(int b) {
	if (b < 8) {
		MASTER_MASK |= (1 << b);
	} else {
		SLAVE_MASK |= (1 << (b - 8));
	}
	mask();
}

void unlock(int b) {
	if (b < 8) {
		MASTER_MASK &= 255 - (1 << b);
	} else {
		SLAVE_MASK &= 255 - (1 << (b - 8));
	}
	mask();
}

void lock_all() {
	MASTER_MASK = 251;
	SLAVE_MASK = 255;
	mask();
}

void unlock_all() {
	MASTER_MASK = 0;
	SLAVE_MASK = 0;
	mask();
}





