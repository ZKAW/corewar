/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** print_array
*/

#include <stdio.h>
#include "lib.h"

void print_array(char** array)
{
    for (int i = 0; array[i]; i++) {
        my_putstr(array[i], 1);
    }
}
