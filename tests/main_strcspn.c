/*
** EPITECH PROJECT, 2025
** asm
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <stdio.h>

size_t str_cspn(const char* s1, const char *s2)
{
    void *handle;
    size_t (*str_cspn) (const char*, const char *);
    size_t res;

    handle = dlopen("libasm.so", RTLD_LAZY);

    if (handle == NULL)
        perror("Error while opening");
    str_cspn = dlsym(handle, "strcspn");
    res = str_cspn(s1, s2);
    dlclose(handle);
    return res;
}

Test(cspn, second_Letter)
{
    cr_assert_eq(str_cspn("Hello user20", "eu2"), strcspn("Hello user20", "eu2"));
}

Test(cspn, not__found__letter)
{
    cr_assert_eq(str_cspn("Moon", "psf"), strcspn("Moon", "psf"));
}

Test(cspn, for_null)
{
    cr_assert_eq(str_cspn("Buddy", ""), strcspn("Buddy", ""));
}

Test(cspn, upto3)
{
    cr_assert_eq(str_cspn("Ocean", "a"), strcspn("Ocean", "a"));
}