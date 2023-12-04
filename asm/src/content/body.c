/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** take_content
*/

#include "asm.h"

int is_label(char *line)
{
    int i = 0;
    for (i = 0; line[i] != '\0' && line[i] != ':'; i++)
        if (line[i] == ' ' || line[i] == '\t')
            return 0;
    if (line[i] == ':')
        return 1;
    return 0;
}

char *skip_whitespace(char *str)
{
    while (*str && (*str == ' ' || *str == '\t'))
        str++;
    return str;
}

instruction_t *get_statement(char* line, instruction_t* next)
{
    instruction_t* new = malloc(sizeof(instruction_t));
    new->name = my_strtok(my_strdup(line), " \t");
    for (int i = 0; op_tab[i].mnemonique != NULL; i++)
        if (my_strcmp(op_tab[i].mnemonique, new->name) == 0)
            new->op = op_tab[i];
    new->params = tokenize_string(line + my_strlen(new->name), ", ");
    new->next = next;
    return new;
}

char *skip_comma(char *str)
{
    while (*str && *str != ',')
        str++;
    if (*str == ',')
        str++;
    return str;
}

void fill_body(FILE* fd, asm_t* assembly)
{
    size_t len = 0; ssize_t read;
    function_t *functions = new_function(NULL);
    char *line = NULL, *buffer = NULL;
    while ((read = getline(&buffer, &len, fd)) != -1) {
        line = skip_whitespace(my_strdup(buffer));
        line[my_strlen(line) - 1] = '\0';
        if (is_label(line) && functions->statements)
            functions = new_function(functions);
        if (functions->label == NULL && is_label(line)) {
            functions->label = my_strtok(my_strdup(line), ":");
            line = line + my_strlen(functions->label) + 1;
            line = skip_whitespace(line);
        }
        if (line[0] == '\0') continue;
        functions->statements = get_statement(line, functions->statements);
    }
    assembly->functions = reverse_functions(functions);
}
