/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** info
*/

#include "corewar.h"

champion_t *get_champion_by_id(champion_t **champions, int id)
{
    for (int i = 0; champions[i]; i++) {
        if (champions[i]->id == id)
            return (champions[i]);
    }
    return (NULL);
}
