#define _BSD_SOURCE // readlink
#include <dlfcn.h>
#include <stdlib.h> // exit
#include <string.h> // strstr, memset
#include <link.h>   // ElfW
#include <errno.h>  // EPERM
#include <unistd.h> // readlink
#include <seccomp.h>
#include <stdio.h>
int syscalls_whitelist[] = {SCMP_SYS(read), SCMP_SYS(write), 
                            SCMP_SYS(fstat), SCMP_SYS(mmap), 
                            SCMP_SYS(mprotect), SCMP_SYS(munmap), 
                            SCMP_SYS(brk), SCMP_SYS(access), 
                            SCMP_SYS(exit_group)};
typedef int (*main_t)(int, char **, char **);
 
#ifndef __unbounded
# define __unbounded
#endif
 
int __libc_start_main(main_t main, int argc, 
    char *__unbounded *__unbounded ubp_av,
    ElfW(auxv_t) *__unbounded auxvec,
    __typeof (main) init,
    void (*fini) (void),
    void (*rtld_fini) (void), void *__unbounded
    stack_end)
{
 
    int i;
    ssize_t len;
    void *libc;
    int whitelist_length = sizeof(syscalls_whitelist) / sizeof(int);
    scmp_filter_ctx ctx = NULL;
    int (*libc_start_main)(main_t main,
        int,
        char *__unbounded *__unbounded,
        ElfW(auxv_t) *,
        __typeof (main),
        void (*fini) (void),
        void (*rtld_fini) (void),
        void *__unbounded stack_end);
 
    // Get __libc_start_main entry point
    libc = dlopen("libc.so.6", RTLD_LOCAL  | RTLD_LAZY);
    if (!libc) {
        exit(1);
    }
 
    libc_start_main = dlsym(libc, "__libc_start_main");
    if (!libc_start_main) {
        exit(2);
    }
 
    ctx = seccomp_init(SCMP_ACT_KILL);
    if (!ctx) {
        exit(3);
    }
    for(i = 0; i < whitelist_length; i++) {
        if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, 
                             syscalls_whitelist[i], 0)) {
            exit(4);
        }
    }
    if (seccomp_load(ctx)) {
        exit(5);
    }
    seccomp_release(ctx);
    return ((*libc_start_main)(main, argc, ubp_av, auxvec,
                 init, fini, rtld_fini, stack_end));
}
