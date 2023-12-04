/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** checker
*/

#include "corewar.h"

static void check_overflow(champion_t **champions)
{
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        champion_t *champion = get_champion_by_id(champions, i + 1);
        if (!champion)
            continue;
        if (champion->address + champion->header.prog_size > MEM_SIZE) {
            my_putstr("Error: champion is too big.\n", 2);
            exit(84);
        }
    }
}

static void check_overlap(champion_t **champions, int i)
{
    int start = champions[i]->pc;

    for (int j = 0; champions[j]; j++) {
        if (i == j)
            continue;
        if (start >= champions[j]->pc
            && start < champions[j]->pc + champions[j]->header.prog_size) {
            my_putstr("Error: champions overlap.\n", 2);
            exit(84);
        }
    }
}

void check_addresses(champion_t **champions)
{
    for (int i = 0; champions[i]; i++) {
        check_overlap(champions, i);
    }
    check_overflow(champions);
}
