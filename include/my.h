/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** header
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <math.h>

#ifndef MY_HEADER_H
    #define MY_HEADER_H

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_put_float(double nb);
void my_put_long_double(long double nb);
void leading_zeros(int fractional_part_as_int);
void my_put_long_int(long int nb);
int my_put_hexa(unsigned long nb);
int my_put_hexa_mini(unsigned long nb);
void my_put_pointer(void *ptr);
void my_put_g(double nb);
void my_put_g_cap(double nb);
void my_put_scientific(double nb);
void my_put_scientific_cap(double nb);
void print_fraction_part(double fraction_part);
void print_fraction_part_cap(double fraction_part);
void print_exponent(int exponent);
void print_exponent_cap(int exponent);
void calculate_exponent(double *nb, int *exponent);
void calculate_exponent_cap(double *nb, int *exponent);
void case_zero(double nb);
void case_zero_cap(double nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int mini_printf(const char *format, ...);
int my_octal(int nb);
int my_printf(const char *format, ...);
void my_unsigned_int(unsigned int nb);
void handle_int(const char *format, int *i, int is_plus, va_list list);
void handle_long_double(const char *format, int *i,
    int plus_flag, va_list list);
void handle_long_int(const char *format, int *i, int plus_flag, va_list list);
void handle_double(const char *format, int *i, int plus_flag, va_list list);
void handle_scientific(const char *format, int *i,
    int plus_flag, va_list list);
int my_put_width(char c, int nb, int value);
int my_put_g_normalize(double *nb);
void normalize2(double *nb, int *exponent);
void my_put_g_sign(double *nb);
void flag_numb(const char *format, char choose, int *i, va_list lis);
int my_int_len(int nb);
void handle_plus_flag(const char *format, int *i, int *plus_flag);

#endif
