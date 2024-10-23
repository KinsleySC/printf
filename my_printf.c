/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** make_mini_printf
*/

#include "include/my.h"

void verif(const char *format, int *i, va_list list)
{
    if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
        my_put_nbr(va_arg(list, int));
    if (format[*i + 1] == 'f' || format[*i + 1] == 'F')
        my_put_float(va_arg(list, double));
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
    if (format[*i + 1] == 'e')
        my_put_scientific(va_arg(list, double));
    if (format[*i + 1] == '%')
        my_putchar('%');
}

void verif2(const char *format, int *i, va_list list)
{
    if (format[*i + 1] == 'l' && format[*i + 2] == 'f') {
        my_put_float(va_arg(list, double));
        *i += 1;
    }
    if (format[*i + 1] == 'L' && format[*i + 2] == 'f') {
        my_put_long_double(va_arg(list, long double));
        *i += 1;
    }
    if (format[*i + 1] == 'l' && format[*i + 2] == 'd') {
        my_put_long_int(va_arg(list, long int));
        *i += 1;
    }
    if (format[*i + 1] == 'E')
        my_put_scientific_cap(va_arg(list, double));
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            verif(format, &i, list);
            verif2(format, &i, list);
            i += 1;
        } else {
            my_putchar(format[i]);
        }
        i++;
    }
    va_end(list);
    return 0;
}

int main(void)
{
    double e = 3542;

    printf("%E\n", e);
    my_printf("%E\n", e);
}