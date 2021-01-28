#include<stdio.h>
#include<stdint.h>

#include "cpu/register.h"
#include "memory/instruction.h"
#include "disk/code.c"

int main()
{
    init_handler_table();

    reg.rax = 0x1234;
    reg.rbx = 0x0;
    reg.rcx = 0x555555554630;
    reg.rdx = 0xabcd0000;
    reg.rsi = 0x7fffffffdbc8;
    reg.rdi = 0x1;
    reg.rbp = 0x7fffffffdae0;
    reg.rsp = 0x7fffffffdac0;

    reg.rip = (uint64_t)&program[11];

    

    // run inst
    int i = 0;
    for(; i<15; i++)
    {
        
    }


    // verify



    return 0;
}
