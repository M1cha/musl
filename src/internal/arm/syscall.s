.syntax unified
.global __syscall
.hidden __syscall
.weak __syscall
.type __syscall,%function
__syscall:
    mov r0, #-1
    bx lr
