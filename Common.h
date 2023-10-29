#ifndef COMMONS_H_INCLUDED
#define COMMONS_H_INCLUDED

const int CMD = 0b11111;
const int IMM = 1 << 5;
const int REG = 1 << 6;
const int RAM = 1 << 7;

static_assert( !(IMM & REG), "IMM and REG overlap");
static_assert( !(IMM & CMD), "IMM and CMD overlap");
static_assert( !(REG & CMD), "REG and CMD overlap");
static_assert( !(RAM & CMD), "RAM and CMD overlap");
static_assert( !(RAM & REG), "RAM and REG overlap");
static_assert( !(RAM & IMM), "RAM and IMM overlap");

const char *REGS_NAME[] =
{
    "rax", "rbx", "rcx", "rdx", "rsi", "rdi", "rbp", "rsp",
    "r08", "r09", "r10", "r11", "r12", "r13", "r14", "r15"
};

const int REGISTERS_COUNT = sizeof(REGS_NAME) / sizeof(REGS_NAME[0]);

#define DEF_CMD(name, num, args, code)    \
    name = num,                           \

enum opcode_t
{
    #include "Commands.h"
};

#undef DEF_CMD

#endif // COMMONS_H_INCLUDED