/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** check_file
*/

#include "asm.h"

int error_header(char* line, char* trimmed_line, asm_t* assembly,
    int line_nb)
{
    if (line_nb == 1) {
        if (parse_name(line, trimmed_line, assembly) == 84)
            return 84;
    }
    if (line_nb == 2) {
        if (parse_comment(line, trimmed_line, assembly) == 84)
            return 84;
    }
    return 0;
}

extern char *verify_file(char *file)
{
    int i = my_strlen(file) - 1; int fd = 0; size_t size = 0;
    char buffer[2];

    if ((fd = open(file, O_RDONLY)) < 0) {
        my_putstr("Error: File doesn't exist\n", 2);
        return NULL;
    }if ((size = read(fd, buffer, 1)) == 0) {
        my_putstr("Error: File is empty\n", 2);
        return NULL;
    }close(fd);
    for (; i >= 0 && file[i] != '.'; i--);
    if (i == -1) {
        my_putstr("Error: File doesn't have extension\n", 2);
        return NULL;
    }
    i++;
    if (file[i] == 's' && file[i + 1] == '\0')
        return my_strdup(file);
    my_putstr("Error: File extension must be [.s]\n", 2);
    return NULL;
}
