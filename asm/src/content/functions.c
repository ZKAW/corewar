/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** functions.c
*/

#include "asm.h"

function_t *new_function(function_t* next)
{
    function_t* new = malloc(sizeof(function_t));
    new->label = NULL;
    new->statements = NULL;
    new->next = next;
    return new;
}

// void dump_asm(asm_t* assembly)
// {
//     function_t* function = assembly->functions;
//     instruction_t* statement = NULL;
//     while (function != NULL) {
//         printf("function: %s\n", function->label);
//         statement = function->statements;
//         while (statement != NULL) {
//             printf("  statement: %s\n", statement->name);
//             printf("    args: ");
//             // for (int i = 0; statement->params[i]; i++) {
//             //     printf("%s ", statement->params[i]);
//             // }
//             printf("\n");
//             statement = statement->next;
//         }
//         printf("\n");
//         function = function->next;
//     }
// }
