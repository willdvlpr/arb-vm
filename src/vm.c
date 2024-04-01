#include "vm.h"
#include <stdio.h>
#include <stdbool.h>

// will be defined elsewhere...
const int program[] = {
	PSH, 5,
	PSH, 6,
	ADD,
	POP,
	HLT};

int ip = 0;

int registers[NUM_OF_REGISTERS];

bool running = true;

void initRegisters()
{
	registers[SP] = VM_MAX_MEMORY - STACK_SIZE;
}

int fetch()
{
	return program[ip];
}

void eval(int instruction)
{
	switch (instruction)
	{
	case HLT:
	{
		running = false;
		break;
	}
	case PSH:
	{
		--registers[SP];
		memory[registers[SP]] = program[++ip];
		printf("stack: %d\n", memory[registers[SP]]);
		break;
	}
	case POP:
	{
		int val_popped = memory[registers[SP]++];
		printf("popped %d\n", val_popped);
		break;
	}
	case ADD:
	{
		int a = memory[registers[SP]++];
		int b = memory[registers[SP]++];
		int result = b + a;

		registers[SP]--;
		memory[registers[SP]] = result;
		break;
	}
	}
}

int main()
{
	initRegisters();
	printf("SP: %d\n", registers[SP]);
	while (running)
	{
		eval(fetch());
		ip++;
	}
	return 0;
}
