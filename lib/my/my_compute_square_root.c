/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "../../include/my.h"

int my_compute_square_root(int nb)
{
    int i;

    if (nb == 1) {
        return 1;
    }
    if (nb < 1) {
        return 0;
    }
    i = 2;
    while (i * i <= nb) {
        if (i * i == nb) {
            return i;
        }
        i++;
    }
    return 0;
}
