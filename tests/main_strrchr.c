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


int chrr(const char *str, int letter)
{
    void *handle;
    int  (*strrchr_ptr) (const char *, int);
    int value;

    handle = dlopen("libasm.so", RTLD_LAZY);

    if (handle == NULL)
        perror("Error while opening");
    strrchr_ptr = dlsym(handle, "strrchr");
    value = strrchr_ptr(str, letter);
    dlclose(handle);
    return value;

}

Test(strrchr, _multipleletters)
{
    cr_assert_eq(chrr("This case is anonymous", 'a'), strrchr("This case is anonymous", 'a'));
}

Test(strrchr, _notFounded)
{
    cr_assert_eq(chrr("This case is closed", 'j'), strrchr("This case is closed", 'j'));
}

Test(strrchr, _b_case)
{
    cr_assert_eq(chrr("banana is bony", 'b'), strrchr("banana is bony", 'b'));
}

Test(strrchr, _nothing__)
{
    cr_assert_eq(chrr("", '0'), strrchr("", '0'));
}

Test(strrchr, _theend)
{
    cr_assert_eq(chrr("The finish line", '\0'), strrchr("The finish line", '\0'));
}

Test(strrchr, _end__)
{
    cr_assert_eq(chrr("The finish line", '\0'), strrchr("The finish line", '\0'));
}

Test(strrchr, _firstOccu_)
{
    cr_assert_eq(chrr("Hello", 'H'), strrchr("Hello", 'H'));
}

Test(strrchr, _lastOccu_)
{
    cr_assert_eq(chrr("banana", 'a'), strrchr("banana", 'a'));
}

Test(strrchr, _middChar_)
{
    cr_assert_eq(chrr("racecar", 'c'), strrchr("racecar", 'c'));
}

Test(strrchr, _nonExtCha_)
{
    cr_assert_eq(chrr("Hello", 'z'), strrchr("Hello", 'z'));
}

Test(strrchr, _eString_)
{
    cr_assert_eq(chrr("", 'X'), strrchr("", 'X'));
}

Test(strrchr, _oNullTerminator_)
{
    cr_assert_eq(chrr("\0", '\0'), strrchr("\0", '\0'));
}

Test(strrchr, _fullStrMatch_)
{
    cr_assert_eq(chrr("abcdabcd", 'd'), strrchr("abcdabcd", 'd'));
}

Test(strrchr, _LString_)
{
    cr_assert_eq(chrr("This is a long test string with many characters", 't'), strrchr("This is a long test string with many characters", 't'));
}
