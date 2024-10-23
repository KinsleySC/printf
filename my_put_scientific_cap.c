/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "include/my.h"

void print_fraction_part_cap(double fraction_part)
{
    int fractional_part_as_int;

    fraction_part = (fraction_part < 0 ? - fraction_part : fraction_part);
    fraction_part *= 1000000;
    fractional_part_as_int = (int)(fraction_part + 0.5);
    for (int i = 100000; i > 1; i /= 10) {
        if (fractional_part_as_int < i) {
            my_putchar('0');
        }
    }
    my_put_nbr(fractional_part_as_int);
}

void print_exponent_cap(int exponent)
{
    my_putchar('E');
    if (exponent >= 0) {
        my_putchar('+');
    } else {
        my_putchar('-');
        exponent = -exponent;
    }
    if (exponent < 10) {
        my_putchar('0');
    }
    my_put_nbr(exponent);
}

void calculate_exponent_cap(double *nb, int *exponent)
{
    while (*nb >= 10 || *nb <= -10) {
        *nb /= 10;
        (*exponent)++;
    }
    while (*nb < 1 && *nb > -1) {
        *nb *= 10;
        (*exponent)--;
    }
}

void case_zero_cap(double nb)
{
    if (nb == 0.0) {
        my_putchar('0');
        my_putchar('.');
        my_put_nbr(0);
        my_putchar('E');
        my_putchar('+');
        my_putchar('0');
        my_putchar('0');
    }
}

void my_put_scientific_cap(double nb)
{
    int integer_part;
    double fraction_part;
    int exponent = 0;

    case_zero_cap(nb);
    if (nb == 0.0) {
        return;
    }
    calculate_exponent_cap(&nb, &exponent);
    integer_part = (int)nb;
    fraction_part = nb - integer_part;
    my_put_nbr(integer_part);
    my_putchar('.');
    print_fraction_part_cap(fraction_part);
    print_exponent_cap(exponent);
}
