/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** init
*/

#include "corewar.h"

static champion_t **copy_champions(champion_t **champions)
{
    champion_t **new_champions = malloc(sizeof(champion_t *) * MAX_ARGS_NUMBER);
    if (new_champions == NULL)
        exit_with_error("Error: malloc failed\n");

    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        new_champions[i] = NULL;
    }

    for (int i = 0; champions[i] != NULL; i++) {
        new_champions[i] = copy_champion(champions[i]);
    }
    return (new_champions);
}

static char *set_bytes(char *arena, champion_t *champion)
{
    int size = champion->header.prog_size;
    char *buffer = malloc(sizeof(char) * size);
    int read_bytes = read(champion->fd, buffer, size);

    if (read_bytes == -1)
        exit_with_error("Error: read failed\n");

    if (read_bytes != size)
        exit_with_error("Error: read failed\n");

    for (int i = champion->pc; size--; i++) {
        if (i >= MEM_SIZE)
            i %= MEM_SIZE;
        arena[i] = *buffer++;
    }
    return (arena);
}

static char *init_arena(champion_t **champions)
{
    char *arena = malloc(sizeof(char) * MEM_SIZE);
    if (arena == NULL)
        exit_with_error("Error: malloc failed\n");

    for (int i = 0; i < MEM_SIZE; i++)
        arena[i] = 0;

    for (int i = 0; champions[i] != NULL; i++) {
        set_bytes(arena, champions[i]);
    }
    return (arena);
}

corewar_t *init_corewar(int ac, char **av)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));
    if (corewar == NULL)
        exit_with_error("Error: malloc failed\n");
    args_t *args = parse_args(ac, av);
    corewar->champions = init_champions(args);
    corewar->original_champions = copy_champions(corewar->champions);
    corewar->arena = init_arena(CHAMPIONS);
    corewar->cycle = 0;
    corewar->cycle_to_die = CYCLE_TO_DIE;
    corewar->call_cycle = 0;
    corewar->nbr_cycle_dump = args->nbr_cycle_dump;
    corewar->nb_champions = args->nb_champions;
    corewar->nb_alive = args->nb_champions;
    corewar->should_dump = false;
    corewar->last_alive_id = -1;
    if (corewar->nbr_cycle_dump != -1)
        corewar->should_dump = true;
    return (corewar);
}
