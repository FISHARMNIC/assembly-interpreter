#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <inttypes.h>

#include "header.h"


int main()
{
    asm_memory_t memory = new_asm_memory(100);
    asm_instance_t instance = new_asm_instance(memory);
    
    // simple loop that writes sequence of numbers 0-9 to memory
    char* code[] = {
        "mov %al, 10",
        "dec %al",
        "mov [%al], %al",
        "cmp %al, 0",
        "jne 1"
    };

    // run the code
    asm_instance_run(&instance, code, 5);

    // display the memory
    for(int i = 0; i < 10; i++)
    {
        printf("[%i] = %i\n",i, instance.memory.buffer[i]);
    }
    
    return 0;
}