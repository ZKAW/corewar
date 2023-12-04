/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** str_append
*/

#include <stdlib.h>
#include <string.h>
#include "lib.h"

char *str_append(char *str, const char *to_append)
{
    size_t len1 = my_strlen(str);
    size_t len2 = my_strlen(to_append);

    char* new_str = malloc(sizeof(char) * (len1 + len2 + 1));
    my_strcpy(new_str, str);
    my_strcat(new_str, to_append);
    free(str);

    return (new_str);
}
