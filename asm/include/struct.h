/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include "op.h"
    #include "file.h"

    #include <stdlib.h>

    typedef struct writer writer_t;

    typedef struct instruction_s {
        op_t op;
        char **params;
        char* name;
        struct instruction_s *next;
    } instruction_t;

    typedef struct function {
        char *label;
        instruction_t *statements;
        int index;
        struct function *next;
    } function_t;

    typedef struct label {
        char *name;
        int index;
        struct label *next;
    } label_t;

    typedef struct asm_s {
        char **content;
        char *name;
        char *comment;
        char *filepath;
        int fd;
        int size;
        int line;
        struct header_s *header;
        function_t *functions;
        instruction_t *instruc;
        label_t *labels;
        writer_t *writer;
    } asm_t;


#endif /* !STRUCT_H_ */
