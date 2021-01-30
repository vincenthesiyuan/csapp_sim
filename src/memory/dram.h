#ifndef DRAM_GUARD
#define DRAM_GUARD

#include<stdint.h>

#define MM_LEN 1000

uint8_t mm[MM_LEN];

void write64bits_dram(uint64_t paddr, uint64_t data);

uint64_t read64bits_dram(uint64_t paddr);




#endif