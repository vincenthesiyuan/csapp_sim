#include<stdint.h>


/*****************************/
/*         64位寄存器         */
/*****************************/


// 通用寄存器：rax, rbx, rcx, rdx
// 栈寄存器：rsp(栈顶指针寄存器), rbp(栈基址寄存器)
// 指令寄存器：rip
// 传参寄存器：rcx, rdx, r8, r9
// scratch寄存器：bx,r12, r13, r14, r15(scratch)，需要保护


// rax，rcx，rdx，r8，r9，r10，r11是“易挥发”的，不用特别保护(push备份），其余寄存器需要保护



typedef struct REG
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
    uint64_t rip; 

}reg_t;

reg_t reg;  // 寄存器 x86架构（IA32）
