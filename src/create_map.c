/*
**EPITECH PROJECT, 2019
**MUL_my_world_2018
**File description:
**create_map
*/

#include "include.h"

sfVector2f **create_2d_map(double a, double b, float **dddmap)
{
    sfVector2f **iso_map = NULL;

    iso_map = malloc(sizeof(sfVector2f*) * MAP_Y + 1);
    for (int i = 0 ; i < MAP_Y ; i++) {
        iso_map[i] = malloc(sizeof(sfVector2f) * MAP_X + 1);
        for (int j = 0 ; j < MAP_X ; j++) {
            iso_map[i][j] = project_iso_point(a, b, j, i, dddmap[j][i]);
        }
    }
    return (iso_map);
}

sfVector2f **create_2d_map_l(double a, double b, float **dddmap)
{
    sfVector2f **iso_map = NULL;

    iso_map = malloc(sizeof(sfVector2f*) * MAP_Y + 1);
    for (int i = 0 ; i < MAP_Y ; i++) {
        iso_map[i] = malloc(sizeof(sfVector2f) * MAP_X + 1);
        for (int j = 0 ; j < MAP_X ; j++) {
            iso_map[i][j] = project_iso_point_l(a, b, j, i, dddmap[j][i]);
        }
    }
    return (iso_map);
}

sfVector2f **create_2d_map_map(float **dddmap)
{
    sfVector2f **iso_map = NULL;

    iso_map = malloc(sizeof(sfVector2f*) * MAP_Y + 1);
    for (int i = 0 ; i < MAP_Y ; i++) {
        iso_map[i] = malloc(sizeof(sfVector2f) * MAP_X + 1);
        for (int j = 0 ; j < MAP_X ; j++) {
            iso_map[i][j] = project_iso_point_map(j, i, dddmap[j][i]);
        }
    }
    return (iso_map);
}

sfVector2f **create_2d_map_map_map(float **dddmap)
{
    sfVector2f **iso_map = NULL;

    iso_map = malloc(sizeof(sfVector2f*) * MAP_Y + 1);
    for (int i = 0 ; i < MAP_Y ; i++) {
        iso_map[i] = malloc(sizeof(sfVector2f) * MAP_X + 1);
        for (int j = 0 ; j < MAP_X ; j++) {
            iso_map[i][j] = project_iso_point_map_map(j, i, dddmap[j][i]);
        }
    }
    return (iso_map);
}

float **create_map(float **ddd_map, int increase , int increase2)
{
    ddd_map = malloc(sizeof(float *) * 100);
    for (int i = 0; i < 100; i++)
        ddd_map[i] = malloc(sizeof(float) * 100);
    for (int i = 1 ; i < 99 ; i++) {
        for (int j = 1 ; j < 99 ; j++) {
            double f = PerlinNoise_2D(i + increase, j + increase2 , 9 , 10000);
            ddd_map[i][j] = f*80 ;
        }
    }
    for (int i = 0 ; i < 100 ; i++){
        ddd_map[i][0] = 0;
        ddd_map[i][99] = 0;
        ddd_map[0][i] = 0;
        ddd_map[i][99] = 0;
    }
    return (ddd_map);
}

int **create_co_map(float **dddmap)
{
    int **co = malloc(sizeof(int *)*100);
    for (int i = 0 ; i < 100 ; i++){
        co[i] = malloc(sizeof(int)*100);
    for (int j = 0 ; j < 100 ; j++)
        ((int)dddmap[i][j] == 30  && (i != 0 && i != 99 && j != 99 && j != 0)) ? co[i][j] = 1 :(co[i][j] = 0);
    }
    return (co);
}
