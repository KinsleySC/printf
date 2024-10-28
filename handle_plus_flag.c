/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "include/my.h"

void handle_int(const char *format, int *i, va_list list)
{
    if (format[*i + 1] == 'd' || format[*i + 1] == 'i') {
        my_put_nbr(va_arg(list, int));
    }
    if (format[*i + 1] == '+' || format[*i + 2] == 'd' ||
    format[*i + 1] == '+' || format[*i + 2] == 'i') {
        my_putchar('+');
        my_put_nbr(va_arg(list, int));
        *i += 1;
    }
}

void handle_long_double(const char *format, int *i, va_list list)
{
    if (format[*i + 1] == 'L' && format[*i + 2] == 'f') {
        my_put_long_double(va_arg(list, long double));
        *i += 1;
    }
    if (format[*i + 1] == '+' && format[*i + 2] == 'L'
    || format[*i + 3] == 'f') {
        my_putchar('+');
        my_put_long_double(va_arg(list, long double));
        *i += 2;
    }
}

void handle_long_int(const char *format, int *i, va_list list)
{
    if (format[*i + 1] == 'l' && format[*i + 2] == 'd') {
        my_put_long_int(va_arg(list, long int));
        *i += 1;
    }
    if (format[*i + 1] == '+' && format[*i + 2] == 'l'
    || format[*i + 3] == 'd') {
        my_putchar('+');
        my_put_long_int(va_arg(list, long int));
        *i += 2;
    }
}

void handle_float(const char *format, int *i, va_list list)
{
    if (format[*i + 1] == 'f' || format[*i + 1] == 'F') {
        my_put_float(va_arg(list, double));
    }
    if (format[*i + 1] == '+' && format[*i + 2] == 'f'
    || format[*i + 1] == '+' && format[*i + 2] == 'F') {
        my_putchar('+');
        my_put_float(va_arg(list, double));
        *i += 2;
    }
}

void handle_scientific(const char *format, int *i, va_list list)
{
    if (format[*i + 1] == 'e' || format[*i + 1] == 'E') {
        if (format[*i + 1] == 'e')
            my_put_scientific(va_arg(list, double));
        else
            my_put_scientific_cap(va_arg(list, double));
    }
    if (format[*i + 1] == '+' && format[*i + 2] == 'e'
    || format[*i + 2] == 'E') {
        if (format[*i + 1] == 'e') {
            my_putchar('+');
            my_put_scientific(va_arg(list, double));
            *i += 1;
        } else {
            my_putchar('+');
            my_put_scientific_cap(va_arg(list, double));
            *i += 1;
        }
    }
}
