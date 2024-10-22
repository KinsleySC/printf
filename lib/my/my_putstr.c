/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    for (int i = 0; *str != '\0'; i++) {
        my_putchar(*str);
        str++;
    }
    return 0;
}
