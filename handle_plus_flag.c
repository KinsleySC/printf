/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "include/my.h"

void handle_int(const char *format, int *i, int is_plus, va_list list)
{
    int num;

    if (format[*i + 1] == 'd' || format[*i + 1] == 'i') {
        num = va_arg(list, int);
        if (is_plus && num >= 0)
            my_putchar('+');
        my_put_nbr(num);
    }
}

void handle_long_double(const char *format, int *i,
    int plus_flag, va_list list)
{
    long double n;

    if (format[*i + 1] == 'L' && format[*i + 2] == 'f') {
        n = va_arg(list, long double);
        if (plus_flag && n >= 0)
            my_putchar('+');
        my_put_long_double(n);
        *i += 1;
    }
}

void handle_long_int(const char *format, int *i, int plus_flag, va_list list)
{
    long int nb;

    if (format[*i + 1] == 'l' && format[*i + 2] == 'd') {
        nb = va_arg(list, long int);
        if (plus_flag && nb >= 0)
            my_putchar('+');
        my_put_long_int(nb);
        *i += 1;
    }
}

void handle_double(const char *format, int *i, int plus_flag, va_list list)
{
    double number;

    if (format[*i + 1] == 'f' || format[*i + 1] == 'F' ||
        (format[*i + 1] == 'l' && format[*i + 2] == 'f')) {
        number = va_arg(list, double);
        if (plus_flag && number >= 0)
            my_putchar('+');
        my_put_float(number);
        if (format[*i + 1] == 'l' && format[*i + 2] == 'f')
            *i += 1;
    }
}

void handle_scientific(const char *format, int *i,
    int plus_flag, va_list list)
{
    double nbr;

    if (format[*i + 1] == 'e' || format[*i + 1] == 'E') {
        nbr = va_arg(list, double);
        if (plus_flag && nbr >= 0)
            my_putchar('+');
        if (format[*i + 1] == 'e')
            my_put_scientific(nbr);
        else
            my_put_scientific_cap(nbr);
    }
}
