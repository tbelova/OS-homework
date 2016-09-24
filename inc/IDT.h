#ifndef __IDT__
#define __IDT__

#include <desc.h>
#include <ints.h>
#include <memory.h>

struct IDT {
	uint16_t offset_15_0;
	uint16_t segment_selector;
	uint16_t smth;
	uint16_t offset_31_16;
	uint32_t offset_63_32;
	uint32_t a;
} __attribute__((packed));

#define IDT_SIZE 48

void initialize_descriptor(struct IDT* idt, uint64_t offset, uint16_t segment_selector, uint16_t p, uint16_t DPL, uint16_t TYPE, uint16_t IST);

void initialize_IDT();		

#endif












