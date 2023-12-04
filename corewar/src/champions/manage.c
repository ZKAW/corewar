/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** manage
*/

#include "corewar.h"

void delete_champion(corewar_t *corewar, int id)
{
    int i = 0;

    for (; CHAMPIONS[i]; i++) {
        if (CHAMPIONS[i] && CHAMPIONS[i]->id == id) {
            CHAMPIONS[i]->is_forked ? 0 : corewar->nb_alive--;
            free(CHAMPIONS[i]);
            break;
        }
    }

    for (; CHAMPIONS[i]; i++) {
        CHAMPIONS[i] = CHAMPIONS[i + 1];
    }
}

champion_t *copy_champion(champion_t *champion)
{
    champion_t *new_champion = malloc(sizeof(champion_t));
    if (new_champion == NULL)
        exit_with_error("Error: malloc failed\n");

    new_champion->id = champion->id;
    new_champion->header = copy_header(champion->header);
    new_champion->address = champion->address;
    new_champion->is_forked = champion->is_forked;
    new_champion->freeze_duration = champion->freeze_duration;
    new_champion->carry = champion->carry;
    new_champion->pc = champion->pc;
    new_champion->fd = champion->fd;
    new_champion->life = champion->life;
    for (int i = 0; i < REG_NUMBER; i++)
        new_champion->registers[i] = champion->registers[i];
    return (new_champion);
}

header_t copy_header(header_t header)
{
    header_t new_header;

    new_header.magic = header.magic;
    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        new_header.prog_name[i] = header.prog_name[i];
    new_header.prog_size = header.prog_size;
    for (int i = 0; i < COMMENT_LENGTH; i++)
        new_header.comment[i] = header.comment[i];
    return new_header;
}

void append_champion(corewar_t *corewar, champion_t *new)
{
    int champion_count = count_champs(CHAMPIONS);

    CHAMPIONS = realloc(CHAMPIONS,
                        (champion_count + 2) * sizeof(champion_t *));
    if (CHAMPIONS == NULL) {
        exit_with_error("Error: realloc failed\n");
    }

    CHAMPIONS[champion_count] = new;
    CHAMPIONS[champion_count + 1] = NULL;
}
