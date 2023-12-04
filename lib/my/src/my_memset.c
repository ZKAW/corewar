/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_memset
*/

void *my_memset(void *s, int c, int n)
{
    char *str = s;

    for (int i = 0; i < n; i++)
        str[i] = c;
    return (s);
}
