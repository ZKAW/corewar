/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** endswith
*/

#include "lib.h"

int str_endswith(char const *str, char const *end)
{
    int str_len = my_strlen(str);
    int end_len = my_strlen(end);

    if (str_len < end_len)
        return 0;

    return my_strcmp(str + str_len - end_len, end) == 0;
}
