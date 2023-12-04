/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include <stdint.h>

uint32_t my_be32toh(uint32_t num);
uint32_t my_htobe32(uint32_t num);
void exit_with_error(char const *message);
void safe_free(void *ptr);

#endif /* !UTILS_H_ */
