/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** header
*/

#include "asm.h"

int is_label(char *line);
char *skip_whitespace(char *str);

void write_head(int prog_size, int fd, asm_t *assembly)
{
    header_t header = {0};
    header.magic = COREWAR_EXEC_MAGIC;
    header.magic = convert_endian(header.magic);
    my_strcpy(header.prog_name, assembly->name);
    my_strcpy(header.comment, assembly->comment);
    header.prog_size = prog_size;
    header.prog_size = convert_endian(header.prog_size);
    write(fd, &header, sizeof(header_t));
}

char *parse_header(char *line)
{
    char *tmp = NULL;
    int i = 0;
    int j = 0;

    for (; line[i] != '\0' && line[i] != '"'; i++);
    if (line[i] == '\0')
        return NULL;
    for (j = i + 1; line[j] != '\0' && line[j] != '"'; j++);
    if (line[j] == '\0')
        return NULL;
    tmp = malloc(sizeof(char) * (j - i));
    tmp = my_strncpy(tmp, line + i + 1, j - i - 1);
    tmp[j - i - 1] = '\0';
    return tmp;
}

int parse_name(char* line, char* trimmed_line, asm_t* assembly)
{
    if (trimmed_line == NULL || my_strcmp(trimmed_line, NAME_CMD_STRING) != 0) {
        write(2, "Error: line 8: Expected .name\n", 30);
        return 84;
    }
    if (my_strlen(parse_header(line)) > PROG_NAME_LENGTH) {
        write(2, "Error: line 8: .name too long\n", 30);
        return 84;
    }
    assembly->name = my_strdup(parse_header(line));
    return 0;
}

int parse_comment(char* line, char* trimmed_line, asm_t* assembly)
{
    if (trimmed_line == NULL || my_strcmp(trimmed_line, COMMENT_CMD_STRING)
        != 0) {
        write(2, "Error: line 12: Expected .comment\n", 34);
        return 84;
    }
    if (my_strlen(parse_header(line)) > COMMENT_LENGTH) {
        write(2, "Error: line 12: .comment too long\n", 34);
        return 84;
    }
    assembly->comment = my_strdup(parse_header(line));
    return 0;
}

int fill_header(FILE* fd, asm_t *assembly)
{
    size_t len = 0;
    ssize_t read;
    char *lines = NULL;
    int line_number = 1;
    if (fd == NULL) {
        write(2, "Error opening the file.\n", 24);
        return 84;
    }
    while ((read = getline(&lines, &len, fd)) != -1 && line_number <= 2) {
        char* line = my_strdup(lines);
        char *trimmed_line = my_strdup(my_strtok(lines, " \t\n"));
        if (error_header(line, trimmed_line, assembly, line_number) == 84)
            return 84;
        line_number++;
    }
    return 0;
}
