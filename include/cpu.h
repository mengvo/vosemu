#pragma once

#include "common.h"
#include "memory.h"
#include "instructions.h"

typedef struct CPU {
    union {
        struct {
            u8 f;
            u8 a;
        };
        u16 af;
    };

    union {
        struct {
            u8 c;
            u8 b;
        };
        u16 bc;
    };

    union {
        struct {
            u8 e;
            u8 d;
        };
        u16 de;
    };

    union {
        struct {
            u8 l;
            u8 h;
        };
        u16 hl;
    };

    u16 SP;
    u16 PC;

} CPU;

typedef struct Operands {
    u16 ptr;
    u8 byte1;
    u8 byte2;
    u16 word;
    u16 reg1;
    u16 reg2;
    r8 offset;
} Operands;

void cpu_init(CPU* cpu);
void decode_operands(CPU* cpu, Mem* mem, Instruction ins, Operands* operands);
void execute_ins(CPU* cpu, Mem* mem, Instruction ins);
bool cpu_step(CPU* cpu, Mem* mem);