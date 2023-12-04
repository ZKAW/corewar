/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** constructor.c
*/

#include "asm.h"

instruction_t *reverse_instructions(instruction_t* instructions)
{
    instruction_t* prev = NULL;
    instruction_t* current = instructions;
    instruction_t* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    instructions = prev;
    return instructions;
}

function_t *reverse_functions(function_t* functions)
{
    function_t* prev = NULL;
    function_t* current = functions;
    function_t* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->statements = reverse_instructions(current->statements);
        prev = current;
        current = next;
    }
    functions = prev;
    return functions;
}
