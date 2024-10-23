/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "include/my.h"

int is_capitalize_position(char *str, int i)
{
    return (i == 0 || str[i - 1] == ' '
    || str[i - 1] == '-' || str[i - 1] == '+');
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_capitalize_position(str, i)
        && str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        if (!is_capitalize_position(str, i)
        && str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return str;
}
