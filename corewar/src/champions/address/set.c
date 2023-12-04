/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** set
*/

#include "corewar.h"

static int count_chosen_addresses(champion_t **champions)
{
    int chosen_addresses = 0;

    for (int i = 0; champions[i]; i++)
        if (champions[i]->pc != -1)
            chosen_addresses++;
    return chosen_addresses;
}

void set_addresses(champion_t **champions, int nb_champions)
{
    int chosen_addresses = count_chosen_addresses(champions);

    if (chosen_addresses == 0) {
        fill_addresses(champions, nb_champions, EMPTY_ADDR); return;
    }
    if (chosen_addresses == 1) {
        fill_addresses(champions, nb_champions, ONE_ADDR); return;
    }
    if (count_champs(champions) - chosen_addresses == 1) {
        fill_addresses(champions, nb_champions, MULTIPLE_ADDR); return;
    }
    if (count_champs(champions) - chosen_addresses == 2) {
        fill_addresses(champions, nb_champions, CONSECUTIVE_ADDR); return;
    }
    exit_with_error("Error: address overlap\n");
}
