/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** my_strtok
*/

#include "lib.h"
#include <unistd.h>

char *my_strpbrk(char *str, char const *accept)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strchr(accept, str[i]) != NULL) {
            return (str + i);
        }
    }
    return (NULL);
}

int my_strspn(char *str, char const *accept)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (my_strchr(accept, str[i]) == NULL) {
            return (i);
        }
    }
    return (i);
}

char *my_strtok(char *str, const char *delim)
{
    static char *save = NULL;
    char *token = NULL;

    if (str != NULL)
        save = str;
    if (save == NULL)
        return (NULL);
    save += my_strspn(save, delim);
    if (*save == '\0')
        return (NULL);
    token = save;
    save = my_strpbrk(token, delim);
    if (save != NULL)
        *save++ = '\0';
    return (token);
}
