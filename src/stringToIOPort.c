#include<stringToIOPort.h>

const unsigned short START = 0x3f8;

int bit(uint8_t value, int b) {
	return (value & (1 << b));
}

int8_t setBit(int b) {
	return (1 << b);
}

void initialize_io_port() {
	out8(START + 3, setBit(7));
	out8(START, 1);
	out8(START + 1, 0);

	out8(START + 3, setBit(0) | setBit(1));
}

void put(char c) {
	while (!bit(in8(START + 5), 5)); 
	out8(START, c);
}

int string_to_io_port(const char* s) {
	int res = 0;
	for (int i = 0; s[i] != 0; i++) {
		put(s[i]);
		res++;
	}	
	return res;
}

