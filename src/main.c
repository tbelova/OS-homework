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

#include "print.h"

void main(void)
{
	qemu_gdb_hang();

	initialize_io_port();
	char* s = "Hello, world!\n";
	string_to_io_port(s);	

	initialize_IDT();
	__asm__ ("int $0");

	initialize_interrupt_controller();

	printf("%d:  %c, %s, %%, %i\nlalala %lld\n", 5, 'a', "abcde", -1, INT64_MIN);   //printf test
	
	char t[100];
	snprintf(t, 100, "%d:  %c, %s, %%, %i\nlalala %lld\n", 5, 'a', "abcde", -1, INT64_MIN);   //snprintf test
	printf("%s", t);
	

	initialize_PIT();


	while (1);
}
