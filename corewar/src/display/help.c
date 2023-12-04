/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** help
*/

#include "corewar.h"

void disp_help(void)
{
    my_putstr("USAGE\n", 1);
    my_putstr("\t./corewar [-dump nbr_cycle] [[-n prog_number] ", 1);
    my_putstr("[-a address] prog_name] ...\n\n", 1);
    my_putstr("DESCRIPTION\n", 1);
    my_putstr("\t-dump nbr_cycle dumps the memory after the nbr_cycle ", 1);
    my_putstr("execution (if the round isn't\n\t\talready over) with the ", 1);
    my_putstr("following format: 32 bytes/line in\n\t\thexadecimal ", 1);
    my_putstr("(A0BCDEFE1DD3...)\n", 1);
    my_putstr("\t-n prog_number sets the next program's number. ", 1);
    my_putstr("By default, the first free number\n\t\tin the parameter ", 1);
    my_putstr("order\n", 1);
    my_putstr("\t-a address sets the next program's loading address. ", 1);
    my_putstr("When no address is\n\t\tspecified, optimize the addresses ", 1);
    my_putstr("so that the processes are as far\n\t\taway from each other ", 1);
    my_putstr("as possible. The addresses are MEM_SIZE modulo\n", 1);
}
