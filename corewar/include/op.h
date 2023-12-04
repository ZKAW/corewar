/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** op
*/

#ifndef OP_H_
    #define OP_H_

    // #include "instructions.h"

    #define MEM_SIZE                (6 * 1024)
    #define IDX_MOD                 512
    #define MAX_ARGS_NUMBER         4

    #define COMMENT_CHAR            '#'
    #define LABEL_CHAR              ':'
    #define DIRECT_CHAR             '%'
    #define SEPARATOR_CHAR          ','

    #define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define NAME_CMD_STRING         ".name"
    #define COMMENT_CMD_STRING      ".comment"

    #define REG_NUMBER               16

typedef char   args_type_t;
typedef unsigned char byte_t;
typedef struct champion_s champion_t;
typedef struct corewar_s corewar_t;
typedef struct instruct_s instruct_t;

    #define INSTRUCT_PARAMS corewar_t *corewar, champion_t *champion, \
                        instruct_t instruct

typedef enum arg_type_e {
    T_NONE = 0,
    T_REG = 1,
    T_DIR = 2,
    T_IND = 4
} arg_type_t;

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
    int (*func)(INSTRUCT_PARAMS);
} op_t;

    #define IND_SIZE        2
    #define DIR_SIZE        4
    #define REG_SIZE        DIR_SIZE

extern  op_t    op_tab[];

    #define PROG_NAME_LENGTH        128
    #define COMMENT_LENGTH          2048

typedef struct header_s {
    int     magic;
    #define COREWAR_EXEC_MAGIC      0xea83f3
    char    prog_name[PROG_NAME_LENGTH + 1];
    int     prog_size;
    char    comment[COMMENT_LENGTH + 1];
} header_t;

    #define CYCLE_TO_DIE    1536
    #define CYCLE_DELTA     5
    #define NBR_LIVE        40

typedef enum op_types {
    OP_TYPE_LIVE = 0,
    OP_TYPE_LD,
    OP_TYPE_ST,
    OP_TYPE_ADD,
    OP_TYPE_SUB,
    OP_TYPE_AND,
    OP_TYPE_OR,
    OP_TYPE_XOR,
    OP_TYPE_ZJMP,
    OP_TYPE_LDI,
    OP_TYPE_STI,
    OP_TYPE_FORK,
    OP_TYPE_LLD,
    OP_TYPE_LLDI,
    OP_TYPE_LFORK,
    OP_TYPE_AFF,
    OP_TYPE_NULL,
    OP_NB
} op_types_t;

#endif /* !OP_H_ */
