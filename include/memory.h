#pragma once

#include "common.h"

typedef struct {
    u8 cart[0x8000];
    u8 wram[0x2000];
    u8 hram[0x80];
    u8 ie;
} Mem;

u8 read_byte(Mem* mem, u16 address);
void write_byte(Mem* mem, u16 address, u8 value);