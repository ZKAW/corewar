/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** output.c
*/

#include "asm.h"

to_write_t add_to_test(char* arg, instruction_t *instruction, asm_t *assembly);


void write_instructions(instruction_t* instruction,
                        writer_t *writer, asm_t* assembly)
{
    to_write_t val;
    while (instruction) {
        writer_append(writer, instruction->op.code, 1);
        write_bytecode(writer, instruction);
        for (int i = 0; instruction->params[i]; i++) {
            val = add_to_test(instruction->params[i], instruction, assembly);
            writer_append(writer, val.value, val.size);
        }
        instruction = instruction->next;
    }
}

writer_t *write_functions(int fd, asm_t* assembly)
{
    function_t *function = assembly->functions;
    writer_t* writer = assembly->writer;
    while (function) {
        function->index = writer->index;
        instruction_t *instruction = function->statements;
        write_instructions(instruction, writer, assembly);
        function = function->next;
    }
    return writer;
}
