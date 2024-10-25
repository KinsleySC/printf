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
    if (format[*i + 1] == 'E') {
        my_put_scientific_cap(va_arg(list, double));
    }
    if (format[*i + 1] == 'u') {
        my_unsigned_int(va_arg(list, unsigned int));
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

void static verif4(const char *format, int *i, int *char_c, va_list list)
{
    int *stock;

    if (format[*i + 1] == '#' && format[*i + 2] == 'm') {
        my_putchar('0');
        *i += 1;
    }
    if (format[*i + 1] == 'm') {
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

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    int char_c = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            verif(format, &i, list);
            verif2(format, &i, list);
            verif3_h(format, &i, list);
            verif4(format, &i, &char_c, list);
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
    int t;
    char l = 'r';
    char str[8];

    my_printf("Me : %n \n", &t);
    printf("Origin : %n \n", &t);
    my_printf("Me with #: %d \n", t);
    printf("Origin with # : %d \n\n", t);
    my_printf("Me with zero: %010d \n", 1755);
    printf("Origin with zero: %010d \n\n", 1755);
    my_printf("Me pred with blank: %19d \n", 1755);
    printf("Origin pred with blank: %19d \n\n", 1755);
    my_printf("Me without #: % \n", &t);
    printf("Origin without #: % \n", &t);
    my_printf("Me with #: %#d \n", 5);
    printf("Origin with #: %#d \n\n", 5);
    return 0;
}
