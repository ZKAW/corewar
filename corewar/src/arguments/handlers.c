/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** modules
*/

#include "corewar.h"

void handle_dump_arg(char **av, int i, args_t *args)
{
    char *value = av[i + 1];

    if (!is_positive_number(value))
        exit_with_error("Error: invalid dump value\n");

    int cycles = my_atoi(value);
    args->nbr_cycle_dump = cycles;
}

void handle_prog_number_arg(char **av, int i, args_t *args)
{
    char *value = av[i + 1];
    int last_champion = args->nb_champions - 1;

    if (!is_positive_number(value))
        exit_with_error("Error: invalid program number\n");
    if (my_atoi(value) < 1 || my_atoi(value) > MAX_ARGS_NUMBER)
        exit_with_error("Error: prog number must be between 1 and 4\n");
    for (int i = 0; i < args->nb_champions - 1; i++) {
        if (args->champions[i]->prog_number == my_atoi(value))
            exit_with_error("Error: prog number already exists\n");
    }
    args->champions[last_champion]->prog_number = my_atoi(value);
}

void handle_address_arg(char **av, int i, args_t *args)
{
    char *value = av[i + 1];
    int last_champion = args->nb_champions - 1;

    if (!is_positive_number(value))
        exit_with_error("Error: invalid load address\n");
    args->champions[last_champion]->address = my_atoi(value);
}
