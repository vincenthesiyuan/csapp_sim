#include<stdlib.h>
#include<stdint.h>

#include "memory/memory.h"

uint64_t va2pa(uint64_t vaddr)
{
    return vaddr % PHYSICAL_MEMORY_SPACE;
}


