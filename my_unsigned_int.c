/*
** EPITECH PROJECT, 2024
** my_unsigned_int
** File description:
** unsigned int
*/

#include "include/my.h"

void my_unsigned_int(unsigned int nb)
{
    if (nb >= 10) {
        my_unsigned_int(nb / 10);
    }
    my_putchar((nb % 10) + '0');
}
