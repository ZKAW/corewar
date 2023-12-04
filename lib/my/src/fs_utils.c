/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** fs_utils
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int is_file_exist(char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return 0;
    close(fd);
    return 1;
}
