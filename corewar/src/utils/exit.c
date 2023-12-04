/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** error
*/

#include "corewar.h"

void exit_with_error(char const *message)
{
    my_putstr(message, 2);
    exit(84);
}
