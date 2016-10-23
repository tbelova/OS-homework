#include <slab_allocator.h>

void slab_init(slab_t* slab, uint64_t* memory, uint64_t block_size, uint64_t max_cnt) {
	slab->memory = memory;
	slab->head = memory;
	for (uint64_t i = 0; i < max_cnt - 1; ++i) {
		(memory)[i] = (uint64_t)memory + block_size;
		memory += block_size;
	}
	memory = 0;
}

slab_t* create_slab(uint64_t block_size, uint64_t max_cnt) {
	if (block_size < 8) block_size = 8;
	uint64_t* memory = (uint64_t*)buddy_alloc(block_size * max_cnt + sizeof(slab_t));
	
	if (!memory) return 0;

	slab_t* slab = (slab_t*)((uint64_t)memory + block_size * max_cnt);
	slab_init(slab, memory, block_size, max_cnt);

	return slab;
}

void* slab_alloc(slab_t* slab) {
	if (slab->head == 0) return 0;

	uint64_t* res = slab->head;
	slab->head = (uint64_t*)*(slab->head);
	
	return (void*)res;
}

void slab_free(slab_t* slab, void* void_ptr) {
	uint64_t* ptr = (uint64_t*)void_ptr;

	*ptr = (uint64_t)slab->head;
	slab->head = ptr; 
}

void destroy_slab(slab_t* slab) {
	buddy_free(slab->memory);
}


