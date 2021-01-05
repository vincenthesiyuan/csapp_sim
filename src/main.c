#include<stdio.h>

#include "cpu/register.h"

int main()
{
    reg.rax = 0x1234abcd5678ffff;

    printf("eax: %08x\n", reg.eax);
    printf("ax: %04x\n", reg.ax);

    return 0;
}
