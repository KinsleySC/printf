/*
** EPITECH PROJECT, 2024
** percentage_number
** File description:
** flag percentage number
*/

#include "include/my.h"

void my_space_width(int nb, int value)
{
    int res = 0;

    while (res < nb - value) {
        my_putchar(' ');
        res++;
    }
}
