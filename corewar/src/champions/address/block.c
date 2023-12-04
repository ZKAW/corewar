/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** address
*/

#include "corewar.h"

static int get_block_size(champion_t *champion)
{
    int start = champion->pc;
    int end = start + champion->header.prog_size;

    if (start == -1)
        return 0;

    if (end > MEM_SIZE)
        end = MEM_SIZE;

    if (start > MEM_SIZE)
        start = MEM_SIZE;

    return end - start;
}

blocks_t get_biggest_blocks(champion_t **champions)
{
    blocks_t biggest_blocks = {0, 0};
    int biggest_size = 0;
    int size = 0;

    for (int i = 0; champions[i]; i++) {
        size = get_block_size(champions[i]);
        if (size > biggest_size) {
            biggest_size = size;
            biggest_blocks.first = champions[i]->pc;
            biggest_blocks.second = champions[i]->pc + size;
        }
    }
    return biggest_blocks;
}

blocks_t get_smallest_blocks(champion_t **champions)
{
    blocks_t smallest_blocks = {0, 0};
    int smallest_size = MEM_SIZE;
    int size = 0;

    for (int i = 0; champions[i]; i++) {
        size = get_block_size(champions[i]);
        if (size < smallest_size) {
            smallest_size = size;
            smallest_blocks.first = champions[i]->pc;
            smallest_blocks.second = champions[i]->pc + size;
        }
    }
    return smallest_blocks;
}
