/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include <stdio.h>

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
