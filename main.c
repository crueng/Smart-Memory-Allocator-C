#include <stdio.h>
#include "MemoryAllocator.h"
int main(void)
{
    int* number = sMalloc(sizeof(int), false);
    *number = 42;
    printf("%d\n", *number);
    *number += 1;
    printf("%d\n", *number);
    sFree(number);
    number = NULL;
}