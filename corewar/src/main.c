/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** main
*/

#include "corewar.h"

int main(int ac, char **av)
{
    if ((ac == 2) && (my_strcmp(av[1], "-h") == 0)) {
        disp_help();
        return 0;
    }

    corewar_t *corewar = init_corewar(ac, av);
    if (!corewar)
        exit_with_error("Error: could not initialize corewar\n");
    exec_vm(corewar);

    return 0;
}
