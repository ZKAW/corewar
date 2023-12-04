/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** file
*/

#ifndef FILE_H_
    #define FILE_H_

    #include <stdio.h>

    typedef struct asm_s asm_t;

    typedef struct to_write {
        int value;
        int size;
    } to_write_t;

    typedef struct writer {
        int* size;
        int* value;
        int index;
        int max_len;
    } writer_t;

extern char *verify_file(char *file);
void create_file(char *filepath, asm_t *assembly);
int fill_header(FILE* fd, asm_t *assembly);
void write_head(int prog_size, int fd, asm_t *assembly);
writer_t* write_functions(int fd, asm_t* assembly);

#endif /* !FILE_H_ */
