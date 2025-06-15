#pragma once

#include "common.h"
#include "memory.h"

typedef struct {
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
            u8 d;
            u8 e;
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

void cpu_init(CPU* cpu);
bool cpu_step(CPU* cpu, Mem* mem);