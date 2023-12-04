/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** merge_array
*/

#include <stdlib.h>
#include <string.h>
#include "lib.h"

char *merge_array(char** array)
{
    char* merged_str;
    int c = 0;
    for (int i = 0; array[i]; i++)
        c += my_strlen(array[i]);
    merged_str = malloc(sizeof(char) * (c + 1));
    merged_str[0] = '\0';
    for (int i = 0; array[i]; i++)
        my_strcat(merged_str, array[i]);
    return merged_str;
}
