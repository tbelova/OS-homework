#include <malloc.h>

slab_t* list_of_slabs[10];

typedef struct allocator_id alloc_id;
struct allocator_id {
	uint8_t type; // 0 -- buddy, 1 -- slab

	slab_t* slab_ptr;
	uint8_t slab_ord;

}__attribute__((packed));


void* malloc(uint64_t size) {
	if (size > PAGE_SIZE / 8) {
		alloc_id* res = (alloc_id*)buddy_alloc(size + sizeof(alloc_id));

		if (res == 0) return 0;

		res->type = 0;
		res++;
		return (void*)res;		
	}
	int k = 0;
	while ((1ull << k) < size) k++;
	if (!list_of_slabs[k]) {
		list_of_slabs[k] = create_slab((1ull << k) + sizeof(alloc_id), PAGE_SIZE / ((1ull << k) + sizeof(alloc_id)));
	}
	alloc_id* res = (alloc_id*)slab_alloc(list_of_slabs[k]);

	if (res == 0) return 0;

	res->type = 1;
	res->slab_ptr = list_of_slabs[k];
	res->slab_ord = k;
	res++;
	if (list_of_slabs[k] -> free_space == 0) {
		slab_t* old_head = list_of_slabs[k];	
		list_of_slabs[k] = old_head -> next;
		old_head -> next = NULL;
		list_of_slabs[k]->prev = NULL;
	}
	return (void*)res;
}

void free(void* void_ptr) {
	alloc_id* ptr = (alloc_id*)void_ptr;
	ptr--;
	if (ptr->type == 0) {
		buddy_free(ptr + 1);
		return;
	}	
	slab_t* slab = ptr->slab_ptr;

	uint8_t k = ptr->slab_ord;
	if (slab->free_space == 0) {
		slab->next = list_of_slabs[k];
		list_of_slabs[k] = slab;
	}
	
	ptr++;
	slab_free(slab, ptr);

	if (slab->free_space == PAGE_SIZE / ((1ull << k) + sizeof(alloc_id))) {
		if (!(slab->prev)) {
			list_of_slabs[k] = slab->next;
			list_of_slabs[k]->prev = NULL;
		} else { 
			slab->prev->next = slab->next;
			if (slab->next) {
				slab->next->prev = slab->prev;
			}
		}
		destroy_slab(slab);
	}	
}













