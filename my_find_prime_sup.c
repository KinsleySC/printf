/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "include/my.h"

int my_find_prime_sup(int nb)
{
    if (nb < 2) {
        return 2;
    }
    while (!my_is_prime(nb)) {
        nb++;
    }
    return nb;
}
