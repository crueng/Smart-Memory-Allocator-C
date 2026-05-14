#pragma once
#include <stdlib.h>
#include <stdbool.h>


void* sMalloc(uint32_t size, bool FULLCACHELINES); //Note: Make the bool a default argument
void sFree(void* ptr);

typedef struct
{
    uint32_t size;
    bool FULLCACHELINES;
} f_args;

void* var_f(f_args in);