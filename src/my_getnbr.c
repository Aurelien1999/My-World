/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** my_getnbr
*/

#include "include.h"

int my_supergetnbr(char *str, int i)
{
    int result = 0;
    int k = 1;
    int z = i;
    int j = 1;
    if (str[i - 1] == '-')
        k = -k;
    while (str[i] >= '0' && str[i] <= '9') {
        j = j * 10;
        i++;
    }
    j = j/10;
    while (str[z] >= '0' && str[z] <= '9') {
        result = result + ((str[z] - 48) * j);
        j = j / 10;
        z++;
    }
    return (k * result);
}

int my_getnbr(char *str)
{
    int i = 0;
    int k = 1;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            return (my_supergetnbr(str, i));
        i++;
    }
    return (0);
}
