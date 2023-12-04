/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** display
*/

#include "corewar.h"

void show_winner(corewar_t *corewar)
{
    champion_t *winner;
    if (corewar->last_alive_id < 0)
        return;
    winner = get_champion_by_id(corewar->original_champions,
                                corewar->last_alive_id);

    if (!winner || winner->is_forked) {
        return;
    }

    my_putstr("Le joueur ", 1);
    my_putnbr(winner->id);
    my_putstr(" (", 1);
    my_putstr(winner->header.prog_name, 1);
    my_putstr(") a gagné.\n", 1);
}
