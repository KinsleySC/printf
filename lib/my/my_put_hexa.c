/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "../../include/my.h"

int my_put_hexa(int nbr)
{
    int x = 1;
    int result;
    int temp;
    char const *base = "0123456789ABCDEF";

    temp = my_strlen(base);
    if (nbr < 0) {
        my_putchar('-');
        nbr = -(nbr);
    }
    while ((nbr / x) >= temp) {
        x = x * temp;
    }
    while (x > 0) {
        result = (nbr / x) % temp;
        my_putchar(base[result]);
        x = x / temp;
    }
    return 0;
}
