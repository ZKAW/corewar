/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** convert_base
*/

#include "lib.h"
#include <stdlib.h>

char *itoa_base(int nbr, char* base)
{
    int len = my_strlen(base);
    int nbr_len = 0;
    int tmp = nbr;
    if (nbr == 0) return my_strdup("0");
    while (tmp > 0) {
        tmp /= len;
        nbr_len++;
    }
    char* result = malloc(sizeof(char) * (nbr_len + 1));
    int index = 0;
    while (nbr > 0) {
        int remainder = nbr % len;
        result[index++] = base[remainder];
        nbr /= len;
    }
    if (index == 0) result[index++] = base[0];
    result[index] = '\0';
    result = my_revstr(result);
    return result;
}

static int convert_to_decimal(char digit, char* base_from)
{
    int len = my_strlen(base_from);
    int index = 0;
    while (index < len) {
        if (digit == base_from[index]) {
            return index;
        }
        index++;
    }
    return -1;
}

char *convert_base(char* nbr, char* base_from, char* base_to)
{
    if (!nbr || !base_from || !base_to) return NULL;

    int len = my_strlen(base_from);
    int nbr_len = my_strlen(nbr);
    int decimal = 0;
    int power = 1;

    for (int i = nbr_len - 1; i >= 0; i--) {
        int digit_value = convert_to_decimal(nbr[i], base_from);
        if (digit_value == -1) {
            return NULL;
        }
        decimal += digit_value * power;
        power *= len;
    }

    return itoa_base(decimal, base_to);
}

char *char_to_hex(char c)
{
    char *hex = malloc(sizeof(char) * 3);
    hex[0] = '0';
    hex[1] = '0';
    hex[2] = '\0';
    if (!c) {
        return hex;
    }

    hex[0] = BASE_HEX[(unsigned char)c >> 4];
    hex[1] = BASE_HEX[(unsigned char)c & 0xF];
    return hex;
}
