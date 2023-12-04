/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** my_strchr
*/

#include <unistd.h>

char *my_strchr(char const *str, char c)
{
    int i = 0;

    if (str == NULL)
        return (NULL);
    while (str[i] != '\0') {
        if (str[i] == c)
            return ((char *)str + i);
        i++;
    }
    if (str[i] == c)
        return ((char *)str + i);
    return (NULL);
}
