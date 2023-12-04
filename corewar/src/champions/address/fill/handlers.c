/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** handlers
*/

#include "corewar.h"

void fill_empty_addresses(champion_t **champions, int nb_champions)
{
    int total_size = get_champs_size(champions);
    size_t separation = (MEM_SIZE - total_size) / nb_champions;
    size_t offset = 0;

    for (int i = 0; champions[i]; ++i) {
        champions[i]->pc = offset;
        offset += champions[i]->header.prog_size + separation;
    }
}

void fill_one_address(champion_t **champions, int nb_champions)
{
    int total_size = get_champs_size(champions);
    size_t separation = (MEM_SIZE - total_size) / count_champs(champions);
    int i = 0;

    sort_champs_by_address(champions);

    for (; i < nb_champions; i++) {
        if (champions[i]->pc != -1) {
            break;
        }
    }

    for (i = i - 1; i >= 0; i--) {
        champions[i]->pc = champions[i + 1]->pc +
                        champions[i + 1]->header.prog_size + separation;
    }
}

void fill_multiple_addresses(champion_t **champions, int nb_champions)
{
    blocks_t biggest_blocks = get_biggest_blocks(champions);
    size_t separation = (biggest_blocks.second - biggest_blocks.first)
                        / nb_champions;

    for (int i = 0; i < nb_champions; i++) {
        champions[i]->pc = biggest_blocks.first + separation * i +
            (separation - champions[i]->header.prog_size) / 2;
    }
}

static void handle_two_separate_blocks(blocks_t biggest_block,
                                        champion_t **champions)
{
    champion_t *champion_3 = get_champion_by_id(champions, 3);
    champion_t *champion_4 = get_champion_by_id(champions, 4);

    if (champion_3 != NULL) {
        champion_3->pc = biggest_block.first +
            ((biggest_block.second - champion_3->header.prog_size) / 2);
    }

    blocks_t remaining_blocks = get_biggest_blocks(champions);

    if (champion_4 != NULL) {
        champion_4->pc = remaining_blocks.first +
            ((remaining_blocks.second - champion_4->header.prog_size) / 2);
    }
}

void fill_consecutive_addresses(champion_t **champions, int nb_champions)
{
    get_champs_size(champions);

    blocks_t biggest_block = get_biggest_blocks(champions);
    blocks_t smallest_block = get_smallest_blocks(champions);
    champion_t *champion_1 = get_champion_by_id(champions, 1);
    champion_t *champion_2 = get_champion_by_id(champions, 2);

    if (champion_1 != NULL && champion_2 != NULL) {
        int new_size = biggest_block.second - champion_1->header.prog_size;
        if (new_size >= smallest_block.second) {
            int offset = (new_size - (champion_2->header.prog_size +
                                    champion_1->header.prog_size)) / 3;
            champion_1->pc = biggest_block.first + offset;
            champion_2->pc = champion_1->pc
                            + champion_1->header.prog_size + offset;
            return;
        }
    }

    handle_two_separate_blocks(biggest_block, champions);
}
