/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** struct
*/

#include "asm.h"

writer_t *writer_init(void);

void init_struct(asm_t *assembly)
{
    assembly->content = NULL;
    assembly->name = NULL;
    assembly->comment = NULL;
    assembly->filepath = NULL;
    assembly->fd = 0;
    assembly->size = 0;
    assembly->line = 0;
    assembly->instruc = NULL;
    assembly->labels = NULL;
    assembly->writer = writer_init();
}
