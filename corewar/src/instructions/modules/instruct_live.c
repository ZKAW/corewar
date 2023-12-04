/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instruct_live
*/

#include "corewar.h"

static void disp_is_alive(champion_t *champion)
{
    my_putstr("Le joueur ", 1);
    my_putnbr(champion->id);
    my_putstr(" (", 1);
    my_putstr(champion->header.prog_name, 1);
    my_putstr(") est en vie.\n", 1);
}

int instruct_live(INSTRUCT_PARAMS)
{
    corewar->call_cycle++;

    if (instruct.args[0].val < 1 || instruct.args[0].val > MAX_ARGS_NUMBER)
        return 0;
    if (corewar->call_cycle >= NBR_LIVE) {
        corewar->cycle_to_die -= CYCLE_DELTA;
        corewar->call_cycle = 0;
    }
    champion_t *target_champion = get_champion_by_id(CHAMPIONS,
                                                    instruct.args[0].val);

    if (target_champion && target_champion->life > 0) {
        disp_is_alive(target_champion);
        target_champion->life = corewar->cycle_to_die;
        corewar->last_alive_id = target_champion->id;
    }

    return (0);
}
