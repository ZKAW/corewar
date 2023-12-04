/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** write.c
*/

#include "asm.h"

int get_arg_type(char* arg);

//no bytecode live, zjmp ,fork, lfork

void write_bytecode(writer_t* writer, instruction_t *instruction)
{
    char* no_bytecode[5] = {"live", "zjmp", "fork", "lfork", NULL};
    int coding_byte = 0, type = 0;
    for (int i = 0; no_bytecode[i] != NULL; i++)
        if (my_strcmp(instruction->name, no_bytecode[i]) == 0)
            return;
    for (int i = 0; instruction->params[i] != NULL; i++) {
        type = get_arg_type(instruction->params[i]);
        coding_byte = coding_byte | (type << (6 - (i * 2)));
    }
    writer_append(writer, coding_byte, 1);
}
