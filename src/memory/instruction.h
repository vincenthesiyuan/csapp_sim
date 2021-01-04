#include<stdint.h>
#include<stdlib.h>

#define NUM_INSTRTYPE 30

typedef enum OP
{
    mov_reg_reg,
    PUSH,
    CALL,
    add_reg_reg

} op_t;

typedef enum OD_TYPE
{
    IMM, REG,
    MM_IMM, MM_REG, MM_IMM_REG, MM_REG1_REG2,
    MM_IMM_REG1_REG2, MM_REG1_S, MM_IMM_REG2_S, 
    MM_REG1_REG2_S, MM_IMM_REG1_REG2_S

} od_type_t;

typedef struct OD
{
    // operand
    od_type_t type;

    int64_t imm;
    int64_t scal;
    uint64_t *reg1;
    uint64_t *reg2;

} od_t;

typedef struct INSTRUCT_STRUCT
{
    // 指令集
};  


// **IMPORTANCE**
// typedef void (*handler_t)(uint64_t, uint64_t);


