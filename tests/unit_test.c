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

//test no %

Test(my_printf, no_specifier, .init = redirect_all_stdout) {
    my_printf("Hello, world!");
    cr_assert_stdout_eq_str("Hello, world!");
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

Test(my_printf, octal_specifier_6, .init = redirect_all_stdout) {
    my_printf("%o", 6);
    cr_assert_stdout_eq_str("6");
}

Test(my_printf, octal_specifier_10, .init = redirect_all_stdout) {
    my_printf("%o", 10);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, octal_specifier_64, .init = redirect_all_stdout) {
    my_printf("%o", 64);
    cr_assert_stdout_eq_str("100");
}

Test(my_printf, percent_specifier, .init = redirect_all_stdout) {
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, unsigned_specifier, .init = redirect_all_stdout) {
    my_printf("%u", 123);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, decimal_specifiers, .init = redirect_all_stdout) {
    my_printf("%d %i", 123, -456);
    cr_assert_stdout_eq_str("123 -456");
}

Test(my_printf, plus_flag, .init = redirect_all_stdout) {
    my_printf("%+d %+i", 123, -456);
    cr_assert_stdout_eq_str("+123 -456");
}

Test(my_printf, long_double, .init = redirect_all_stdout) {
    long double Lf = 3.14159;
    my_printf("%Lf", Lf);
    cr_assert_stdout_eq_str("3.141590");
}

Test(my_printf, long_double2, .init = redirect_all_stdout) {
    long double Lf = 3.14159;
    my_printf("%+Lf", Lf);
    cr_assert_stdout_eq_str("+3.141590");
}

Test(my_printf, long_int, .init = redirect_all_stdout) {
    long int ld = 1234567890;
    my_printf("%ld", ld);
    cr_assert_stdout_eq_str("1234567890");
}

Test(my_printf, long_int2, .init = redirect_all_stdout) {
    long int ld = 1234567890;
    my_printf("%+ld", ld);
    cr_assert_stdout_eq_str("+1234567890");
}

Test(my_printf, double, .init = redirect_all_stdout) {
    double f = 3.14159;
    my_printf("%+f", f);
    cr_assert_stdout_eq_str("+3.141590");
}

Test(my_printf, double2, .init = redirect_all_stdout) {
    double lf = 3.14159;
    my_printf("%lf", lf);
    cr_assert_stdout_eq_str("3.141590");
}

Test(my_printf, double3, .init = redirect_all_stdout) {
    double lf = 3.14159;
    my_printf("%+lf", lf);
    cr_assert_stdout_eq_str("+3.141590");
}

Test(my_printf, scientific, .init = redirect_all_stdout) {
    double f = 3.14159;
    my_printf("%+e", f);
    cr_assert_stdout_eq_str("+3.141590e+00");
}

Test(my_printf, scientific2, .init = redirect_all_stdout) {
    double f = 3.14159;
    my_printf("%+E", f);
    cr_assert_stdout_eq_str("+3.141590E+00");
}

//test %#x %#X %#o

Test(my_printf, hash_specifiers, .init = redirect_all_stdout) {
    my_printf("%#x %#X %#o", 255, 255, 8);
    cr_assert_stdout_eq_str("0xff 0XFF 010");
}

Test(my_put_float, test_put_float, .init = redirect_all_stdout) {
    my_put_float(3.14159);
    cr_assert_stdout_eq_str("3.141590");
}

Test(my_put_float, test_put_float_negative, .init = redirect_all_stdout) {
    my_put_float(-3.14159);
    cr_assert_stdout_eq_str("-3.141590");
}

Test(my_printf, m_specifier, .init = redirect_all_stdout) {
    my_printf("%m");
    cr_assert_stdout_eq_str("Success");
}

//test %#m

Test(my_printf, hash_m_specifier, .init = redirect_all_stdout) {
    my_printf("%#m");
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, n_specifier, .init = redirect_all_stdout) {
    int a;
    my_printf("%n", &a);
    cr_assert_stdout_eq_str("");
}

Test(my_compute_power_rec, test_power) {
    cr_assert_eq(my_compute_power_rec(2, 3), 8);
    cr_assert_eq(my_compute_power_rec(3, 3), 27);
    cr_assert_eq(my_compute_power_rec(5, 2), 25);
    cr_assert_eq(my_compute_power_rec(10, 0), 1);
}

Test(my_compute_power_rec, test_power_negative) {
    cr_assert_eq(my_compute_power_rec(2, -3), 0);
    cr_assert_eq(my_compute_power_rec(3, -3), 0);
    cr_assert_eq(my_compute_power_rec(5, -2), 0);
    cr_assert_eq(my_compute_power_rec(10, -1), 0);
}

Test(my_compute_square_root, test_square_root) {
    cr_assert_eq(my_compute_square_root(4), 2);
    cr_assert_eq(my_compute_square_root(9), 3);
    cr_assert_eq(my_compute_square_root(16), 4);
    cr_assert_eq(my_compute_square_root(25), 5);
}

Test(my_compute_square_root, test_square_root_2) {
    cr_assert_eq(my_compute_square_root(0), 0);
    cr_assert_eq(my_compute_square_root(1), 1);
    cr_assert_eq(my_compute_square_root(2), 0);
    cr_assert_eq(my_compute_square_root(3), 0);
    cr_assert_eq(my_compute_square_root(5), 0);
}

Test(my_find_prime_sup, test_prime_sup) {
    cr_assert_eq(my_find_prime_sup(4), 5);
    cr_assert_eq(my_find_prime_sup(9), 11);
    cr_assert_eq(my_find_prime_sup(16), 17);
    cr_assert_eq(my_find_prime_sup(25), 29);
}

Test(my_find_prime_sup, test_prime_sup_negative) {
    cr_assert_eq(my_find_prime_sup(0), 2);
    cr_assert_eq(my_find_prime_sup(1), 2);
    cr_assert_eq(my_find_prime_sup(2), 2);
    cr_assert_eq(my_find_prime_sup(3), 3);
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

Test(my_is_prime, test_is_prime_2) {
    cr_assert_eq(my_is_prime(0), 0);
    cr_assert_eq(my_is_prime(1), 0);
    cr_assert_eq(my_is_prime(2), 1);
    cr_assert_eq(my_is_prime(3), 1);
}

Test(my_put_nbr, test_put_nbr_positive, .init = redirect_all_stdout) {
    my_put_nbr(12345);
    cr_assert_stdout_eq_str("12345");
}

Test(my_put_nbr, test_put_nbr_negative, .init = redirect_all_stdout) {
    my_put_nbr(-12345);
    cr_assert_stdout_eq_str("-12345");
}

Test(my_put_nbr, test_put_nbr_min, .init = redirect_all_stdout) {
    my_put_nbr(-2147483648);
    cr_assert_stdout_eq_str("-2147483648");
}

Test(my_put_nbr, test_put_nbr_single_digit, .init = redirect_all_stdout) {
    my_put_nbr(7);
    cr_assert_stdout_eq_str("7");
}


Test(my_getnbr, test_getnbr) {
    cr_assert_eq(my_getnbr("123"), 123);
    cr_assert_eq(my_getnbr("-123"), -123);
    cr_assert_eq(my_getnbr("0"), 0);
    cr_assert_eq(my_getnbr("2147483647"), 2147483647);
    cr_assert_eq(my_getnbr("-2147483648"), -2147483648);
}

Test(my_getnbr, test_getnbr_2) {
    cr_assert_eq(my_getnbr("1234567890"), 1234567890, "Expected 1234567890");
    cr_assert_eq(my_getnbr("-1234567890"), -1234567890, "Expected -1234567890");
    cr_assert_eq(my_getnbr("12345678901234567890"), 0, "Expected overflow for large positive number");
    cr_assert_eq(my_getnbr("-12345678901234567890"), 0, "Expected overflow for large negative number");
    cr_assert_eq(my_getnbr("2147483647"), 2147483647, "Expected 2147483647");
    cr_assert_eq(my_getnbr("-2147483648"), -2147483648, "Expected -2147483648");
    cr_assert_eq(my_getnbr("2147483648"), 0, "Expected overflow for value just above INT_MAX");
    cr_assert_eq(my_getnbr("-2147483649"), 0, "Expected overflow for value just below INT_MIN");
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

Test(my_put_long_double, test_put_long_double_negative, .init = redirect_all_stdout) {
    my_put_long_double(-3.14159);
    cr_assert_stdout_eq_str("-3.141590");
}

Test(my_put_long_int, test_put_long_int_positive, .init = redirect_all_stdout) {
    my_put_long_int(1234567890);
    cr_assert_stdout_eq_str("1234567890");
}

Test(my_put_long_int, test_put_long_int_negative, .init = redirect_all_stdout) {
    my_put_long_int(-1234567890);
    cr_assert_stdout_eq_str("-1234567890");
}

Test(my_put_long_int, test_put_long_int_min, .init = redirect_all_stdout) {
    my_put_long_int(-2147483648L);
    cr_assert_stdout_eq_str("-2147483648");
}

Test(my_put_long_int, test_put_long_int_single_digit, .init = redirect_all_stdout) {
    my_put_long_int(5);
    cr_assert_stdout_eq_str("5");
}

Test(my_put_scientific, test_put_scientific, .init = redirect_all_stdout) {
    my_put_scientific(3.14159);
    cr_assert_stdout_eq_str("3.141590e+00");
}

Test(my_put_scientific, test_put_scientific_2, .init = redirect_all_stdout) {
    my_put_scientific(0.0);
    cr_assert_stdout_eq_str("0.000000e+00");
}

Test(my_put_scientific, test_put_scientific_3, .init = redirect_all_stdout) {
    my_put_scientific(-32958);
    cr_assert_stdout_eq_str("-3.295800e+04");
}

Test(my_put_scientific_cap, test_put_scientific_cap, .init = redirect_all_stdout) {
    my_put_scientific_cap(3.14159);
    cr_assert_stdout_eq_str("3.141590E+00");
}

Test(my_put_scientific, test_put_scientific_cap_2, .init = redirect_all_stdout) {
    my_put_scientific_cap(0.0);
    cr_assert_stdout_eq_str("0.000000E+00");
}

Test(my_put_scientific, test_put_scientific_cap_3, .init = redirect_all_stdout) {
    my_put_scientific_cap(-32958);
    cr_assert_stdout_eq_str("-3.295800E+04");
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

Test(my_str_isalpha, test_str_isalpha2) {
    cr_assert_eq(my_str_isalpha(""), 1);
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

Test(my_strncpy, test_short_src) {
    char dest[50];
    my_strncpy(dest, "Hello", 10);
    cr_assert_str_eq(dest, "Hello");
    for (int i = 5; i < 10; i++) {
        cr_assert_eq(dest[i], '\0');
    }
}

Test(my_strncpy, test_empty_src) {
    char dest[50];
    my_strncpy(dest, "", 5);
    cr_assert_str_empty(dest);
    for (int i = 0; i < 5; i++) {
        cr_assert_eq(dest[i], '\0');
    }
}

Test(my_strncpy, test_zero_n) {
    char dest[50] = "Initial content";
    my_strncpy(dest, "Hello", 0);
    cr_assert_str_eq(dest, "Initial content");
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
