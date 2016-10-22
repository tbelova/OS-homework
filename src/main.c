#include <desc.h>
#include <ints.h>

#include <stringToIOPort.h>
#include <IDT.h>
#include <interruptController.h>
#include <interrupt_lock.h>
#include <PIT.h>
#include <memmap.h>


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
}

#include "print.h"

void main(void)
{
	qemu_gdb_hang();

	init();

	print_memory_map();

/*  __asm__ ("int $0");

	initialize_PIT();*/


	while (1);
}
