#include<stdlib.h>

#include "cpu/register.h"
#include "memory/instruction.h"
#include "cpu/mmu.h"
#include "memory/dram.h"

static uint64_t decode_operand(od_t *od)
{
    if(od->type == IMM)
    {
        return od->imm;
    }
    else if(od->type == REG)
    {
        return *((uint64_t *)od->reg1);
    }
    else if(od->type == EMPTY)
    {
        return 0;
    }
    else
    {
        uint64_t vaddr = 0;

        if(od->type == MM_IMM)
        {
            vaddr = *(uint64_t *)&od->imm;
        }
        else if(od->type == MM_REG)
        {
            vaddr = *((uint64_t *)od->reg1);
        }
        else if(od->type == MM_IMM_REG)
        {
            vaddr = od->imm + *((uint64_t *)od->reg1);
        }
        else if(od->type == MM_REG1_REG2)
        {
            vaddr = *((uint64_t *)od->reg1) + *((uint64_t *)od->reg2);
        }
        else if(od->type == MM_IMM_REG1_REG2)
        {
            vaddr = od->imm + *((uint64_t *)od->reg1) + *((uint64_t *)od->reg2);
        }
        else if(od->type == MM_REG2_S)
        {
            vaddr = *((uint64_t *)od->reg2) * od->scal;
        }
        else if(od->type == MM_IMM_REG2_S)
        {
            vaddr = od->imm + *((uint64_t *)od->reg2) * od->scal;
        }
        else if(od->type == MM_REG1_REG2_S)
        {
            vaddr = *((uint64_t *)od->reg1) + *((uint64_t *)od->reg2) * od->scal;
        }
        else if(od->type == MM_IMM_REG1_REG2_S)
        {
            vaddr = od->imm + *((uint64_t *)od->reg1) + *((uint64_t *)od->reg2) * od->scal;
        }
        return vaddr;
    }
    return 0;
}

void instruction_cycle()
{
    inst_t *instr = (inst_t *)reg.rip;

    uint64_t src = decode_operand(&(instr->src));
    uint64_t dst = decode_operand(&(instr->dst));

    handler_t handler = handler_table[instr->op];

    handler(src, dst);

}

void init_handler_table()
{
    handler_table[0] = &mov_reg_reg_handler;
    handler_table[5] = &call_handler;
    handler_table[6] = &return_handler;
    handler_table[7] = &add_reg_reg_handler;
}


void mov_reg_reg_handler(uint64_t src, uint64_t dst)
{
    *(uint64_t *)dst = *(uint64_t *)src;
    reg.rip = reg.rip + sizeof(inst_t);
}

void add_reg_reg_handler(uint64_t src, uint64_t dst)
{
    *(uint64_t *)dst = *(uint64_t *)src + *(uint64_t *)dst;
    reg.rip = reg.rip + sizeof(inst_t);
}

void call_handler(uint64_t src, uint64_t dst)
{
}

void return_handler(uint64_t src, uint64_t dst)
{
    uint64_t ret_addr = read64bits_dram(va2pa(reg.rsp));
    reg.rsp += 8;
    reg.rip = ret_addr;
}