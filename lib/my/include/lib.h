/*
** EPITECH PROJECT, 2022
** lib.h
** File description:
** my lib
*/

#ifndef lib_h
    #define lib_h

    #define BASE_DEC "0123456789"
    #define BASE_HEX "0123456789ABCDEF"
    #define BASE_BIN "01"
    #define BASE_OCT "01234567"

int my_getnbr(char *str);
int my_intlen(int value);
char *my_itoa(int nbr);
char** string_split(char const * str, char* separator);
char *my_itoa_dest(char *dest, int nbr);
void my_putchar(char c);
void my_putstr(char const *str, int std);
char *my_revstr(char *str);
int my_strlen(char const *str);
int get_nbr_from(char *str, int i);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strtok(char *str, const char *delim);
char *my_strstr(char *str, char const *to_find);
char *my_strdup(char const *src);
int my_atoi(char const *str);
int tablen(char **tab);
int any_tablen(void **tab);
char *my_strchr(char const *str, char c);
int my_putnbr(int nb);
int my_pow(int nb, int pow);
int is_whitespace(char *str);
char *my_strncpy(char *dest, char const *src, int n);
char **my_str_to_word_array(char *str, char delim);
int my_strncmp(const char *s1, const char *s2, int n);
char *my_strcpy(char *dest, char const *src);
int is_c_space(char c);
int is_alphanum(char c);
int is_str_alphanum(char *str);
int is_number(char *str);
int count_char(char *str, char c);
char *my_strndup(char const *src, int n);
char *my_strcat_c(char *str, char c);
char *clean_str(char* str);
void print_array(char** array);
char** array_remove(int position, char** array);
char** array_append(char** array, char* const str);
void arraydup(char** dest, char** src);
char *str_append(char *str, const char *to_append);
char* merge_array(char** array);
void free_arr(char** arr);
void replace_arr_at_index(char ***main_arr_ptr, char **sub_arr, int index);
void insert_arr_at_index(char ***main_arr_ptr, char **sub_arr, int index);
int is_alpha(char c);
int is_str_alpha(char *str);
char *my_strncat( char* dest , char* const src, int nb);
int is_file_exist(char *filepath);
int str_endswith(char const *str, char const *end);
int is_positive_number(char const *str);
char *convert_base(char* nbr, char* base_from, char* base_to);
char *itoa_base(int nbr, char* base);
char *char_to_hex(char c);
void *my_memset(void *s, int c, int size);

#endif
