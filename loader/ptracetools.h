/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * vim: set ts=8 sts=2 et sw=2 tw=80:
 */
#ifndef __ptracetools_h_
#define __ptracetools_h_

#include <sys/types.h>
#include <sys/user.h>

void mk_funcall_args(user_regs_struct& regs,
                     unsigned long long arg1=0,
                     unsigned long long arg2=0,
                     unsigned long long arg3=0,
                     unsigned long long arg4=0,
                     unsigned long long arg5=0,
                     unsigned long long arg6=0);

long inject_text(pid_t, void*, void*, unsigned int);
long inject_data(pid_t, void*, void*, unsigned int);
long read_text(pid_t, void*, void*, unsigned int);
long ptrace_attach(pid_t);
long ptrace_waitstop(pid_t);
long ptrace_waittrap(pid_t pid);
long ptrace_stop(pid_t);
long ptrace_cont(pid_t);
long ptrace_stepi(pid_t);
long ptrace_getregs(pid_t, user_regs_struct&);
long ptrace_setregs(pid_t, const user_regs_struct&);
long inject_run_syscall(pid_t pid, int nr,
                        unsigned long long arg1=0,
                        unsigned long long arg2=0,
                        unsigned long long arg3=0,
                        unsigned long long arg4=0,
                        unsigned long long arg5=0,
                        unsigned long long arg6=0,
                        user_regs_struct* saved_regs = nullptr);
void* inject_mmap(pid_t pid, void* addr, size_t length,
                  int prot, int flags, int fd, off_t offset,
                  user_regs_struct* saved_regs = nullptr);
long inject_run_funcall(pid_t pid,
                        void* codesrc,
                        int codesrclen,
                        void* entry,
                        unsigned long long arg1 = 0,
                        unsigned long long arg2 = 0,
                        unsigned long long arg3 = 0,
                        unsigned long long arg4 = 0,
                        unsigned long long arg5 = 0,
                        unsigned long long arg6 = 0,
                        user_regs_struct* saved_regs = nullptr);
long inject_run_funcall_nosave(pid_t pid,
                               void* codesrc,
                               int codesrclen,
                               void* entry,
                               unsigned long long arg1 = 0,
                               unsigned long long arg2 = 0,
                               unsigned long long arg3 = 0,
                               unsigned long long arg4 = 0,
                               unsigned long long arg5 = 0,
                               unsigned long long arg6 = 0,
                               user_regs_struct* saved_regs = nullptr);


#endif /* __ptracetools_h_ */
