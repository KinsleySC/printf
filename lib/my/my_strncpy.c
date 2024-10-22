/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include <string.h>
#include <stdio.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i != n; i++) {
        if (src[i] != '\0') {
            dest[i] = src[i];
        } else {
            dest[i] = '\0';
        }
    }
    return dest;
}
