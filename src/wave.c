/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** wave
*/

#include "include.h"

float **wave(float **ddmap , float inc, int **co_map)
{
    for (int i = 0 ; i < 100 ; i++){
        for (int j = 0 ; j < 100 ; j++){
            if (co_map[i][j] == 1)
                ddmap[i][j] = 30 + PerlinNoise_2D(i + inc, j + inc, 8, 1000) * 6;
        }
    }
    return (ddmap);
}

float **wave_l(float **ddmap , int inc, int **co_map)
{
    for (int i = 0 ; i < 100 ; i++){
        for (int j = 0 ; j < 100 ; j++){
            if (co_map[i][j] == 1)
                ddmap[i][j] = 30 + PerlinNoise_2D(i + inc / 1.3, j + inc / 1.3, 9, 3000) * 4;
        }
    }
    return (ddmap);
}
