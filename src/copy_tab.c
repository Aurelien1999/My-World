/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** copy_tab
*/
#include "include.h"

float** copy_map(float** dddmap)
{
    float **map_cpy = malloc(sizeof(float*)*100);

    for(int i = 0 ; i < 100 ; i++){
        map_cpy[i] = malloc(sizeof(float)*100);
        for(int j = 0 ; j < 100 ; j++){
            map_cpy[i][j] = dddmap[i][j];
        }
    }
  return(map_cpy);
}
