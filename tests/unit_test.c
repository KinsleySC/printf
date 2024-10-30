/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_stdout(void) {
    cr_redirect_stdout();
}

Test(my_printf, string_specifier, .init = redirect_all_stdout) {
    my_printf("%s", "Hello, world!");
    cr_assert_stdout_eq_str("Hello, world!");
}

Test(my_printf, char_specifier, .init = redirect_all_stdout) {
    my_printf("%c", 'A');
    cr_assert_stdout_eq_str("A");
}

Test(my_printf, hex_specifiers, .init = redirect_all_stdout) {
    my_printf("%x %X", 255, 255);
    cr_assert_stdout_eq_str("ff FF");
}

Test(my_printf, pointer_specifier, .init = redirect_all_stdout) {
    int a = 10;
    my_printf("%p", &a);
}

Test(my_printf, octal_specifier, .init = redirect_all_stdout) {
    my_printf("%o", 64);
    cr_assert_stdout_eq_str("100");
}

Test(my_printf, decimal_specifiers, .init = redirect_all_stdout) {
    my_printf("%d %i", 123, -456);
    cr_assert_stdout_eq_str("123 -456");
}

Test(my_printf, float_specifier, .init = redirect_all_stdout) {
    my_printf("%f", 3.14159);
    cr_assert_stdout_eq_str("3.141590");
}

Test(my_printf, hash_specifiers, .init = redirect_all_stdout) {
    my_printf("%#x %#X %#o", 255, 255, 8);
    cr_assert_stdout_eq_str("0xff 0XFF 010");
}

Test(my_compute_power_rec, test_power) {
    cr_assert_eq(my_compute_power_rec(2, 3), 8);
    cr_assert_eq(my_compute_power_rec(3, 3), 27);
    cr_assert_eq(my_compute_power_rec(5, 2), 25);
    cr_assert_eq(my_compute_power_rec(10, 0), 1);
}

Test(my_compute_square_root, test_square_root) {
    cr_assert_eq(my_compute_square_root(4), 2);
    cr_assert_eq(my_compute_square_root(9), 3);
    cr_assert_eq(my_compute_square_root(16), 4);
    cr_assert_eq(my_compute_square_root(25), 5);
}

Test(my_find_prime_sup, test_prime_sup) {
    cr_assert_eq(my_find_prime_sup(4), 5);
    cr_assert_eq(my_find_prime_sup(9), 11);
    cr_assert_eq(my_find_prime_sup(16), 17);
    cr_assert_eq(my_find_prime_sup(25), 29);
}

Test(my_is_prime, test_is_prime) {
    cr_assert_eq(my_is_prime(4), 0);
    cr_assert_eq(my_is_prime(9), 0);
    cr_assert_eq(my_is_prime(16), 0);
    cr_assert_eq(my_is_prime(25), 0);
    cr_assert_eq(my_is_prime(5), 1);
    cr_assert_eq(my_is_prime(11), 1);
    cr_assert_eq(my_is_prime(17), 1);
    cr_assert_eq(my_is_prime(29), 1);
}

Test(my_getnbr, test_getnbr) {
    cr_assert_eq(my_getnbr("123"), 123);
    cr_assert_eq(my_getnbr("-123"), -123);
    cr_assert_eq(my_getnbr("0"), 0);
    cr_assert_eq(my_getnbr("2147483647"), 2147483647);
    cr_assert_eq(my_getnbr("-2147483648"), -2147483648);
}

Test(my_isneg, test_positive, .init = redirect_all_stdout)
{
    my_isneg(1);
    cr_assert_stdout_eq_str("P", "Expected 'P' for positive input");
}

Test(my_isneg, test_negative, .init = redirect_all_stdout)
{
    my_isneg(-1);
    cr_assert_stdout_eq_str("N", "Expected 'N' for negative input");
}

Test(my_isneg, test_zero, .init = redirect_all_stdout)
{
    my_isneg(0);
    cr_assert_stdout_eq_str("P", "Expected 'P' for zero input");
}

Test(my_put_long_double, test_put_long_double, .init = redirect_all_stdout) {
    my_put_long_double(3.14159);
    cr_assert_stdout_eq_str("3.141590");
}

Test(my_put_long_int, test_put_long_int, .init = redirect_all_stdout) {
    my_put_long_int(1234567890);
    cr_assert_stdout_eq_str("1234567890");
}

Test(my_put_scientific, test_put_scientific, .init = redirect_all_stdout) {
    my_put_scientific(3.14159);
    cr_assert_stdout_eq_str("3.141590e+00");
}

Test(my_put_scientific_cap, test_put_scientific_cap, .init = redirect_all_stdout) {
    my_put_scientific_cap(3.14159);
    cr_assert_stdout_eq_str("3.141590E+00");
}

Test(my_revstr, test_revstr) {
    char str[] = "Hello, world!";
    my_revstr(str);
    cr_assert_str_eq(str, "!dlrow ,olleH");
}

Test(my_strcapitalize, test_strcapitalize) {
    char str[] = "hello, world!";
    my_strcapitalize(str);
    cr_assert_str_eq(str, "Hello, World!");
}

Test(my_strcat, test_strcat) {
    char dest[50] = "Hello, ";
    char src[] = "world!";
    my_strcat(dest, src);
    cr_assert_str_eq(dest, "Hello, world!");
}

Test(my_strcmp, test_strcmp) {
    cr_assert_eq(my_strcmp("Hello, world!", "Hello, world!"), 0);
    cr_assert_eq(my_strcmp("Hello, world!", "Hello, world"), 33);
    cr_assert_eq(my_strcmp("Hello, world", "Hello, world!"), -33);
}

Test(my_strcpy, test_strcpy) {
    char dest[50];
    my_strcpy(dest, "Hello, world!");
    cr_assert_str_eq(dest, "Hello, world!");
}

Test(my_str_isalpha, test_str_isalpha) {
    cr_assert_eq(my_str_isalpha("Hello, world!"), 0);
    cr_assert_eq(my_str_isalpha("Hello"), 1);
    cr_assert_eq(my_str_isalpha("world"), 1);
}

Test(my_str_islower, test_str_islower) {
    cr_assert_eq(my_str_islower("Hello, world!"), 0);
    cr_assert_eq(my_str_islower("hello"), 1);
    cr_assert_eq(my_str_islower("world"), 1);
}

Test(my_str_isnum, test_str_isnum) {
    cr_assert_eq(my_str_isnum("Hello, world!"), 0);
    cr_assert_eq(my_str_isnum("123"), 1);
    cr_assert_eq(my_str_isnum("456"), 1);
}

Test(my_strlowcase, test_strlowcase) {
    char str[] = "Hello, World!";
    my_strlowcase(str);
    cr_assert_str_eq(str, "hello, world!");
}

Test(my_strncat, test_strncat) {
    char dest[50] = "Hello, ";
    char src[] = "world";
    my_strncat(dest, src, 6);
    cr_assert_str_eq(dest, "Hello, world");
}

Test(my_strncmp, test_strncmp) {
    cr_assert_eq(my_strncmp("Hello, world!", "Hello, world!", 13), 0);
    cr_assert_eq(my_strncmp("Hello, world!", "Hello, world", 13), 33);
    cr_assert_eq(my_strncmp("Hello, world", "Hello, world!", 13), -33);
}

Test(my_strncpy, test_strncpy) {
    char dest[50];
    my_strncpy(dest, "Hello, world!", 13);
    cr_assert_str_eq(dest, "Hello, world!");
}

Test(my_strupcase, test_strupcase) {
    char str[] = "Hello, World!";
    my_strupcase(str);
    cr_assert_str_eq(str, "HELLO, WORLD!");
}

Test(my_unsigned_int, test_unsigned_int, .init = redirect_all_stdout) {
    my_unsigned_int(123);
    cr_assert_stdout_eq_str("123");
}

Test(my_swap, test_swap) {
    int a = 10;
    int b = 20;
    my_swap(&a, &b);
    cr_assert_eq(a, 20);
    cr_assert_eq(b, 10);
}

Test(my_str_isupper, test_str_isupper) {
    cr_assert_eq(my_str_isupper("Hello, world!"), 0);
    cr_assert_eq(my_str_isupper("HELLO"), 1);
    cr_assert_eq(my_str_isupper("WORLD"), 1);
}

Test(my_space_width, test_space_width, .init = redirect_all_stdout) {
    my_space_width(10, 5);
    cr_assert_stdout_eq_str("     ");
}