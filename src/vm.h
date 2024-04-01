#ifndef VM_H
#define VM_H

#include <stdint.h>

#define VM_MAX_MEMORY (1 << 16)
#define STACK_SIZE 1024              /* 1kb */
unsigned char memory[VM_MAX_MEMORY]; /* 65536 locations (64kb) */

typedef enum
{
    A,
    B,
    C,
    D,
    E,
    F,
    PC,
    SP,
    NUM_OF_REGISTERS
} Registers;

// defines the possible instructions for the VM
typedef enum
{
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

#endif
