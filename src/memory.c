#include "memory.h"

u8 read_byte(Mem* mem, u16 address) {
    if(address <= 0x7FFF) {
        return mem->cart[address];

    } else if(address >= 0x8000 && address <= 0x9FFF) { 
        return mem->vram[address - 0x8000];

    } else if(address >= 0xA000 && address <= 0xBFFF) { 
        return mem->sram[address - 0xA000];

    } else if(address >= 0xC000 && address <= 0xDFFF) {
        return mem->wram[address - 0xC000];

    } else if(address >= 0xFE00 && address <= 0xFE9F) { 
        return mem->oam[address - 0xFE00];

    } else if(address >= 0xFF00 && address <= 0xFF7F) { 
        return mem->io[address - 0xFF00];

    } else if(address >= 0xFF80 && address <= 0xFFFE) {
        return mem->hram[address - 0xFF80];
    }
    return 0;
}

void write_byte(Mem* mem, u16 address, u8 value) {
    (void)mem;      //! Suppresses warnings
    (void)address;  //! Suppresses warnings
    (void)value;    //! Suppresses warnings
    // TODO: write this function
}

bool cart_load(Mem* mem, char* filename) {
    FILE* rom = fopen(filename, "rb");
    if(!rom) {
        printf("Failed to open ROM file: %s\n", filename);
        return false;
    }

    fseek(rom, 0, SEEK_END);
    size_t file_size = ftell(rom);
    rewind(rom);

    if(file_size < 0x8000) {
        printf("ROM is too small!\n");
        fclose(rom);
        return false;
    }

    fread(mem->cart, 1, sizeof(mem->cart), rom);

    fclose(rom);
    return true;
}