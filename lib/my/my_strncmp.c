/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i != n && (s1[i] == s2[i]) && (s1[i] !=
    '\0') && (s2[i] != '\0')) {
    i++;
    }
    if (i == n) {
        return 0;
    }
    return (s1[i] - s2[i]);
}
