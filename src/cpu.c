#include "cpu.h"
#include "instructions.h"

void cpu_init(CPU* cpu) {
    cpu->a = 0x01;
    cpu->f = 0xB0;
    cpu->b = 0x00;
    cpu->c = 0x13;
    cpu->d = 0x00;
    cpu->e = 0xD8;
    cpu->h = 0x01;
    cpu->l = 0x4D;
    cpu->SP = 0xFFFE;
    cpu->PC = 0x0100;
}

bool cpu_step(CPU* cpu, Mem* mem) {
    u8 opcode = read_byte(mem, cpu->PC++);
    Instruction ins = instructions[opcode];
    return false;
}

/* 

TODO : Finish create an execute instruction function

* may need to create a new struct containing addressing mode info, like what registers/immediates are we using, and other info of instruction
* use a switch to find out what the curr ins addressing mode is and store the needed info in that struct
* then write functions for each ins_type and use the struct to execute, set flags, etc.

void execute_ins(CPU*, Mem*, Instruction)
1.) figure out what instruction type e.g. load, alu, conditional, etc?
2.) fetch amt of bytes needed
3.) call its respective function?

*/
