/*
** EPITECH PROJECT, 2024
** my_int_len
** File description:
** count number in int
*/

#include "include/my.h"

int my_int_len(int nb)
{
    int len = 0;

    if (nb <= 0) {
        len++;
    }
    while (nb != 0) {
        nb /= 10;
        len++;
    }
    return len;
}
