#include <stdio.h>
#include "MemoryAllocator.h"

#define sMalloc(...) var_sMalloc((sMalloc_args){__VA_ARGS__})

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