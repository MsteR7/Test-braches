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


int callLib(const char *str)
{
    void *handle;
    int  (*strlen_ptr) (const char *);
    int len;

    handle = dlopen("libasm.so", RTLD_LAZY);

    if (handle == NULL)
        perror("Error while opening");
    strlen_ptr = dlsym(handle, "strlen");
    len = strlen_ptr(str);
    dlclose(handle);
    return len;

}

Test(strlen, _emptyStrin)
{
    cr_assert_eq(callLib(""), strlen(""));
}

Test(strlen, _withSpaces)
{
    cr_assert_eq(callLib("Hey, its me!"), strlen("Hey, its me!"));
}

Test(strlen, normalCase)
{
    cr_assert_eq(callLib("Universe"), strlen("Universe"));
}