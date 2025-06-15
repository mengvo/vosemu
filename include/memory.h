#pragma once

#include "common.h"

typedef struct {
    u8 cart[0x8000];    // 0000-7FFF
    u8 vram[0x2000];    // 8000-9FFF
    u8 sram[0x2000];    // A000-BFFF
    u8 wram[0x2000];    // C000-DFFF
    u8 oam[0x100];      // FE00-FE9F
    u8 io[0x100];       // FF00-FF7F
    u8 hram[0x80];      // FF80-FFFE
    u8 ie;              // FFFF
} Mem;

u8 read_byte(Mem* mem, u16 address);
void write_byte(Mem* mem, u16 address, u8 value);
bool cart_load(Mem* mem, char* filename);