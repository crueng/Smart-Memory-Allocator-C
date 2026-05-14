#pragma once
#include <stdlib.h>
#include <stdbool.h>


void* sMalloc(uint32_t size, bool FULLCACHELINES); //Note: Make the bool a default argument
void sFree(void* ptr);