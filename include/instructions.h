#pragma once

#include "common.h"
#include "cpu.h"

// Instruction decoding ideas and enums inspired by:
// "Low Level Devel" (Youtube)
// https://www.youtube.com/watch?v=17cdj-HYpb0&t=1179s

/** KEY **
 * R   - register
 * MR  - memory location of register
 * D8  - immediate 8 bit data
 * D16 - immediate 16 bit data
 * A8  - 8 bit unsigned data
 * A16 - 16 bit address
 */
typedef enum {
    AM_IMP,
    AM_R_D16,
    AM_R_R,
    AM_MR_R,
    AM_R,
    AM_R_D8,
    AM_R_MR,
    AM_R_HLI,
    AM_R_HLD,
    AM_HLI_R,
    AM_HLD_R,
    AM_R_A8,
    AM_A8_R,
    AM_HL_SPR,
    AM_D16,
    AM_D8,
    AM_D16_R,
    AM_MR_D8,
    AM_MR,
    AM_A16_R,
    AM_R_A16
} addr_mode;

typedef enum {
    NONE,
    A,
    F,
    B,
    C,
    D,
    E,
    H,
    L,
    AF,
    BC,
    DE,
    HL,
    SP,
    PC
} reg_type;

typedef enum {
    INS_NONE,
    INS_NOP,
    INS_LD,
    INS_INC,
    INS_DEC,
    INS_RLCA,
    INS_ADD,
    INS_RRCA,
    INS_STOP,
    INS_RLA,
    INS_JR,
    INS_RRA,
    INS_DAA,
    INS_CPL,
    INS_SCF,
    INS_CCF,
    INS_HALT,
    INS_ADC,
    INS_SUB,
    INS_SBC,
    INS_AND,
    INS_XOR,
    INS_OR,
    INS_CP,
    INS_POP,
    INS_JP,
    INS_PUSH,
    INS_RET,
    INS_CB,
    INS_CALL,
    INS_RETI,
    INS_LDH,
    INS_JPHL,
    INS_DI,
    INS_EI,
    INS_RST,
    INS_ERR,
    //CB instructions...
    INS_RLC, 
    INS_RRC,
    INS_RL, 
    INS_RR,
    INS_SLA, 
    INS_SRA,
    INS_SWAP, 
    INS_SRL,
    INS_BIT, 
    INS_RES, 
    INS_SET
} ins_type;

typedef enum {
    CT_NONE, CT_NZ, CT_Z, CT_NC, CT_C
} cond_type;

typedef struct {
    ins_type type;
    addr_mode mode;
    reg_type reg_1;
    reg_type reg_2;
    cond_type cond;
    u8 param;
} Instruction;

extern Instruction instructions[256];

u16 get_register(CPU*, reg_type);