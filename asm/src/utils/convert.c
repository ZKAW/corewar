/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** convert
*/

int convert_endian(int nb)
{
    return (((nb >> 24) & 0xff) | ((nb << 8) & 0xff0000) |
    ((nb >> 8) & 0xff00) | ((nb << 24) & 0xff000000));
}
