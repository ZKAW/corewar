/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_type
*/

#include "asm.h"

int get_register(char* test)
{
    return (test[0] == 'r' && my_strlen(test) == 2 &&
    test[1] >= '0' && test[1] <= '9') ? 1 : 0;
}

int get_direct(char* test)
{
    if (test[0] == DIRECT_CHAR && test[1] == LABEL_CHAR)
        return 2;
    if (test[0] == DIRECT_CHAR && test[1] >= '0' && test[1] <= '9')
        return 1;
    return 0;
}

int get_indirect(char* test)
{
    if (test[0] == LABEL_CHAR)
        return 1;
    if (test[0] >= '0' && test[0] <= '9')
        return 1;
    return 0;
}

int get_param_type(char* test)
{
    if (get_register(test))
        return T_REG;
    if (get_direct(test) == 1)
        return T_DIR;
    if (get_direct(test) == 2)
        return T_LAB;
    if (get_indirect(test))
        return T_IND;
    return 0;
}

int get_arg_type(char* arg, instruction_t *instruction)
{
    if (arg[0] == 'r')
        return T_REG;
    if (arg[0] == DIRECT_CHAR)
        return T_DIR;
    if (arg[0] == LABEL_CHAR)
        return T_IND;
    return T_IND;
}
