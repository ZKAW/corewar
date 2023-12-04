/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** error
*/

#include "corewar.h"

bool is_valid_address(int address)
{
    return (address >= 0 && address < MEM_SIZE);
}
