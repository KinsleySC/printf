/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "../../include/my.h"

int my_put_hexa(int nb)
{
    int x = 1;
    int result;
    int temp;
    char const *base = "0123456789ABCDEF";

    temp = my_strlen(base);
    if (nb < 0) {
        my_putchar('-');
        nb = -(nb);
    }
    while ((nb / x) >= temp) {
        x = x * temp;
    }
    while (x > 0) {
        result = (nb / x) % temp;
        my_putchar(base[result]);
        x = x / temp;
    }
    return 0;
}
