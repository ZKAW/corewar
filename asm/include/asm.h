/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_

    #define SWAP_UINT32(x) ((x >> 24) & 0xff) | ((x << 8) & 0xff0000) \
| ((x >> 8) & 0xff00) | ((x << 24) & 0xff000000)
    #define SWAP_UINT16(x) ((x >> 8) & 0xff) | ((x << 8) & 0xff00)

    #include "lib.h"
    #include "struct.h"
    #include "op.h"
    #include "utils.h"
    #include "file.h"

    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <string.h>
    #include <stdbool.h>

void init_struct(asm_t *assembly);

void writer_append(writer_t* writer, int value, int size);
int writer_get_size(writer_t* writer);

char* parse_header(char *line);
int parse_name(char* line, char* trimmed_line, asm_t* assembly);
int parse_comment(char* line, char* trimmed_line, asm_t* assembly);

instruction_t* reverse_instructions(instruction_t* instructions);
function_t* reverse_functions(function_t* functions);
function_t* new_function(function_t* next);

void fill_body(FILE* fd, asm_t* assembly);
void write_bytecode(writer_t* writer, instruction_t *instruction);
label_t *add_label(char *name, asm_t* assembly);
void write_labels(writer_t* writer, asm_t* assembly);
int get_instruction(char *param);
int error_handling(instruction_t *ins);
int is_label(char *line);

#endif /* !ASM_H_ */
