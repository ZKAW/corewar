/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** byte
*/

#include <stdint.h>

uint32_t my_be32toh(uint32_t num)
{
    uint32_t res = 0;

    res |= (num & 0x000000FF) << 24u;
    res |= (num & 0x0000FF00) << 8u;
    res |= (num & 0x00FF0000) >> 8u;
    res |= (num & 0xFF000000) >> 24u;

    return res;
}

uint32_t my_htobe32(uint32_t num)
{
    uint32_t res = ((num & 0xFF) << 24) |
                    ((num & 0xFF00) << 8) |
                    ((num >> 8) & 0xFF00) |
                    ((num >> 24) & 0xFF);
    return res;
}
