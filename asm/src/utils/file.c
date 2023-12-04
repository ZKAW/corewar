/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** file
*/

#include "asm.h"

void create_file(char* filepath, asm_t* assembly)
{
    filepath[my_strlen(filepath) - 2] = '\0';
    char* new_filepath = my_strcat(filepath, ".cor");
    int fd = open(new_filepath, O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if (fd < 0) {
        write(2, "Error: can't create file\n", 25);
        exit(84);
    }
    writer_t* writer = write_functions(fd, assembly);
    write_labels(writer, assembly);
    int prog_size = writer_get_size(writer);
    write_head(prog_size, fd, assembly);
    for (int i = 0; i < writer->index; i++)
        write(fd, &writer->value[i], writer->size[i]);
    close(fd);
}
