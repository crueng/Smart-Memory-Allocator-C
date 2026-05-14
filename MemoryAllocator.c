#include "MemoryAllocator.h"
#include <stdlib.h>
#include <sys/mman.h>

void* sMalloc(uint32_t size, bool FULLCACHELINES)
{
    int* plen;
    uint16_t len = size + sizeof(size); //Add sizeof(size) for holding length

    plen = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    *plen = len;

    return (void*)(&plen[1]);
}

void sFree(void* memoryRegion)
{
    int* plen = (int*)memoryRegion;
    plen--; //Reaching the top of the memory
    int len = *plen; //Reading the length of the memory
    munmap((void*)plen, len); //Free the memory
}

void* var_sMalloc(sMalloc_args in)
{
    uint32_t size = in.size ? in.size : 0;
    bool FULLCACHELINES = in.FULLCACHELINES;
    return sMalloc(size, FULLCACHELINES);
}