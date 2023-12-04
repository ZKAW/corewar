/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** init
*/

#include "corewar.h"

header_t read_header(int fd)
{
    header_t header;

    if (fd == -1) {
        write(2, "Error: Can't read source file\n", 30);
        exit(84);
    }
    if (read(fd, &header, sizeof(header_t)) != sizeof(header_t)) {
        write(2, "Error: Can't read source file\n", 30);
        exit(84);
    }
    if (my_be32toh(header.magic) != COREWAR_EXEC_MAGIC) {
        write(2, "Error: File is not a corewar executable\n", 40);
        exit(84);
    }
    header.prog_size = my_be32toh(header.prog_size);
    return (header);
}

static champion_t *init_champion(char *filepath, int address)
{
    champion_t *champion = malloc(sizeof(champion_t));
    int fd = open(filepath, O_RDONLY);
    champion->header = read_header(fd);

    champion->id = -1;
    champion->address = address;
    champion->is_forked = false;
    champion->freeze_duration = 0;
    champion->pc = address % MEM_SIZE;
    champion->carry = 0;
    champion->fd = fd;
    champion->registers[0] = -1;
    champion->life = CYCLE_TO_DIE;
    for (int i = 1; i < REG_NUMBER; i++)
        champion->registers[i] = 0;
    return (champion);
}

static void set_champions_ids(args_t *args, champion_t **champions)
{
    for (int i = 0; i < args->nb_champions; i++) {
        if (args->champions[i]->prog_number > 0) {
            champions[i]->id = args->champions[i]->prog_number;
            champions[i]->registers[0] = champions[i]->id;
        }
    }
    int id = 1;
    for (int i = 0; i < args->nb_champions; i++) {
        if (champions[i]->id == -1) {
            id = get_new_id(champions, id);
            champions[i]->id = id;
            champions[i]->registers[0] = champions[i]->id;
        }
    }
}

static void init_champions_helper(champion_t **champions, args_t *args)
{
    sort_champs_by_id(champions);
    set_addresses(champions, args->nb_champions);
    for (int i = 0; champions[i]; i++) {
        champions[i]->pc %= MEM_SIZE;
    }
    sort_champs_by_id(champions);
    check_addresses(champions);
}

champion_t **init_champions(args_t *args)
{
    champion_t **champions = malloc(sizeof(champion_t *) *
                            (args->nb_champions + 1));

    for (int i = 0; i < args->nb_champions; i++) {
        champions[i] = init_champion(args->champions[i]->filename,
                                    args->champions[i]->address);
    }
    champions[args->nb_champions] = NULL;
    set_champions_ids(args, champions);

    int champs_size = get_champs_size(champions);
    if ((champs_size > MEM_SIZE) || (champs_size < 1)) {
        exit_with_error("Error: Invalid champions size\n");
    }

    init_champions_helper(champions, args);

    return (champions);
}
