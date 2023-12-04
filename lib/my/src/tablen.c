/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** tablen
*/

#include <unistd.h>

int tablen(char **tab)
{
    int i = 0;

    if (!tab)
        return (0);
    for (; tab[i]; i++);
    return (i);
}

int any_tablen(void **tab)
{
    int i = 0;

    if (!tab)
        return (0);
    for (; tab[i]; i++);
    return (i);
}
