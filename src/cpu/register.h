#include<stdint.h>

typedef struct cpu
{
    union
    {
        struct
        {
           uint8_t al;
           uint8_t ah;
        };
        
        uint16_t ax;
        uint32_t eax;
        uint64_t rax;
    };
    
    
    uint64_t rbx;
    uint64_t rcx;
    uint64_t rdx;
    uint64_t rsi;
    uint64_t rdi;
    uint64_t rbp;
    uint64_t rsp;

}cpu_t;
