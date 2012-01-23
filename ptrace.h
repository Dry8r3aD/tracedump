/*
 * Copyright (C) 2011 IITiS PAN Gliwice <www.iitis.pl>
 * Author: Paweł Foremski <pjf@iitis.pl>
 * Licensed under GNU GPL v. 3
 */

#ifndef _PTRACE_H_
#define _PTRACE_H_

#include <stdlib.h>
#include <stdint.h>
#include <sys/ptrace.h>

/** Attach to process pid */
void ptrace_attach_pid(int pid);

/** Attach to a child which did PTRACE_TRACEME */
void ptrace_attach_child(int pid);

/** Mark this proccess as waiting for ptrace */
void ptrace_traceme(void);

/** Wait for traced child - wrapper around waitpid()
 * @return          pid of the child which has stopped
 * @param status    optional addr for process stop info */
int ptrace_wait(int pid, int *status);

/** Continue execution until INT3 */
void ptrace_cont(int pid, unsigned long sig, bool w8);

/** Continue until syscall */
void ptrace_cont_syscall(int pid, unsigned long sig, bool wait);

/** Detach from process pid */
void ptrace_detach(int pid);

/** Kill traced child */
void ptrace_kill(int pid);

/** Read data from location addr
 * @len length in bytes */
void ptrace_read(int pid, unsigned long addr, void *vptr, int len);

/** Write data to location addr
 * @len length in bytes */
void ptrace_write(int pid, unsigned long addr, void *vptr, int len);

/** Get process registers */
void ptrace_getregs(int pid, struct user_regs_struct *regs);

/** Set process registers */
void ptrace_setregs(int pid, struct user_regs_struct *regs);

#endif
