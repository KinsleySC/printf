/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "../../include/my.h"

int my_str_isupper(char const *str)
{
    if (str == NULL) {
        return -1;
    }
    while (*str) {
        if (!(*str >= 'A' && *str <= 'Z')) {
            return 0;
        }
        str++;
    }
    return 1;
}
