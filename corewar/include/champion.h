/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** champion
*/

#ifndef CHAMPION_H_
    #define CHAMPION_H_

    #include <stdbool.h>

    #define CHAMPIONS corewar->champions

typedef struct header_s header_t;
typedef struct champion_s champion_t;
typedef struct corewar_s corewar_t;
typedef struct args_s args_t;

typedef struct blocks_s {
    int first;
    int second;
} blocks_t;

typedef struct champion_s {
    int id;
    header_t header;
    int address;
    int registers[REG_NUMBER];
    int pc;
    bool is_forked;
    int freeze_duration;
    int carry;
    int fd;
    int life;
} champion_t;

typedef enum address_fill_type_e {
    EMPTY_ADDR,
    ONE_ADDR,
    MULTIPLE_ADDR,
    CONSECUTIVE_ADDR
} address_fill_type_t;

champion_t **init_champions(args_t *args);
int count_champs(champion_t **champions);
void sort_champs_by_id(champion_t **champions);
void sort_champs_by_address(champion_t **champions);
void delete_champion(corewar_t *corewar, int id);
champion_t *get_champion_by_id(champion_t **champions, int id);
int get_champion_index(corewar_t *corewar, int nb);
int get_champs_size(champion_t **champions);
blocks_t get_biggest_blocks(champion_t **champions);
blocks_t get_smallest_blocks(champion_t **champions);
void set_addresses(champion_t **champions, int nb_champions);
void fill_addresses(champion_t **champions, int nb_champions,
                    address_fill_type_t type);
void fill_empty_addresses(champion_t **champions, int nb_champions);
void fill_one_address(champion_t **champions, int nb_champions);
void fill_multiple_addresses(champion_t **champions, int nb_champions);
void fill_consecutive_addresses(champion_t **champions, int nb_champions);
void check_addresses(champion_t **champions);
void append_champion(corewar_t *corewar, champion_t *new);
header_t copy_header(header_t header);
header_t read_header(int fd);
int is_id_taken(champion_t **champions, int id);
int get_new_id(champion_t **champions, int id);

#endif /* !CHAMPION_H_ */
