/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** vm
*/

#include "corewar.h"

static int handle_dump(corewar_t *corewar)
{
    if (!corewar->should_dump)
        return (0);
    if (corewar->cycle >= corewar->nbr_cycle_dump) {
        dump_memory(corewar->arena);
        return (1);
    }
    corewar->cycle++;
    return (0);
}

static void exec_cycle(corewar_t *corewar)
{
    for (int i = 0; CHAMPIONS[i]; i++) {
        if (CHAMPIONS[i]->freeze_duration > 0) {
            CHAMPIONS[i]->freeze_duration--;
            continue;
        }
        exec_instruction(corewar, CHAMPIONS[i]);
    }
}

static void update_champions(corewar_t *corewar)
{
    for (int i = 0; CHAMPIONS[i]; i++) {
        if (CHAMPIONS[i]->life > 0)
            CHAMPIONS[i]->life--;
        if (CHAMPIONS[i]->is_forked == true ||
            CHAMPIONS[i]->life > 0)
            continue;
        delete_champion(corewar, CHAMPIONS[i]->id);
        i = -1;
    }
}

void exec_vm(corewar_t *corewar)
{
    while (corewar->nb_alive > 1) {
        if (handle_dump(corewar)) {
            break;
        }
        exec_cycle(corewar);
        update_champions(corewar);
    }
    show_winner(corewar);
}
