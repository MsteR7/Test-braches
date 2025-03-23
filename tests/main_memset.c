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

void *mem_set(void *pointer, int value, size_t count)
{
    void *handle;
    void * (*memset_ptr) (void *, int, size_t);
    void *res;

    handle = dlopen("libasm.so", RTLD_LAZY);

    if (handle == NULL)
        perror("Error while opening");
    memset_ptr = dlsym(handle, "memset");
    res = memset_ptr(pointer, value, count);
    dlclose(handle);
    return res;
}

Test(strchr, _numbers)
{
    int array[] = {1, 2, 3, 4};
    cr_assert_eq(mem_set(array, 7, 4), memset(array, 7, 4));
}

Test(strchr, _string)
{
    char str[] = "This is a test";
    cr_assert_eq(mem_set(str, '#', 9), memset(str, '#', 9));
}
