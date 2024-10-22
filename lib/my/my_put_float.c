/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** rush2
*/

#include "my.h"

void my_put_float(double nb)
{
    int integer_part = (int)nb;
    double fraction_part;
    int precision;
    int fractional_part_as_int;

    my_put_nbr(integer_part);
    my_putchar('.');
    fraction_part = nb - integer_part;
    if (fraction_part < 0)
        fraction_part = -fraction_part;
    precision = 6;
    fraction_part *= 1000000;
    fractional_part_as_int = (int)(fraction_part + 0.5);
    my_put_nbr(fractional_part_as_int);
}
