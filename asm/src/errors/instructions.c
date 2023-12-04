/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instructions
*/

#include "asm.h"

static int too_many_args(instruction_t* ins)
{
    int count = 0;
    for (; ins->params[count]; ++count);

    for (int i = 0; op_tab[i].mnemonique; i++)
        if (!my_strcmp(op_tab[i].mnemonique, ins->name)
            && count == op_tab[i].nbr_args) {
            return 1;
        }
    return 0;
}

int error_handling(instruction_t *ins)
{
    while (ins->next != NULL) {
        if (!get_instruction(ins->name))
            return -1;
        if (!too_many_args(ins))
            return -1;
        ins = ins->next;
    }
    return 0;
}
