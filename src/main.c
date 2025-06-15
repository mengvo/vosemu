#include "memory.h"

/* TEMP, USED TO LEARN FOR NOW */
int main(int argc, char* argv[]) {
    u8 cart[0x8000];
    FILE* rom = fopen(argv[1], "rb");
    int bytes_read = fread(cart, 1, sizeof(cart), rom);
    printf("\n\n\nCartridge Header (0100-014F)\n\nNumber of bytes read: %d\n\n", bytes_read);
    printf("0100-0103 | Entry Point\n--------------------------------------------------------------------\n");
    for (u16 i = 0x0100; i <= 0x0103; i++) {
        printf("%04x: %02x\n", i, cart[i]);
    }
    printf("\n0104-0133 | Nintendo logo\n");
    printf("--------------------------------------------------------------------\n");
    int num_bytes = 0;
    for(u16 i = 0x0104; i <= 0x0133; i++) {
        printf("%02x ", cart[i]);
        num_bytes++;
        if(num_bytes == 16) {
            printf("\n");
            num_bytes = 0;
        }
    }
    printf("\n0134-0143 | Title\n");
    printf("--------------------------------------------------------------------\n");
    for(u16 i = 0x0134; i <= 0x0143; i++) {
        printf("%c", cart[i]);
    } printf("\n");
    int count = 1;
    for(u16 i = 0x0134; i <= 0x0143; i++) {
        printf("%d)%02x ", count++, cart[i]);
    }
    printf("\n*Note: Manufacturer code is 013F-0142 in newer carts [12-15]\n       CGB flag is 0143 [16]\n");
    printf("\n0144-0145 | New Licensee code\n");
    printf("--------------------------------------------------------------------\nCode in char: ");
    for(u16 i = 0x0144; i <= 0x0145; i++) { 
        printf("%c", cart[i] == 0 ? '0' : cart[i]);
    } printf("\nCode in hex: %01x%01x", cart[0x0144], cart[0x0145]);
    printf("\n\n0146 | SGB flag\n");
    printf("--------------------------------------------------------------------\n");
    printf("%02x\n", cart[0x0146]);
    printf("\n0147 | Cartridge type\n");
    printf("--------------------------------------------------------------------\n");
    printf("%02x\n", cart[0x0147]);
    printf("\n0148 | ROM size\n");
    printf("--------------------------------------------------------------------\n");
    printf("%02x\n", cart[0x0148]);
    printf("\n0149 | RAM size\n");
    printf("--------------------------------------------------------------------\n");
    printf("%02x\n", cart[0x0149]);
    printf("\n014A | Destination code\n");
    printf("--------------------------------------------------------------------\n");
    printf("%02x\n", cart[0x014A]);
    printf("\n014B | Old Licensee code\n");
    printf("--------------------------------------------------------------------\n");
    printf("%02x\n", cart[0x014B]);
    printf("\n014C | Mask ROM version number\n");
    printf("--------------------------------------------------------------------\n");
    printf("%02x\n", cart[0x014C]);
    printf("\n014D | Header checksum\n");
    printf("--------------------------------------------------------------------\n");
    printf("checksum in memory: %02x\n", cart[0x014D]);
    u8 checksum = 0;
    for (u16 i = 0x0134; i <= 0x014C; i++) {
        checksum = checksum - cart[i] - 1;
    } printf("checksum calculated: %02x\n", checksum);
    printf("\n014E-014F | Global checksum\n");
    printf("--------------------------------------------------------------------\n");
    printf("%02x, %02x\n", cart[0x014E], cart[0x014F]);
    printf("\n\n----------------------------END OF HEADER---------------------------\n");
    return 0;
}