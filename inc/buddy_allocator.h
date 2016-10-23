#ifndef __BUDDY_ALLOCATOR__

#define __BUDDY_ALLOCATOR__

#include <memmap.h>

void initialize_buddy_allocator();
uint64_t buddy_alloc(uint64_t);
void buddy_free(uint64_t);

#endif

