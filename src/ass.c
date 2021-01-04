#include<stdio.h>

#include "cpu.h"

int main()
{
    cpu_t cpu;
    cpu.rax = 0x1234abcd5678ffff;

    printf("eax: %08x\n", cpu.eax);
    printf("ax: %04x\n", cpu.ax);

    return 0;
}
