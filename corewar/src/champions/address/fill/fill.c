/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** fill
*/

#include "corewar.h"

void fill_addresses(champion_t **champions, int nb_champions,
                    address_fill_type_t type)
{
    if (type == EMPTY_ADDR)
        fill_empty_addresses(champions, nb_champions);
    if (type == ONE_ADDR)
        fill_one_address(champions, nb_champions);
    if (type == MULTIPLE_ADDR)
        fill_multiple_addresses(champions, nb_champions);
    if (type == CONSECUTIVE_ADDR)
        fill_consecutive_addresses(champions, nb_champions);
}
