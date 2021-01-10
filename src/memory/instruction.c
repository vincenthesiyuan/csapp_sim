#include<stdlib.h>

#include "cpu/register.h"
#include "memory/instruction.h"


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

}

void mov_reg_reg_handler(uint64_t src, uint64_t dst)
{
    
}



void add_reg_reg_handler(uint64_t src, uint64_t dst)
{
    
}