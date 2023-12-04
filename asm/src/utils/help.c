/*
** EPITECH PROJECT, 2023
** help.c
** File description:
** aa
*/

#include "asm.h"

extern int print_help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "./asm file_name[.s]\n", 20);
    write(1, "DESCRIPTION\n", 13);
    write(1, "file_name file in assembly", 26);
    write(1, " language to be converted into file_name.cor, an ", 49);
    write(1, "executable in the Virtual Machine.\n", 35);
    return 0;
}
