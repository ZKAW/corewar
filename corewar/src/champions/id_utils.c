/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** id_utils
*/

#include "corewar.h"

int is_id_taken(champion_t **champions, int id)
{
    for (int i = 0; champions[i]; i++) {
        if (champions[i]->id == id)
            return (1);
    }
    return (0);
}

int get_new_id(champion_t **champions, int id)
{
    while (is_id_taken(champions, id))
        id++;
    return (id);
}
