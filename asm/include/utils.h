/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include <stdlib.h>

    typedef struct linked_list_s {
        void *data;
        struct linked_list_s *next;
    } linked_list_t;

int convert_endian(int nb);
extern int print_help(void);
char **tokenize_string(char *input, char *sep);
void dump_asm(asm_t* assembly);
int get_param_type(char* test);
int error_header(char* line, char* trimmed_line, asm_t* assembly, int line_nb);

#endif /* !UTILS_H_ */
