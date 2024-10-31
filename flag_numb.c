/*
** EPITECH PROJECT, 2024
** flag_number
** File description:
** flag percent number
*/

#include "include/my.h"

void static char_verif(const char *format, int *i, int nbr, va_list list)
{
    int len_c = va_arg(list, int);
    char *str = va_arg(list, char *);
    int len_s = my_strlen(str);

    if (format[*i + 1] == 's' && nbr) {
        if (nbr <= len_s) {
            my_putstr(str);
        } else {
            my_space_width(nbr, len_s);
            my_putstr(str);
        }
    }
    if (format[*i + 1] == 'c' && nbr) {
        if (nbr <= 1) {
            my_putchar(len_c);
        } else {
            my_space_width(nbr, 1);
            my_putchar(len_c);
        }
    }
}

void static int_verif2(const char *format, int *i, int nbr, va_list list)
{
    int count = va_arg(list, int);

    if (format[*i + 1] == 'o' && nbr) {
        if (nbr <= count) {
            my_octal(count);
        } else {
            my_space_width(nbr, count);
            my_octal(count);
        }
    }
    if ((format[*i + 1] == 'd' || format[*i + 1] == 'i') && nbr) {
        if (nbr <= count) {
            my_put_nbr(count);
        } else {
            my_space_width(nbr, count);
            my_put_nbr(count);
        }
    }
}

void float_verif(const char *format, int *i, int nbr, va_list list)
{
    double countf = va_arg(list, double);

    if (nbr <= (int)countf) {
        my_put_float(countf);
    } else {
        my_space_width((int)nbr, (int)countf);
        my_put_float(countf);
    }
}

void static verif5(const char *format, int *i, int nbr, va_list list)
{
    int len_s = 0;
    int len_c = 0;
    char *str;

    while (format[*i + 1] >= '0' && format[*i + 1] <= '9') {
        nbr = (nbr * 10) + (format[*i + 1] - '0');
        *i += 1;
    }
    if ((format[*i + 1] == 's' || format[*i + 1] == 'c') && nbr) {
        char_verif(format, i, nbr, list);
    }
}

void flag_numb(const char *format, int *i, int nbr, va_list list)
{
    verif5(format, i, nbr, list);
}
