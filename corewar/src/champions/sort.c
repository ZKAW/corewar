/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** sort
*/

#include "corewar.h"

void swap(champion_t **a, champion_t **b)
{
    champion_t *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(champion_t **champions, int low, int high, int sort_type)
{
    int pivot = (sort_type == 0) ? champions[high]->id : champions[high]->pc;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if ((sort_type == 0 && champions[j]->id < pivot)
            || (sort_type == 1 && champions[j]->pc < pivot)) {
            i++;
            swap(&champions[i], &champions[j]);
            continue;
        }
        if ((champions[j]->id == -1 && champions[j + 1]->id == -1)
                && (champions[j]->pc < champions[j + 1]->pc)) {
            i++;
            swap(&champions[i], &champions[j]);
        }
    }
    swap(&champions[i + 1], &champions[high]);
    return (i + 1);
}

void quicksort(champion_t **champions, int low, int high, int sort_type)
{
    if (low < high) {
        int pi = partition(champions, low, high, sort_type);
        quicksort(champions, low, pi - 1, sort_type);
        quicksort(champions, pi + 1, high, sort_type);
    }
}

void sort_champs_by_id(champion_t **champions)
{
    int size = 0;
    while (champions[size] != NULL)
        size++;

    quicksort(champions, 0, size - 1, 0);
}

void sort_champs_by_address(champion_t **champions)
{
    int size = 0;
    while (champions[size] != NULL)
        size++;

    quicksort(champions, 0, size - 1, 1);
}
