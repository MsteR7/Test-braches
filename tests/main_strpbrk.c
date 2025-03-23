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

const char *str_pbrk(const char* s1, const char *s2)
{
    void *handle;
    char *(*str_pbrk) (const char*, const char *);
    char* res;

    handle = dlopen("libasm.so", RTLD_LAZY);

    if (handle == NULL)
        perror("Error while opening");
    str_pbrk = dlsym(handle, "strpbrk");
    res = str_pbrk(s1, s2);
    dlclose(handle);
    return res;
}

Test(pbrk, secondLetter)
{
    cr_assert_eq(str_pbrk("Hello, my friend", "iyd"), strpbrk("Hello, my friend", "iyd"));
}

Test(pbrk, not__found)
{
    cr_assert_eq(str_pbrk("Moon", "psf"), strpbrk("Moon", "psf"));
}

Test(pbrk, lookin_for_null)
{
    cr_assert_eq(str_pbrk("Buddy", ""), strpbrk("Buddy", ""));
}

Test(pbrk, oneLetter)
{
    cr_assert_eq(str_pbrk("Buddy", "d"), strpbrk("Buddy", "d"));
}