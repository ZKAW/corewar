/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** arguments
*/

#ifndef ARGUMENTS_H_
    #define ARGUMENTS_H_

typedef struct champion_arg_s {
    char *filename;
    int prog_number;
    int address;
} champion_arg_t;

typedef struct args_s {
    long nbr_cycle_dump;
    int nb_champions;
    champion_arg_t **champions;
} args_t;

// Init
champion_arg_t *init_champion_arg(void);
args_t *init_args(void);

// Parser
void *add_empty_champion(args_t *args);
args_t *parse_args(int ac, char **av);

// Parser modules
void handle_dump_arg(char **av, int i, args_t *args);
void handle_prog_number_arg(char **av, int i, args_t *args);
void handle_address_arg(char **av, int i, args_t *args);

#endif /* !ARGUMENTS_H_ */
