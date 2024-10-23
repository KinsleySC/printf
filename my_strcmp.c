/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; (s1[i] == s2[i])
    && (s1[i] != '\0') && (s2[i] != '\0'); i++);
    return (s1[i] - s2[i]);
}
