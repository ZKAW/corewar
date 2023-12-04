/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** args
*/

#include "corewar.h"

champion_arg_t *init_champion_arg(void)
{
    champion_arg_t *champion_arg = malloc(sizeof(champion_arg_t));

    champion_arg->filename = NULL;
    champion_arg->prog_number = -1;
    champion_arg->address = -1;
    return (champion_arg);
}

void *add_empty_champion(args_t *args)
{
    int i = 0;

    while (args->champions[i] != NULL)
        i++;
    args->champions = realloc(args->champions,
                    sizeof(champion_arg_t *) * (i + 2));
    args->champions[i] = init_champion_arg();
    args->champions[i + 1] = NULL;
    args->nb_champions++;
    if (args->nb_champions > MAX_ARGS_NUMBER + 1)
        exit_with_error("Error: too many champions\n");
    return (args);
}

args_t *init_args(void)
{
    args_t *args = malloc(sizeof(args_t));

    args->nbr_cycle_dump = -1;
    args->nb_champions = 0;
    args->champions = malloc(sizeof(champion_arg_t *) * 1);
    args->champions[0] = NULL;
    return (args);
}
