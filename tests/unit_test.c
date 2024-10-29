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

// Test for %s (string) format specifier
Test(my_printf, string_specifier, .init = redirect_all_stdout) {
    my_printf("%s", "Hello, world!");
    cr_assert_stdout_eq_str("Hello, world!");
}

// Test for %c (character) format specifier
Test(my_printf, char_specifier, .init = redirect_all_stdout) {
    my_printf("%c", 'A');
    cr_assert_stdout_eq_str("A");
}

// Test for %x (hexadecimal lowercase) and %X (hexadecimal uppercase)
Test(my_printf, hex_specifiers, .init = redirect_all_stdout) {
    my_printf("%x %X", 255, 255);
    cr_assert_stdout_eq_str("ff FF");
}

// Test for %p (pointer)
Test(my_printf, pointer_specifier, .init = redirect_all_stdout) {
    int a = 10;
    my_printf("%p", &a);
}

// Test for %o (octal) format specifier
Test(my_printf, octal_specifier, .init = redirect_all_stdout) {
    my_printf("%o", 64);
    cr_assert_stdout_eq_str("100");
}

// Test for %d, %i (decimal integer)
Test(my_printf, decimal_specifiers, .init = redirect_all_stdout) {
    my_printf("%d %i", 123, -456);
    cr_assert_stdout_eq_str("123 -456");
}

// Test for %f, %F (float) format specifier
Test(my_printf, float_specifier, .init = redirect_all_stdout) {
    my_printf("%f", 3.14159);
    cr_assert_stdout_eq_str("3.141590");
}

// Test for the %#x, %#X, and %#o specifiers
Test(my_printf, hash_specifiers, .init = redirect_all_stdout) {
    my_printf("%#x %#X %#o", 255, 255, 8);
    cr_assert_stdout_eq_str("0xff 0XFF 010");
}

