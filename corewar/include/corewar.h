/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

    #include "lib.h"
    #include "op.h"
    #include "utils.h"
    #include "champion.h"
    #include "display.h"
    #include "arguments.h"
    #include "memory.h"
    #include "instructions.h"

typedef struct corewar_s {
    char *arena;
    bool should_dump;
    long nbr_cycle_dump;
    long cycle;
    long cycle_to_die;
    long call_cycle;
    int nb_alive;
    int nb_champions;
    int last_alive_id;
    champion_t **champions;
    champion_t **original_champions;
} corewar_t;

corewar_t *init_corewar(int ac, char **av);
void exec_vm(corewar_t *corewar);
void show_winner(corewar_t *corewar);
champion_t *copy_champion(champion_t *champion);

#endif /* !COREWAR_H_ */
