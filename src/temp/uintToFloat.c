#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>


float uint2float(uint32_t u)
{
    int n = 0;

    uint32_t s = u & 0x80000000;
    u = u & 0x7fffffff;  /* 去掉sign位 */

    /* 找到1.frac中1的位置 */
    for(int i = 0; i < 31; i++)
    {
        if ((u >> i) == 0x1)
        {
            n = i; 
            break;
        }
    }

    printf("n = %d\n", n);

    return 0;
}


int main()
{
    uint32_t a = 0x08000000;
    uint2float(a);
    return 0;
}
