/*
** EPITECH PROJECT, 2024
** test
** File description:
** testo
*/

#include "include/my.h"

int my_octal(int nb)
{
    int total = 0;
    int div = nb / 8;
    int rest = nb % 8;
    int base = 1;

    if (nb <= 7) {
        my_put_nbr(nb);
        return nb;
    }
    total = rest;
    nb = div;
    base = 10;
    while (nb != 0) {
        rest = nb % 8;
        total += (rest * base);
        nb = nb / 8;
        base *= 10;
    }
    my_put_nbr(total);
    return total;
}
