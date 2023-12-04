/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** tokenize_string.c
*/

/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** input
*/

#include "asm.h"

char **tokenize_string(char *input, char *sep)
{
    char *input_dup = my_strdup(input);
    char **parsed = malloc(sizeof(char *) * (my_strlen(input_dup) + 1));
    int i = 0;
    char *token = my_strtok(input_dup, sep);

    while (token != NULL) {
        parsed[i] = clean_str(my_strdup(token));
        token = my_strtok(NULL, sep);
        i++;
    }
    parsed[i] = NULL;
    free(input_dup);
    return (parsed);
}
