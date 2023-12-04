/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instructions
*/

#ifndef INSTRUCTIONS_H_
    #define INSTRUCTIONS_H_

    #include <stdbool.h>
    #include "op.h"

typedef struct corewar_s corewar_t;
typedef struct champion_s champion_t;

typedef enum instruct_type_e {
    I_REG = 1,
    I_DIR,
    I_IDR
} instruct_type_t;

typedef enum val_type_e {
    VAL_NORMAL = 1,
    VAL_LONG
} val_type_t;

typedef struct arg_s {
    arg_type_t type;
    int val;
} arg_t;

typedef struct instruct_s {
    byte_t byte;
    arg_t args[4];
} instruct_t;

static const int ARG_TYPES[] = {
    [0b01] = T_REG,
    [0b10] = T_DIR,
    [0b11] = T_IND,
};

// Macros

    #define INSTRUCT_PARAMS corewar_t *corewar, champion_t *champion, \
                            instruct_t instruct
    #define VAL_PARAMS champion_t *champion, char *arena, \
                            byte_t byte, int value, val_type_t type

    #define GET_ARG_PARAM(n) n == OP_TYPE_LIVE ? 0b10 : 0b11
    #define PASS_ARGS(op) (op != OP_TYPE_LIVE && op != OP_TYPE_ZJMP && \
op != OP_TYPE_FORK && op != OP_TYPE_LFORK)
    #define GET_PARAM_BYTE(arena, champion, idx) \
        (PASS_ARGS(idx) ? arena[(champion->pc + 1) % MEM_SIZE] : 0)

// Utils

int get_param_value(char *arena, int pc, int size);
int get_param_type(char *arena, int pc, int size);
int read_arg(char *arena, int pc, int size);
void write_arg(char *arena, int offset, int value);
bool is_register(instruct_t instruct, int arg_nb);
int get_value(VAL_PARAMS);
int check_instruct_validity(char *arena, champion_t *champion, int idx);
int check_index_need(int index);
int count_instr_bytes(byte_t byte, int idx);
void freeze_champ_once(champion_t *champion);
void freeze_champ_by_cycles(champion_t *champion, int code, int idx);
int get_arg_len(int arg_type, int index);
void exec_instruction(corewar_t *corewar, champion_t *champion);
instruct_t init_instructs(champion_t *champion, char* arena, int idx);
int get_arg_type(byte_t byte, int arg);
int get_arg_from_byte(char args);

// Instructions

int instruct_live(INSTRUCT_PARAMS);
int instruct_ld(INSTRUCT_PARAMS);
int instruct_st(INSTRUCT_PARAMS);
int instruct_add(INSTRUCT_PARAMS);
int instruct_sub(INSTRUCT_PARAMS);
int instruct_and(INSTRUCT_PARAMS);
int instruct_or(INSTRUCT_PARAMS);
int instruct_xor(INSTRUCT_PARAMS);
int instruct_zjmp(INSTRUCT_PARAMS);
int instruct_ldi(INSTRUCT_PARAMS);
int instruct_sti(INSTRUCT_PARAMS);
int instruct_fork(INSTRUCT_PARAMS);
int instruct_lld(INSTRUCT_PARAMS);
int instruct_lldi(INSTRUCT_PARAMS);
int instruct_lfork(INSTRUCT_PARAMS);
int instruct_aff(INSTRUCT_PARAMS);

#endif /* !INSTRUCTIONS_H_ */
