/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** writer.c
*/

#include "asm.h"

writer_t *writer_init(void)
{
    writer_t* writer = malloc(sizeof(writer_t));
    writer->size = malloc(sizeof(int) * 1024);
    writer->value = malloc(sizeof(int) * 1024);
    writer->max_len = 1024;
    writer->index = 0;
    return writer;
}

void writer_append(writer_t* writer, int value, int size)
{
    int* tmp;
    if (writer->index >= writer->max_len) {
        writer->max_len *= 2;
        tmp = malloc(sizeof(int) * writer->max_len);
        for (int i = 0; i < writer->index; i++)
            tmp[i] = writer->size[i];
        free(writer->size);
        writer->size = tmp;
        tmp = malloc(sizeof(int) * writer->max_len);
        for (int i = 0; i < writer->index; i++)
            tmp[i] = writer->value[i];
        free(writer->value);
        writer->value = tmp;
    }
    writer->size[writer->index] = size;
    writer->value[writer->index] = value;
    writer->index++;
}

int writer_get_size(writer_t* writer)
{
    int size = 0;
    for (int i = 0; i < writer->index; i++)
        size += writer->size[i];
    return size;
}
