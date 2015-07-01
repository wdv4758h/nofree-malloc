#include <stdio.h>

// linux, x86_64

#define SYS_BRK 12

void* call_brk(void* addr) {
    void* result;
    asm volatile ("syscall\n\t" : "=a" (result) : "0" (SYS_BRK) : "memory", "cc", "r11", "cx");
    return result;
}

void* sbrk(size_t inc) {
    static void* curbrk = 0;

    printf("my sbrk :P\n");

    if (curbrk == 0)
        curbrk = call_brk(0);

    curbrk = (void *) call_brk(curbrk + inc);

    return curbrk;
}

void* malloc (size_t size) {
    printf("my malloc :P\n");
    return sbrk(size);
}
