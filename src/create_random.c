/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** create_random
*/

#include "include.h"

int create_random(void)
{
    int tmp = 0;

    tmp = (rand()%3)-1;
    while (tmp == -2) {
        tmp = (rand()%3)-1;
    }
    return (tmp);
}