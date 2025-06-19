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

void execute_ins(CPU* cpu, Mem* mem, Instruction ins) {
    u16 reg1 = 0, reg2 = 0;
    u8 byte1 = 0, byte2 = 0;
    u16 word = 0;
    switch(ins.mode) {
        case AM_IMP:
            break;
        case AM_R:
            reg1 = get_register(cpu, ins.reg_1);
            break;
        case AM_R_R:
            reg1 = get_register(cpu, ins.reg_1);
            reg2 = get_register(cpu, ins.reg_2);
            break;
        case AM_R_D8:
            reg1 = get_register(cpu, ins.reg_1);
            byte1 = read_byte(mem, cpu->PC++);
            break;
        case AM_R_D16:
            reg1 = get_register(cpu, ins.reg_1);
            byte1 = read_byte(mem, cpu->PC++);
            byte2 = read_byte(mem, cpu->PC++); 
            break;
        case AM_R_MR:
            // TODO: CONTINUE HERE
            break;
    }
}

bool cpu_step(CPU* cpu, Mem* mem) {
    u8 opcode = read_byte(mem, cpu->PC++);
    Instruction ins = instructions[opcode];
    return false;
}

