/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** args
*/

#include "corewar.h"

static void handle_flags(int ac, char **argv, int i, args_t *args)
{
    if (i + 1 >= ac)
        exit_with_error("Error: invalid flag\n");
    if (my_strcmp(argv[i], "-dump") == 0) {
        handle_dump_arg(argv, i, args);
        return;
    }
    if (my_strcmp(argv[i], "-n") == 0) {
        handle_prog_number_arg(argv, i, args);
        return;
    } else if (my_strcmp(argv[i], "-a") == 0) {
        handle_address_arg(argv, i, args);
        return;
    } else
        exit_with_error("Error: invalid flag\n");
}

static void handle_file(char *filename, args_t *args)
{
    int last_champion = args->nb_champions - 1;
    if (!is_file_exist(filename))
        exit_with_error("Error: file doesn't exist\n");
    if (str_endswith(filename, ".cor") == 0)
        exit_with_error("Error: invalid file extension\n");

    args->champions[last_champion]->filename = filename;
    add_empty_champion(args);
}

args_t *parse_args(int ac, char **argv)
{
    args_t *args = init_args();
    int i = 1;

    if (ac < 2)
        exit_with_error("Error: not enough arguments, try -h\n");

    add_empty_champion(args);
    for (; i < ac; i++) {
        if (argv[i][0] == '-') {
            handle_flags(ac, argv, i, args);
            i++;
        } else {
            handle_file(argv[i], args);
        }
    }
    args->nb_champions--;
    if (args->nb_champions < 2)
        exit_with_error("Error: not enough champions\n");
    return (args);
}
