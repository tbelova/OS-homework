#include <desc.h>
#include <ints.h>

#include <stringToIOPort.h>
#include <IDT.h>
#include <interruptController.h>
#include <interrupt_lock.h>
#include <PIT.h>

static void qemu_gdb_hang(void)
{
#ifdef DEBUG
	static volatile int wait = 1;

	while (wait);
#endif
}

void main(void)
{
	qemu_gdb_hang();

	initialize_io_port();
	char* s = "Hello, world!\n";
	string_to_io_port(s);	

	initialize_IDT();
	__asm__ ("int $0");

	initialize_interrupt_controller();

	initialize_PIT();


	while (1);
}
