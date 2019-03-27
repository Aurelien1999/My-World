/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** create_board
*/

#include "include.h"

float **create_board(float **dddmap)
{
    for (int i = 0 ; i < 100 ; i++){
        dddmap[i][99] = 30;
        dddmap[i][0] = 30;
        dddmap[99][i] = 30;
        dddmap[0][i] = 30;
    }
    return (dddmap);
}
