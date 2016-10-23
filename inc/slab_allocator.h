#ifndef __SLAB_ALLOCATOR__

#define __SLAB_ALLOCATOR__

#include <buddy_allocator.h>

typedef struct slab_allocator slab_t;
typedef struct slab_node slab_node_t;

struct slab_allocator {
	uint64_t* memory;
	uint64_t* head;
};

slab_t* create_slab(uint64_t block_size, uint64_t max_cnt);
void* slab_alloc(slab_t* slab);
void slab_free(slab_t* slab, void* void_ptr);
void destroy_slab(slab_t* slab);

#endif
