# include <stdio.h>
# include "CPU.h"

void initCPU(MyStruct* cpu);

int main()
{
    MyStruct* cpu;
    printf("%d\n", cpu->clock.m);
    return 0;
}
