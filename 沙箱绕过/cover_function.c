#include <stdio.h>
#include <seccomp.h>
 
int seccomp_rule_add(scmp_filter_ctx ctx, uint32_t action, int syscall, unsigned int arg_cnt, ...) {
    printf("This is a fake seccomp_rule_add\n");
    return 0;
}
int seccomp_load(scmp_filter_ctx ctx) {
    return 0;
}
void seccomp_release(scmp_filter_ctx ctx) {}
int main()
{
    return 0;
}