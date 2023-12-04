/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** main
*/

#include "asm.h"

int get_instruc(char* test)
{
    char* instruc[16] = {"live", "ld", "st", "add", "sub", "and", "or", "xor",
    "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff"};
    for (int i = 0; i < 16; i++) {
        if (!my_strcmp(test, instruc[i]))
            return 1;
    }
    return 0;
}

int get_instruction(char *param)
{
    for (int i = 0; op_tab[i].mnemonique; i++)
        if (!my_strcmp(op_tab[i].mnemonique, param))
            return op_tab[i].code;
    return 0;
}

to_write_t get_dir_type(instruction_t *instruction, int nb)
{
    char* two_bytes[7] = {"ldi", "lfork", "lldi", "zjmp", "fork", "sti", NULL};
    char* four_bytes[6] = {"lld", "xor", "or", "ld", "live", NULL};
    for (int i = 0; two_bytes[i]; i++) {
        if (!my_strcmp(instruction->name, two_bytes[i]))
            return ((to_write_t){SWAP_UINT16(nb), IND_SIZE});
    }
    for (int i = 0; four_bytes[i]; i++) {
        if (!my_strcmp(instruction->name, four_bytes[i])) {
            return ((to_write_t){SWAP_UINT32(nb), DIR_SIZE});
        }
    }
    exit(84);
}

to_write_t add_to_test(char* arg, instruction_t *instruction, asm_t *assembly)
{
    to_write_t new;
    int type = get_param_type(arg);
    if (type == T_LAB) {
        add_label(arg + 2, assembly);
        new = (to_write_t){0, IND_SIZE};
    }
    if (type == T_REG)
        new = (to_write_t){my_getnbr(arg + 1), 1};
    if (type == T_DIR) {
        int nb = my_getnbr(arg + 1);
        return get_dir_type(instruction, nb);
    }
    if (type == T_IND) {
        int nb = my_getnbr(arg);
        new = (to_write_t){SWAP_UINT16(nb), IND_SIZE};
    }
    return new;
}

int main(int ac, char **av)
{
    FILE *fd;
    asm_t *assembly = malloc(sizeof(asm_t));
    if (ac != 2) {
        write(2, "Usage: ./asm file_name[.s]\n", 27);
        return 84;
    }
    if (!my_strcmp(av[1], "-h")) return print_help();
    init_struct(assembly);
    if (!(assembly->filepath = verify_file(av[1]))) return 84;
    fd = fopen(assembly->filepath, "r");
    if (fill_header(fd, assembly) == 84) return 84;
    fill_body(fd, assembly);
    create_file(av[1], assembly);
    return 0;
}
