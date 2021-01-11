#include<stdlib.h>

#include "cpu/register.h"
#include "memory/instruction.h"
#include "cpu/mmu.h"


// interpret the operand
static uint64_t decode_operand(od_t *od)
{
    if(od->type == IMM)
    {
        return *(uint64_t *)&od->imm;
    }
    else if(od->type == REG)
    {
        return od->reg1;
    }
    else if(od->type == EMPTY)
    {
        return 0;
    }
    else
    {
    
    }

}

void instruction_cycle()
{
    inst_t *instr = (inst_t *)reg.rip;

    uint64_t src = decode_operand(instr->src);
    uint64_t dst = decode_operand(instr->dst);




}

void init_handler_table()
{
    
}

void mov_reg_reg_handler(uint64_t src, uint64_t dst)
{
    *(uint64_t *)dst = *(uint64_t *)src;
    reg.rip = reg.rip + sizeof(inst_t);
}

void add_reg_reg_handler(uint64_t src, uint64_t dst)
{
    
}