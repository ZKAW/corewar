/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** free
*/

#include "corewar.h"

void safe_free(void *ptr)
{
    if (ptr)
        free(ptr);
}
