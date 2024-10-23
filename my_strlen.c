/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "include/my.h"

int my_strlen(char const *str)
{
    int c = 0;

    for (int i = 0; *str != '\0'; i++) {
        c++;
        str++;
    }
    return c;
}
