/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** string_split.c
*/

/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** task04
*/

#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n);
int my_strlen(char const * str);

int is_include(char to_find, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find)
            return 1;
    }
    return 0;
}

int count_words_sep(char const *str, char* separator)
{
    int i;
    int count = 1;
    for (i = 0; str[i] != '\0'; i++) {
        if (is_include(str[i], separator))
            count++;
    }
    return count;
}

char **split_string_rec(char const * str, char **table,
                        char* separator, int position)
{
    int i;
    for (i = 0; !is_include(str[i], separator) && str[i] != '\0'; i++);
    table[position] = malloc(sizeof(char) * (i + 1));
    table[position][0] = '\0';
    if (( i > 0 && !is_include(str[i - 1], separator))
    && is_include(str[i], separator)) {
        my_strncpy(table[position], str, i);
        if (my_strlen(table[position]))
            position++;
    }
    if (str[i] == '\0') {
        if (i > 0 && !is_include(str[i - 1], separator))
            my_strncpy(table[position++], str, i);
        table[position] = 0;
        return table;
    }
    return split_string_rec(&str[i + 1], table, separator, position);
}

char **string_split(char const * str, char* separator)
{
    char **table;
    int count = count_words_sep(str, separator);
    table = malloc(sizeof(char*) * (count + 1));
    for (int i = 0; i < count; i++)
        table[i] = NULL;
    return split_string_rec(str, table, separator, 0);
}
