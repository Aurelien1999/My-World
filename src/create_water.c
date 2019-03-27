/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** create_water
*/

#include "include.h"

float **create_water(float **water_map)
{
    for (int i = 0 ; i < 100 ; i++){
        for (int j = 0 ; j < 100 ; j++){
            (water_map[i][j] <= 36)? (water_map[i][j] = 30) : (1);
        }
    }
    return (water_map);
}

float **create_water_l(float **water_map)
{
    for (int i = 0 ; i < 100 ; i++){
        for (int j = 0 ; j < 100 ; j++){
            (water_map[i][j] <= 40)? (water_map[i][j] = 30) : (1);
        }
    }
    return (water_map);
}
