/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** helpers
*/

#include "corewar.h"

bool is_register(instruct_t instruct, int arg_nb)
{
    for (int i = 0; i < arg_nb; i++) {
        if (instruct.args[i].type != T_REG)
            continue;
        if (instruct.args[i].val < 1 || instruct.args[i].val > REG_NUMBER)
            return false;
    }
    return true;
}
