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
#include <malloc.h>

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

void test_buddy(int n) {
	int * array = (int*)buddy_alloc(sizeof(int) * n);
	if (array == 0) {
		printf("Not enough memory\n");
		return;
	}
	for (int i = 0; i < n; ++i) {
		array[i] = i;
	}
	//for (int i = 0; i < n; ++i) {
	//	printf("%d ", array[i]);
	//}
	//printf("\n");

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
			b[k] = -k;
		}
		for (int k = 0; k < 10; ++k) {
			printf("(a[%d] = %d, b[%d] = %d) ", k, a[k], k, b[k]);
		}
		printf("\n\n");
		
		slab_free(slab, a);
		slab_free(slab, b);
	}

	destroy_slab(slab);

	printf("success\n");

}

void test_malloc(int n) {
	int* a = malloc(sizeof(int) * n);
	if (a == 0) {
		printf("Not enough memory\n");
		return;
	}
	for (int i = 0; i < n; ++i) {
		a[i] = i;
	}
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
	}
	free(a);
	if (sum == (long long)n * (n - 1) / 2) {
		printf("success\n");
	} else {
		printf("fail\n");
	}
}

void main(void)
{
	qemu_gdb_hang();

	init();

	print_memory_map();	
//	test_buddy(5000);
//	test_slab();
	test_malloc(15);
	test_malloc(1000000);	

/*  __asm__ ("int $0");

	initialize_PIT();*/


	while (1);
}
