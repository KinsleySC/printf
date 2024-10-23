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

#ifndef MY_HEADER_H
    #define MY_HEADER_H

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_put_float(double nb);
void my_put_long_double(long double nb);
void my_put_long_int(long int nb);
int my_put_hexa(unsigned long nb);
int my_put_hexa_mini(unsigned long nb);
void my_put_pointer(void *ptr);
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

#endif
