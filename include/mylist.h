/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** header
*/

#ifndef MY_HEADER_H
    #define MY_HEADER_H

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

linked_list_t *my_params_to_list(int ac, char *const *av);

#endif
