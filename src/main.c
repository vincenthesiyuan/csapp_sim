#include<stdio.h>
#include<stdint.h>

#include "cpu/register.h"
#include "cpu/mmu.h"
#include "memory/instruction.h"
#include "disk/code.c"
#include "memory/dram.h"

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

    mm[va2pa(0x7fffffffdae4)] = 0x00005555;
    mm[va2pa(0x7fffffffdae0)] = 0x55554630;   // rbp
    mm[va2pa(0x7fffffffdad8)] = 0x00000000;
    mm[va2pa(0x7fffffffdad0)] = 0xabcd0000;
    mm[va2pa(0x7fffffffdac8)] = 0x00001234;
    mm[va2pa(0x7fffffffdac4)] = 0x00005555;
    mm[va2pa(0x7fffffffdac0)] = 0x55554630;   // rsp


    // run inst
    for(int i = 0; i<15; i++)
    {
        instruction_cycle();
    }


    // register verify
    // 验证程序运行完后的register上的值和memory值是否与gdb上的值一致
    int match = 1;

    match = match && (reg.rax == 0xabcd1234);
    match = match && (reg.rbx == 0x0);
    match = match && (reg.rcx == 0x555555554630);
    match = match && (reg.rdx == 0x1234);
    match = match && (reg.rsi == 0xabcd0000);
    match = match && (reg.rdi == 0x1234);
    match = match && (reg.rbp == 0x7fffffffdae0);
    match = match && (reg.rsp == 0x7fffffffdac0);

    if(match == 1)
    {
        printf("register match! \n");
    }
    else
    {
        printf("register not match! \n");
    }
    
    // memory verify
    match = 1;

    match = match && (mm[va2pa(0x7fffffffdae4)] == 0x00005555);
    match = match && (mm[va2pa(0x7fffffffdae0)] == 0x55554630);   // rbp
    match = match && (mm[va2pa(0x7fffffffdad8)] == 0xabcd1234);
    match = match && (mm[va2pa(0x7fffffffdad0)] == 0xabcd0000);
    match = match && (mm[va2pa(0x7fffffffdac8)] == 0x00001234);
    match = match && (mm[va2pa(0x7fffffffdac4)] == 0x00005555);
    match = match && (mm[va2pa(0x7fffffffdac0)] == 0x55554630);   // rsp

    if(match == 1)
    {
        printf("memory match! \n");
    }
    else
    {
        printf("memory not match! \n");
    }

    return 0;
}