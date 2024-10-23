/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "include/my.h"

int my_is_prime(int nb)
{
    if (nb < 2) {
        return 0;
    }
    for (int i = 2; i * i <= nb; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}