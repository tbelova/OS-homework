#include <desc.h>
#include <ints.h>

#include <stringToIOPort.h>
#include <IDT.h>
#include <interruptController.h>
#include <interrupt_lock.h>
#include <PIT.h>
#include <memmap.h>
#include <buddy_allocator.h>
#include <slab_allocator.h>

#include <print.h>

static void qemu_gdb_hang(void)
{
#ifdef DEBUG
	static volatile int wait = 1;

	while (wait);
#endif
}

void init() {
	initialize_io_port();
	initialize_IDT();
	initialize_interrupt_controller();
	initialize_memory_map();
	initialize_buddy_allocator();
}

void test_buddy() {
	int n = 20;
	int * array = (int*)buddy_alloc(n);
	for (int i = 0; i < n; ++i) {
		array[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");

	buddy_free(array);

	printf("success!\n");

}

void test_slab() {
	slab_t* slab = create_slab(sizeof(int) * 10, 2);
	
	for (int i = 0; i < 5; ++i) {
		int* a = slab_alloc(slab);
		int* b = slab_alloc(slab);
		for (int k = 0; k < 10; ++k) {
			a[k] = k;
			b[k] = 0;
		}
		for (int k = 0; k < 10; ++k) {
			printf("(a[%d] = %lld, b[%d] = %lld) ", k, a[k], k, b[k]);
		}
		printf("\n\n");
		
		slab_free(slab, a);
		slab_free(slab, b);
	}

}

void main(void)
{
	qemu_gdb_hang();

	init();

	print_memory_map();	
	//test_buddy();
	//test_slab();

 
	

/*  __asm__ ("int $0");

	initialize_PIT();*/


	while (1);
}
