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
    if (format[*i + 1] == '%')
        my_putchar('%');
}

void verif2(const char *format, int *i, va_list list)
{
    int plus_flag = 0;

    handle_plus_flag(format, i, &plus_flag);
    handle_int(format, i, plus_flag, list);
    handle_double(format, i, plus_flag, list);
    handle_long_double(format, i, plus_flag, list);
    handle_long_int(format, i, plus_flag, list);
    handle_scientific(format, i, plus_flag, list);
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

void static verif4(const char *format, int *i, int *char_c, va_list list)
{
    int *stock;

    if (format[*i + 1] == '#' && format[*i + 2] == 'm') {
        my_putchar('0');
        *i += 1;
    } else if (format[*i + 1] == 'm') {
        my_putstr("Success");
    }
    if (format[*i + 1] == 'n') {
        stock = va_arg(list, int *);
        *char_c = *stock;
    }
    if (format[*i + 1] == '#') {
        if (format[*i + 2] == 'd' || format[*i + 2] == 'i') {
            my_put_nbr(va_arg(list, int));
        }
    }
}

void static group(const char *format, int *i, int *cnb, va_list list)
{
    verif(format, i, list);
    verif2(format, i, list);
    verif3_h(format, i, list);
    verif4(format, i, cnb, list);
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
