#include<stdlib.h>
#include<stdint.h>

#include "memory/dram.h"

uint64_t va2pa(uint64_t vaddr)
{
    return vaddr % MM_LEN;
}


