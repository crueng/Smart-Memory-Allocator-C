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

    int* numberAllignt = sMalloc(sizeof(int), true);
    *numberAllignt = 42;
    printf("%d\n", *numberAllignt);
    *numberAllignt += 1;
    printf("%d\n", *numberAllignt);
    sFree(numberAllignt);
    numberAllignt = NULL;
}