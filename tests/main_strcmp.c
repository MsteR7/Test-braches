/*
** EPITECH PROJECT, 2025
** asm
** File description:
** main test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <stdio.h>


int call(const char *s1, const char *s2)
{
    void *handle;
    int  (*strcmp_ptr) (const char *, const char *);
    int value;

    handle = dlopen("libasm.so", RTLD_LAZY);

    if (handle == NULL)
        perror("Error while opening");
    strcmp_ptr = dlsym(handle, "strcmp");
    value = strcmp_ptr(s1, s2);
    dlclose(handle);
    return value;

}

Test(strlen, _sameLen)
{
    cr_assert_eq(call("Hello", "Hello"), strcmp("Hello", "Hello"));
}

Test(strlen, _oneLetter)
{
    cr_assert_eq(call("hey", "hEy"), strcmp("hey", "hEy"));
}

Test(strlen, _oneLetterMissing)
{
    cr_assert_eq(call("Hello", "Hell"), strcmp("Hello", "Hell"));
}

Test(strlen, _emptyString__)
{
    cr_assert_eq(call("", "bad"), strcmp("", "bad"));
}

Test(strlen, _wrongWithSpaces)
{
    cr_assert_eq(call("Its Dora", "Idea"), strcmp("Its Dora", "Idea"));
}

Test(strlen, _beginningWithSpaces)
{
    cr_assert_eq(call("   new", "   new"), strcmp("   new", "   new"));
}

Test(strlen, _differentWords)
{
    cr_assert_eq(call("Guy", "Girl"), strcmp("Guy", "Girl"));
}

Test(strlen, _fruits)
{
    cr_assert_eq(call("mango", "papaya"), strcmp("mango", "papaya"));
}

Test(my_strcmp, _equalStrings) {
    cr_assert_eq(call("First thing", "First thing"), strcmp("First thing", "First thing"));
}

Test(my_strcmp, _firstStringGreater) {
    cr_assert_eq(call("world", "hello"), strcmp("world", "hello"));
}

Test(my_strcmp, _secondStringGreater) {
    cr_assert_eq(call("apple", "banana"), strcmp("apple", "banana"));
}

Test(my_strcmp, _emptyFirstString) {
    cr_assert_eq(call("", "hello"), strcmp("", "hello"));
}

Test(my_strcmp, _emptySecondString) {
    cr_assert_eq(call("hello", ""), strcmp("hello", ""));
}

Test(my_strcmp, _bothEmptyStrings) {
    cr_assert_eq(call("", ""), strcmp("", ""));
}

Test(my_strcmp, _caseSensitivity) {
    cr_assert_eq(call("Hello", "hello"), strcmp("Hello", "hello"));
}

Test(my_strcmp, _firstStringShorter) {
    cr_assert_eq(call("hi", "high"), strcmp("hi", "high"));
}

Test(my_strcmp, _secondStringShorter) {
    cr_assert_eq(call("high", "hi"), strcmp("high", "hi"));
}

Test(my_strcmp, _specialCharacters) {
    cr_assert_eq(call("hello!", "hello?"), strcmp("hello!", "hello?"));
}

Test(my_strcmp, _numericStrings) {
    cr_assert_eq(call("123", "122"), strcmp("123", "122"));
}

Test(my_strcmp, _longStrings) {
    cr_assert_eq(call("This is a long test string.", "This is a long test string."),
                strcmp("This is a long test string.", "This is a long test string."));
}

Test(my_strcmp, _stringsWithSpaces) {
    cr_assert_eq(call("hello world", "hello  world"), strcmp("hello world", "hello  world"));
}
