/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "include/my.h"

void leading_zeros(int fractional_part_as_int)
{
    if (fractional_part_as_int < 100000) {
        my_putchar('0');
    }
    if (fractional_part_as_int < 10000) {
        my_putchar('0');
    }
    if (fractional_part_as_int < 1000) {
        my_putchar('0');
    }
    if (fractional_part_as_int < 100) {
        my_putchar('0');
    }
    if (fractional_part_as_int < 10) {
        my_putchar('0');
    }
}

void my_put_long_double(long double nb)
{
    int integer_part = (int)nb;
    long double fraction_part = nb - integer_part;
    int precision = 6;
    int fractional_part_as_int;

    if (fraction_part < 0) {
        fraction_part = -fraction_part;
    }
    my_put_nbr(integer_part);
    my_putchar('.');
    fraction_part *= 1000000;
    fractional_part_as_int = (int)(fraction_part + 0.5);
    leading_zeros(fractional_part_as_int);
    my_put_nbr(fractional_part_as_int);
}
