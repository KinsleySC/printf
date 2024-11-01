/*
** EPITECH PROJECT, 2024
** Flag_numb
** File description:
** Print flag number of printf
*/

#include "include/my.h"

void static verif_string(char convert, int nbr, va_list list)
{
    char *str = va_arg(list, char *);
    int len_s = my_strlen(str);

    if (nbr <= len_s) {
        my_putstr(str);
    } else {
        my_put_width(convert, nbr, len_s);
        my_putstr(str);
    }
}

void static verif_char(char convert, int nbr, va_list list)
{
    if (nbr > 1) {
        my_put_width(convert, nbr, 1);
    }
    my_putchar(va_arg(list, int));
}

void static int_verif(char choose, int nbr, char convert, va_list list)
{
    int value = va_arg(list, int);
    int len_v = my_int_len(value);

    if (nbr > len_v) {
        my_put_width(convert, nbr, len_v);
    }
    if (choose == 'd' || choose == 'i') {
        my_put_nbr(value);
    } else if (choose == 'o') {
        my_octal(value);
    }
}

void verif_zero(const char *format, int *i, char *convert)
{
    if (format[*i + 1] == 's' || format[*i + 1] == 'c') {
        *convert = ' ';
    }
}

void flag_numb(const char *format, char choose, int *i, va_list list)
{
    int nbr = 0;
    char convert = ' ';

    if (format[*i + 1] == '0') {
        convert = '0';
        *i += 1;
    }
    while (format[*i + 1] >= '0' && format[*i + 1] <= '9') {
        nbr = (nbr * 10) + (format[*i + 1] - '0');
        *i += 1;
    }
    verif_zero(format, i, &convert);
    choose = format[*i + 1];
    if (choose == 's') {
        verif_string(convert, nbr, list);
    } else if (choose == 'c') {
        verif_char(convert, nbr, list);
    } else {
        int_verif(choose, nbr, convert, list);
    }
}
