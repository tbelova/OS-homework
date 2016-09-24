#include <IDT.h>

struct IDT idt[IDT_SIZE];
extern uint64_t array[];

void initialize_descriptor(struct IDT* idt, uint64_t offset, uint16_t segment_selector, uint16_t p, uint16_t DPL, uint16_t TYPE, uint16_t IST) {
	(*idt).a = 0;

	(*idt).offset_63_32 = offset >> 32;
	(*idt).offset_31_16 = (offset & 0x00000000ffffffffull) >> 16;
	(*idt).offset_15_0 = offset & 0x000000000000ffffull; 
	
	(*idt).segment_selector = segment_selector;

	(*idt).smth = (p << 15)  + (DPL << 13) + (TYPE << 8) + IST;
}

void initialize_IDT() {
	disable_ints();

	struct desc_table_ptr IDT_ptr;
	IDT_ptr.size = sizeof(idt) - 1; 
	IDT_ptr.addr = (uint64_t)idt;
	write_idtr(&IDT_ptr);
	
	for (int i = 0; i < IDT_SIZE; i++) {
		uint64_t offset = array[i];
		uint16_t segment_selector = KERNEL_CS;
		uint16_t p = 1;
		uint16_t DPL = 0;
//		if (i >= 32) DPL = 3;
		uint16_t TYPE = 14;				
		uint16_t IST = 0;

		initialize_descriptor(idt + i, offset, segment_selector, p, DPL, TYPE, IST);
	}

	enable_ints();

}

		














