/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** compare
*/

#include "include.h"

float compare_tmp(float tmp3, sfVector2i * tmp, float average, int  i, int j){
    if (tmp3 < average){
        average = tmp3;
        tmp->x = i;
        tmp->y = j;
    }
    return (average);
}

sfVector2i comparemap(sfVector2i iso_mouse, float **dddmap_cpy, double a, double b)
{
    sfVector2i tmp;
    float average = 1000;
    sfVector2f tmp2;
    float tmp3;

    for (int i = 0 ; i < 100 ; i++){
        for (int j = 0 ; j < 100 ; j++){
            tmp2 = project_iso_point(a, b, i, j, dddmap_cpy[i][j]);
            tmp2.x - iso_mouse.x < 0 ? tmp2.x = (-(tmp2.x - iso_mouse.x)) : (tmp2.x - iso_mouse.x);
            tmp2.y - iso_mouse.y < 0 ? tmp2.y = (-(tmp2.y - iso_mouse.y)) : (tmp2.y - iso_mouse.y);
            tmp3 = tmp2.x + tmp2.y/2.;
            average = compare_tmp(tmp3, &tmp, average, i, j);
        }
    }
    return (tmp);
}
