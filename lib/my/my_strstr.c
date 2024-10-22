/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include <stddef.h>
#include <stdio.h>

char *my_strstr(char *str, char const *to_find)
{
    int i;
    int j;

    if (*to_find == '\0') {
        return str;
    }
    for (i = 0; str[i] != '\0'; i++) {
        j = 0;
        while (str[i + j] == to_find[j] && to_find[j] != '\0') {
            j++;
        }
        if (to_find[j] == '\0') {
            return &str[i];
        }
    }
    return NULL;
}
