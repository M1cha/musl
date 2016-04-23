#define _GNU_SOURCE
#include <unistd.h>
#include <signal.h>
#include "syscall.h"
#include "libc.h"

pid_t __vfork(void)
{
	/* vfork syscall cannot be made from C code */
#ifdef SYS_vfork
	return syscall(SYS_vfork);
#else
	return syscall(SYS_clone, CLONE_VFORK|CLONE_VM|SIGCHLD, 0);
#endif
}

weak_alias(__vfork, vfork);
