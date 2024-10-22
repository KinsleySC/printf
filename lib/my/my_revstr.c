/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int i;
    char t;
    int len = my_strlen(str);

    for (i = 0; i < len / 2; i++) {
        t = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = t;
    }
    return str;
}
