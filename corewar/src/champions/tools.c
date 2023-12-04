/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** tools
*/

#include "corewar.h"

int count_champs(champion_t **champions)
{
    int size = 0;
    if (!champions)
        return 0;

    while (champions[size])
        size++;
    return size;
}

int get_champs_size(champion_t **champions)
{
    int size = 0;
    if (!champions)
        return 0;

    for (int i = 0; champions[i]; i++)
        size += champions[i]->header.prog_size;

    if (size > MEM_SIZE)
        exit_with_error("Champions size are too big for the memory\n");
    return size;
}
