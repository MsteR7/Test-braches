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


int chr(const char *str, int letter)
{
    void *handle;
    int  (*strchr_ptr) (const char *, int);
    int value;

    handle = dlopen("libasm.so", RTLD_LAZY);

    if (handle == NULL)
        perror("Error while opening");
    strchr_ptr = dlsym(handle, "strchr");
    value = strchr_ptr(str, letter);
    dlclose(handle);
    return value;
}

Test(strchr, _normal)
{
    cr_assert_eq(chr("This case is", 'a'), strchr("This case is", 'a'));
}

Test(strchr, _notFound)
{
    cr_assert_eq(chr("This case is", 'j'), strchr("This case is", 'j'));
}

Test(strchr, _multiple)
{
    cr_assert_eq(chr("Banana is good", 'o'), strchr("Banana is good", 'o'));
}

Test(strchr, _empty)
{
    cr_assert_eq(chr("", '0'), strchr("", '0'));
}

Test(strchr, _nullCharacter)
{
    cr_assert_eq(chr("Easy", '\0'), strchr("Easy", '\0'));
}

Test(strchr, _firstCharacter)
{
    cr_assert_eq(chr("Hello", 'H'), strchr("Hello", 'H'));
}

Test(strchr, _middleCharacter)
{
    cr_assert_eq(chr("Hello", 'l'), strchr("Hello", 'l'));
}

Test(strchr, _lastCharacter)
{
    cr_assert_eq(chr("Hello", 'o'), strchr("Hello", 'o'));
}

Test(strchr, _nonExistentCharacter)
{
    cr_assert_eq(chr("Hello", 'z'), strchr("Hello", 'z'));
}

Test(strchr, _emptyString)
{
    cr_assert_eq(chr("", 'H'), strchr("", 'H'));
}

Test(strchr, _multipleOccurrences)
{
    cr_assert_eq(chr("banana", 'a'), strchr("banana", 'a'));
}

Test(strchr, _fullStringMatch)
{
    cr_assert_eq(chr("abcdabcd", 'c'), strchr("abcdabcd", 'c'));
}

Test(strchr, _longString)
{
    cr_assert_eq(chr("This is a long test string with many characters", 't'), strchr("This is a long test string with many characters", 't'));
}
