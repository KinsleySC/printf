/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include <stddef.h>

int my_str_islower(char const *str)
{
    if (str == NULL) {
        return 1;
    }
    while (*str) {
        if (!(*str >= 'a' && *str <= 'z')) {
            return 0;
        }
        str++;
    }
    return 1;
}
