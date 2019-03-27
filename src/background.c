/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** background
*/

#include "include.h"

sfColor **create_background_l(sfColor ** background , int w)
{
    static int random_seed = 30000;
    float c = 0;
    background = malloc(sizeof(sfColor *) * 200);
    for (int i = 0 ; i < 200 ; i++) {
        background[i] = malloc(sizeof(sfColor) * 200);
        for (int j = 0; j < 200; j++) {
          c = PerlinNoise_2D(i+random_seed+w, j + i+random_seed+w , 9.10,13000) * 5;
          background[i][j] = (sfColor) { 255 - c * 50, 255 - c, 255 - c, 255};
        }
    }
    return (background);
}

sfColor **create_background(sfColor ** background)
{
    int random_seed = rand()%10000;
    float c = 0;
    background = malloc(sizeof(sfColor *) * 200);
    for (int i = 0 ; i < 200 ; i++) {
        background[i] = malloc(sizeof(sfColor) * 200);
        for (int j = 0; j < 200; j++) {
          c = PerlinNoise_2D(i+random_seed, j + i+random_seed , 9.10,13000) * 5;
          background[i][j] = (sfColor) { 255 - c * 50, 255 - c, 255 - c, 255};
        }
    }
    return (background);
}

sfColor **create_background2(sfColor ** background, float o)
{
    float c = 0;
    background = malloc(sizeof(sfColor *) * 200);
    for (int i = 0 ; i < 200 ; i++) {
        background[i] = malloc(sizeof(sfColor) * 200);
        for (int j = 0; j < 200; j++) {
          c = PerlinNoise_2D(i + o, o, 6, 15000) *4;
          background[i][j] = (sfColor) {255 + c *cos(c) * PI / sin(18) * o * o, 0 + c * o * 127.5 * cos(c)/PI, 255 + c / o, 255};
        }
    }
    return (background);
}
