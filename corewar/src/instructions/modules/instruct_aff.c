/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instruct_aff
*/

#include "corewar.h"

int instruct_aff(INSTRUCT_PARAMS)
{
    if (!is_register(instruct, 0))
        return -1;

    char c = champion->registers[instruct.args[0].val - 1] % 256;
    if (c == 42)
        c = '*';
    my_putchar(c);
    return (0);
}
