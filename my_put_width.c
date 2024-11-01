/*
** EPITECH PROJECT, 2024
** percentage_number
** File description:
** flag percentage number
*/

#include "include/my.h"

int my_put_width(char c, int nb, int value)
{
    int res = 0;

    while (res < nb - value) {
        my_putchar(c);
        res++;
    }
    return 0;
}
