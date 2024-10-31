/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** make_mini_printf
*/

#include "include/my.h"

void verif(const char *format, int *i, va_list list)
{
    if (format[*i + 1] == 's')
        my_putstr(va_arg(list, char *));
    if (format[*i + 1] == 'c')
        my_putchar(va_arg(list, int));
    if (format[*i + 1] == 'x')
        my_put_hexa_mini(va_arg(list, int));
    if (format[*i + 1] == 'X')
        my_put_hexa(va_arg(list, int));
    if (format[*i + 1] == 'p')
        my_put_pointer(va_arg(list, void *));
    if (format[*i + 1] == 'o')
        my_octal(va_arg(list, int));
    if (format[*i + 1] == 'u')
        my_unsigned_int(va_arg(list, unsigned int));
    if (format[*i + 1] == 'f' || format[*i + 1] == 'F')
        my_put_float(va_arg(list, double));
    if (format[*i + 1] == 'l' && format[*i + 2] == 'f') {
        my_put_float(va_arg(list, double));
        *i += 1;
    }
}

void verif2(const char *format, int *i, va_list list)
{
    if (format[*i + 1] == '%')
        my_putchar('%');
    if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
        my_put_nbr(va_arg(list, int));
    if (format[*i + 1] == 'l' && format[*i + 2] == 'd') {
        my_put_long_int(va_arg(list, long int));
        *i += 1;
    }
    if (format[*i + 1] == 'L' && format[*i + 2] == 'f') {
        my_put_long_double(va_arg(list, long double));
        *i += 1;
    }
    if (format[*i + 1] == 'e' || format[*i + 1] == 'E') {
        if (format[*i + 1] == 'e')
            my_put_scientific(va_arg(list, double));
        else
            my_put_scientific_cap(va_arg(list, double));
    }
}

void verif3_h(const char *format, int *i, va_list list)
{
    if (format[*i + 1] == '#' && format[*i + 2] == 'x') {
        my_putstr("0x");
        my_put_hexa_mini(va_arg(list, int));
        *i += 1;
    }
    if (format[*i + 1] == '#' && format[*i + 2] == 'X') {
        my_putstr("0X");
        my_put_hexa(va_arg(list, int));
        *i += 1;
    }
    if (format[*i + 1] == '#' && format[*i + 2] == 'o') {
        my_putchar('0');
        my_octal(va_arg(list, int));
        *i += 1;
    }
}

void static verif4(const char *format, int *i, int *cnb, va_list list)
{
    int *stock;

    if (format[*i + 1] == '#' && format[*i + 2] == 'm') {
        my_putchar('0');
        *i += 2;
    }
    if (format[*i + 1] == 'm') {
        my_putstr("Success");
        *i += 1;
    }
    if (format[*i + 1] == 'n') {
        stock = va_arg(list, int *);
        *stock = *cnb;
    }
    if (format[*i + 1] == '#' && (format[*i + 2] == 'd'
    || format[*i + 2] == 'i')) {
        my_put_nbr(va_arg(list, int));
        *i += 2;
    }
}

void static verif5(const char *format, int *i, int *cnb, va_list list)
{
    int len = my_strlen(va_arg(list, char *));
    int *nbr;

    while (format[*i + 1] >= '0' && format[*i + 1] <= '9') {
        *nbr = (*nbr * 10) + (format[*i + 1] - '0');
        *nbr = *cnb;
        if (format[*i + 2] == 's') {
            my_space_width(*nbr, len);
            my_putstr(va_arg(list, char *));
            i += 2;
        }
        if (format[*i + 2] == 'd' || format[*i + 2] == 'i') {
            my_space_width(*nbr, va_arg(list, int));
            my_put_nbr(va_arg(list, int));
            i += 2;
        }
    }
}

void static plus_flag(const char *format, int *i, va_list list)
{
    int is_plus = 0;

    if (format[*i + 1] == '+') {
        is_plus = 1;
        *i += 1;
    }
    if (format[*i - 1] == '+' && format[*i + 1] == 'i' ||
    format[*i + 1] == '+' && format[*i + 1] == 'd')
        handle_int(format, i, is_plus, list);
    handle_double(format, i, is_plus, list);
    handle_long_double(format, i, is_plus, list);
    handle_long_int(format, i, is_plus, list);
    handle_scientific(format, i, is_plus, list);
}

void static group(const char *format, int *i, int *cnb, va_list list)
{
    verif(format, i, list);
    verif2(format, i, list);
    verif3_h(format, i, list);
    verif4(format, i, cnb, list);
    plus_flag(format, i, list);
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    int cnb = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            group(format, &i, &cnb, list);
            i++;
        } else {
            my_putchar(format[i]);
            cnb++;
        }
        i++;
    }
    va_end(list);
    return cnb;
}
