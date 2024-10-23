/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "include/my.h"

int my_put_hexa(unsigned long nb)
{
    unsigned long x = 1;
    unsigned long result;
    unsigned long temp;
    char const *base = "0123456789ABCDEF";

    temp = my_strlen(base);
    while ((nb / x) >= temp) {
        x *= temp;
    }
    while (x > 0) {
        result = (nb / x) % temp;
        my_putchar(base[result]);
        x /= temp;
    }
    return 0;
}
