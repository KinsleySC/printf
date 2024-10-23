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
    int base = 10;

    if (nb <= 7) {
        my_put_nbr(nb);
        return 0;
    }
    nb = nb / 8;
    total = rest;
    while (div != 0) {
        div = nb / 8;
        rest = nb % 8;
        nb = nb / 8;
        total += (rest * base);
        base = base * 10;
    }
    my_put_nbr(total);
    return 0;
}
