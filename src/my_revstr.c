/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** my_revstr
*/

#include "include.h"

void my_swap(char *a, char *b)
{
    char c = *a;

    *a = *b;
    *b = c;
}

int my_strlen(char *const str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    int len = my_strlen(str) - 1;

    for (int j = 0; j < (len / 2); j++, i--)
        my_swap(&str[j], &str[i]);
    return (str);
}