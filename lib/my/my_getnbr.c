/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** function
*/

#include <limits.h>

int get_sign(const char *str, int *i)
{
    int sign = 1;

    while (str[*i] != '\0' && (str[*i] == '+'
    || str[*i] == '-' || str[*i] == ' ')) {
        if (str[*i] == '-') {
            sign *= -1;
        }
        (*i)++;
    }
    return sign;
}

int is_overflow(int n, int next_digit, int sign)
{
    if (sign == 1) {
        return (n > (INT_MAX / 10) || (n == (INT_MAX /
        10) && next_digit > (INT_MAX % 10)));
    } else {
        return (n > (INT_MAX / 10) || (n == (INT_MAX /
        10) && next_digit > (-(INT_MIN % 10))));
    }
}

int my_getnbr(const char *str)
{
    int n = 0;
    int i = 0;
    int sign = get_sign(str, &i);

    while (str[i] >= '0' && str[i] <= '9') {
        if (is_overflow(n, str[i] - '0', sign)) {
            return 0;
        }
        n = n * 10 + (str[i] - '0');
        i++;
    }
    return n * sign;
}
