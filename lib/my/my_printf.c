/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** make_mini_printf
*/

#include "../../include/my.h"

void verif(const char *format, int *i, va_list list)
{
    if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
        my_put_nbr(va_arg(list, int));
    if (format[*i + 1] == 'f')
        my_put_float(va_arg(list, double));
    if (format[*i + 1] == 'l' && format[*i + 2] == 'f') {
        my_put_float(va_arg(list, double));
        *i += 1;
    }
    if (format[*i + 1] == 's')
        my_putstr(va_arg(list, char *));
    if (format[*i + 1] == 'c')
        my_putchar(va_arg(list, int));
    if (format[*i + 1] == '%')
        my_putchar('%');
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            verif(format, &i, list);
            i += 1;
        } else {
            my_putchar(format[i]);
        }
        i++;
    }
    va_end(list);
    return 0;
}
