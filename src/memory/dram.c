#include<stdint.h>
#include<stdlib.h>

#include "cpu/mmu.h"

#define SRAM_CACHE_SETTING 0


// Dynamic Random Access Memory


void write64bits_dram(uint64_t paddr, uint64_t data)
{
    if(SRAM_CACHE_SETTING == 1)
    {
        return;
    }
}

uint64_t read64bits_dram(uint64_t paddr)
{
    if(SRAM_CACHE_SETTING == 1)
    {
        return 0x0;
    }

    uint64_t val = 0x0;



    return 0;
}