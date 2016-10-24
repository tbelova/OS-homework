#ifndef __MALLOC__

#define __MALLOC__

#include <buddy_allocator.h>
#include <slab_allocator.h>

void* malloc(uint64_t size);
void free(void* void_ptr);

#endif
