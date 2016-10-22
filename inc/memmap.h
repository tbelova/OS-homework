#ifndef __MEMMAP__

#define __MEMMAP__

#include<print.h>

struct mem_entry {
	uint32_t size;
	uint64_t base_addr;
	uint64_t length;
	uint32_t type;
}__attribute__((packed));

struct my_mem_entry {
	uint64_t begin;
	uint64_t end;
	uint64_t length;
	uint32_t type;
};

void initialize_memory_map();
void print_memory_map();

#endif
