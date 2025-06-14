#include "memory.h"

u8 read_byte(Mem* mem, u16 address) {
    if(address <= 0x7FFF) {
        return mem->cart[address];
    } else if(address >= 0xC000 && address <= 0xDFFF) {
        return mem->wram[address - 0xC000];
    } else if(address >= 0xFF80 && address <= 0xFFFE) {
        return mem->hram[address - 0xFF80];
    } else {
        return 1; // temp, so no warnings
    }
}

void write_byte(Mem* mem, u16 address, u8 value) {
    // TODO: write this function
}