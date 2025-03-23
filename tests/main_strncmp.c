/*
** EPITECH PROJECT, 2025
** asm
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/internal/test.h>
#include <criterion/redirect.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

int ncmp(const char *s1, const char *s2, size_t len)
{
    void *handle;
    int  (*ncmp_ptr) (const char *, const char *, size_t);
    int value;

    handle = dlopen("libasm.so", RTLD_LAZY);

    if (handle == NULL)
        perror("Error while opening");
    ncmp_ptr = dlsym(handle, "strncmp");
    value = ncmp_ptr(s1, s2, len);
    dlclose(handle);
    return value;
}

Test(strncmp, _oneDifferentLetter) //passed 1 16
{
    cr_assert_eq(ncmp("anonymous", "anonimous", 5), strncmp("anonymous", "anonimous", 5));
}

Test(strncmp, _upperCase) //passed -1 -32
{
        cr_assert_eq(ncmp("Test", "test", 3), strncmp("Test", "test", 3));
}


Test(strncmp, _same2Letters)
{
    cr_assert_eq(ncmp("Mickey", "Minnie", 2), strncmp("Mickey", "Minnie", 2));
}

Test(strncmp, lastLetter) //passed -1 -16
{
    cr_assert_eq(ncmp("  mod", "  mot", 5), strncmp("  mod", "  mot", 5));
}

Test(my_strncmp, _equalstrings) {
    cr_assert_eq(ncmp("hello", "hello", 5), strncmp("hello", "hello", 5));
}

Test(my_strncmp, _firststringgreater) { //passed 1 15
    cr_assert_eq(ncmp("world", "hello", 3), strncmp("world", "hello", 3));
}

Test(my_strncmp, _secondstringgreater) {
    cr_assert_eq(ncmp("apple", "banana", 4), strncmp("apple", "banana", 4));
}

Test(my_strncmp, _emptyFirstString) { //passed 1 104
    cr_assert_eq(ncmp("", "hello", 2), strncmp("", "hello", 2));
}

Test(my_strncmp, _emptysecondstring) {
    cr_assert_eq(ncmp("hello", "", 3), strncmp("hello", "", 3));
}

Test(my_strncmp, _bothemptyStrings) {
    cr_assert_eq(ncmp("", "", 5), strncmp("", "", 5));
}

Test(my_strncmp, _casesensitivity) { //passed -1 -104
    cr_assert_eq(ncmp("Hello", "hello", 2), strncmp("Hello", "hello", 2));
}

Test(my_strncmp, _firstStringShorter) { //passed 1 15
    cr_assert_eq(ncmp("hi", "high", 3), strncmp("hi", "high", 3));
}

Test(my_strncmp, _secondStringShorter) { //passed 1 103
    cr_assert_eq(ncmp("high", "hi", 3), strncmp("high", "hi", 3));
}

Test(my_strncmp, _specialCharacters) { //passed -1 -30
    cr_assert_eq(ncmp("hello!", "hello?", 6), strncmp("hello!", "hello?", 6));
}

Test(my_strncmp, _NumericStrings) {
    cr_assert_eq(ncmp("123", "122", 2), strncmp("123", "122", 2));
}

Test(my_strncmp, _longstr) {
    cr_assert_eq(ncmp("This is a long test string.", "This is a long test string.", 20),
                strncmp("This is a long test string.", "This is a long test string.", 20));
}

Test(my_strncmp, _stringsWithSpaces) {
    cr_assert_eq(ncmp("hello world", "hello  world", 6), strncmp("hello world", "hello  world", 6));
}

Test(my_strncmp, _limitShorterthanStr) {
    cr_assert_eq(ncmp("abcdef", "abcxyz", 3), strncmp("abcdef", "abcxyz", 3));
}

Test(my_strncmp, _LimitLongerThanDifference) { //passed -1 -20
        cr_assert_eq(ncmp("abcdef", "abcxyz", 6), strncmp("abcdef", "abcxyz", 6));
}

Test(my_strncmp, _zeroLengthComparison) {
    cr_assert_eq(ncmp("abcdef", "abcxyz", 0), strncmp("abcdef", "abcxyz", 0));
}