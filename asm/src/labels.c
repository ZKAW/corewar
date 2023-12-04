/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** labels.c
*/

#include "asm.h"

label_t *add_label(char *name, asm_t* assembly)
{
    label_t *label = malloc(sizeof(label_t));
    label->index = assembly->writer->index;
    label->name = name;
    label->next = assembly->labels;
    assembly->labels = label;
    return (label);
}

int get_label_position(asm_t* assembly, const char* name)
{
    function_t* function = assembly->functions;

    while (function) {
        if (function->label && my_strcmp(function->label, name) == 0) {
            return function->index;
        }
        function = function->next;
    }
    return -1;
}

int get_byte_sum(int index, writer_t* writer)
{
    int total = 0;
    for (int i = 0; i < index; i++) {
        total += writer->size[i];
    }
    return total;
}

int get_sum(int pos, int cursor, writer_t* writer)
{
    int total = 0;
    if (pos > cursor) {
        for (int i = cursor; i <= pos; i++)
            total += writer->size[i];
        total += writer->size[cursor];
    } else {
        for (int i = pos + 1; i < cursor; i++)
            total -= writer->size[i];
    }
    return total;
}

void write_labels(writer_t* writer, asm_t* assembly)
{
    label_t* label = assembly->labels;

    while (label) {
        int pos = get_label_position(assembly, label->name);
        int diff = get_sum(pos, label->index, assembly->writer);
        writer->value[label->index] = SWAP_UINT16(diff);
        label = label->next;
    }
}
