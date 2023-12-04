/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** freeze
*/

#include "corewar.h"

void freeze_champ_once(champion_t *champion)
{
    champion->pc = (champion->pc + 1) % MEM_SIZE;
    champion->freeze_duration = 1;
}

void freeze_champ_by_cycles(champion_t *champion, int code, int idx)
{
    champion->pc = (champion->pc + count_instr_bytes(code, idx)) % MEM_SIZE;
    champion->freeze_duration = op_tab[idx].nbr_cycles;
}
