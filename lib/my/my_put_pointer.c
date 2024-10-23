/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include "../../include/my.h"

void my_put_pointer(void *ptr)
{
    unsigned long address = (unsigned long)ptr;

    my_putstr("0x");
    my_put_hexa_mini(address);
}
