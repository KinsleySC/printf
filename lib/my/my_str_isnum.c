/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "../../include/my.h"

int my_str_isnum(const char *str)
{
    if (str == NULL || *str == '\0') {
        return 0;
    }
    while (*str) {
        if (!(*str >= '0' && *str <= '9')) {
            return 0;
        }
        str++;
    }
    return 1;
}
