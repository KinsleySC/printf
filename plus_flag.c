/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "include/my.h"

void handle_plus_flag(const char *format, int *i, int *plus_flag)
{
    if (format[*i + 1] == '+') {
        *plus_flag = 1;
        *i += 1;
    }
}
