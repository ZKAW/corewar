/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** dump
*/

#include "corewar.h"

void dump_memory(char *arena)
{
    for (int i = 0; i < MEM_SIZE; i += 32) {
        char *hex = itoa_base(i, BASE_HEX);
        int len = my_strlen(hex);
        write(1, hex, len);
        for (int j = 0; j < 5 - len; j++)
            write(1, " ", 1);
        write(1, ": ", 2);
        for (int j = 0; j < 32; j++) {
            hex = char_to_hex(arena[i + j]);
            my_putstr(hex, 1);
            write(1, " ", 1);
        }
        write(1, "\n", 1);
    }
}
