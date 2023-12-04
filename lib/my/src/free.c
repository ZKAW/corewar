/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** free_arr
*/

#include <stdlib.h>

void safe_free(void *ptr)
{
    if (ptr != NULL)
        free(ptr);
}

void free_arr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        safe_free(arr[i]);
    safe_free(arr);
}
