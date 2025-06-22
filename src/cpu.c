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

// ! There will probably be an issue with this function
// ! When using the ptr, read_byte only returns a byte, but some registers may be 2 bytes...
void decode_operands(CPU* cpu, Mem* mem, Instruction ins, Operands* operands) {
    switch(ins.mode) {
        case AM_IMP:
            return;
        case AM_R:
            operands->reg1 = get_register(cpu, ins.reg_1);
            return;
        case AM_R_R:
            operands->reg1 = get_register(cpu, ins.reg_1);
            operands->reg2 = get_register(cpu, ins.reg_2);
            return;
        case AM_R_D8:
            operands->reg1 = get_register(cpu, ins.reg_1);
            operands->byte1 = read_byte(mem, cpu->PC++);
            return;
        case AM_R_D16:
            operands->reg1 = get_register(cpu, ins.reg_1);
            operands->byte1 = read_byte(mem, cpu->PC++);
            operands->byte2 = read_byte(mem, cpu->PC++);
            operands->word = (operands->byte2 << 8) | operands->byte1; 
            return;
        // essentially reg1 = *ptr, where ptr = reg2
        case AM_R_MR:
            operands->reg1 = get_register(cpu, ins.reg_1);
            operands->ptr = get_register(cpu, ins.reg_2);
            return;
        case AM_MR_R:
            operands->ptr = get_register(cpu, ins.reg_1);
            operands->reg2 = get_register(cpu, ins.reg_2);
            return;
        case AM_R_HLI:
            operands->reg1 = get_register(cpu, ins.reg_1);
            operands->ptr = get_register(cpu, ins.reg_2);
            cpu->hl++;
            return;
        case AM_R_HLD:
            operands->reg1 = get_register(cpu, ins.reg_1);
            operands->ptr = get_register(cpu, ins.reg_2);
            cpu->hl--;
            return;
        case AM_HLI_R:
            operands->ptr = get_register(cpu, ins.reg_1);
            operands->reg2 = get_register(cpu, ins.reg_2);
            cpu->hl++;
            return;
        case AM_HLD_R:
            operands->ptr = get_register(cpu, ins.reg_1);
            operands->reg2 = get_register(cpu, ins.reg_2);
            cpu->hl--;
            return;
        case AM_R_A8:
            operands->reg1 = get_register(cpu, ins.reg_1);
            operands->byte1 = read_byte(mem, cpu->PC++);
            return;
        // review 0xE0 in cpu instructions if needed.
        case AM_A8_R:
            operands->ptr = 0xFF00 | read_byte(mem, cpu->PC++);
            operands->reg2 = get_register(cpu, ins.reg_2);
            return;
        // review 0xF8 in cpu instructions if needed.
        case AM_HL_SPR:
            operands->reg1 = get_register(cpu, ins.reg_1);
            operands->reg2 = get_register(cpu, ins.reg_2);
            operands->offset = (r8)read_byte(mem, cpu->PC++); // r8 means signed
            return;
        case AM_D8:
            operands->byte1 = read_byte(mem, cpu->PC++);
            return;
        case AM_D16_R:
        case AM_A16_R:
            operands->byte1 = read_byte(mem, cpu->PC++);
            operands->byte2 = read_byte(mem, cpu->PC++);
            operands->word = (operands->byte2 << 8) | operands->byte1;
            operands->reg2 = get_register(cpu, ins.reg_2);
            return;
        case AM_MR_D8:
            operands->ptr = get_register(cpu, ins.reg_1);
            operands->byte1 = read_byte(mem, cpu->PC++);
            return;
        case AM_MR:
            operands->ptr = get_register(cpu, ins.reg_1);
            return;
        case AM_R_A16:
            operands->reg1 = get_register(cpu, ins.reg_1);
            operands->byte1 = read_byte(mem, cpu->PC++);
            operands->byte2 = read_byte(mem, cpu->PC++);
            operands->word = (operands->byte2 << 8) | operands->byte1;
            return;
        default:
            printf("Unknown Addressing mode!");
            return;
    }
}

/* Logic: I'll retrieve the needed operands for 'ins' using decode_operands. It only retrieves data, doesn't necessarily
          do anything with it. It sets up everything so all I'll have to do is use what I retrieved and execute according
          to the instruction e.g. AM_MR_D8 gets the ptr to the register and the d8 byte only, doesn't perform the *(ptr) = d8.
          My plan is to create another function that will look at ins_type and proceed to narrow down the ins to simplify 
          execution, so I dont have to write 256 instruction functions (hopefully). */
void execute_ins(CPU* cpu, Mem* mem, Instruction ins) {
    Operands operands = {0};
    decode_operands(cpu, mem, ins, &operands);

    // * Review decode_operands and logic explaination before implementing next function
    // use vars to execute instructions: maybe sort by ins_type w switch too?
    // ^ possibly another function?
}

bool cpu_step(CPU* cpu, Mem* mem) {
    u8 opcode = read_byte(mem, cpu->PC++);
    Instruction ins = instructions[opcode];
    return false;
}

