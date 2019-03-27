/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** create_line
*/

#include "include.h"

sfVertexArray *create_line(int i, int j, sfVector2f **ddmap , float** dddmap, int** co_map)
{
    float c = (dddmap[j][i] + dddmap[j+1][i] + dddmap[j+1][i+1] + dddmap[j][i+1])/4.;
    float d = PerlinNoise_2D(j,i,9,10000)*100;
    sfVector3f normal_v = normal(dddmap,i,j);
    sfColor color1 ;
    // if( c >= 49. && (i != 0 && i != 99) && (j != 0 && j!= 99))
    //   color1 = (sfColor) {(0+(c-30)*2)*scal(normal_v),(89+(c-30)*2)*scal(normal_v),(33+(c-30)*2)*scal(normal_v),255};
    //else
      color1 = (sfColor){0+c*2, 0+c*2, 0+c*2, 255};
    if (co_map[j][i] == 1 &&  co_map[j+1][i] == 1 && co_map[j+1][i+1] == 1 && co_map[j][i+1] == 1) {
      color1 = (sfColor) {0,255,239 ,d};
    }
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = ddmap[i][j + 1], .color = color1};
    sfVertex vertex2 = {.position = ddmap[i + 1][j + 1], .color = color1};
    sfVertex vertex3 = {.position = ddmap[i + 1][j], .color = color1};
    sfVertex vertex4 = {.position = ddmap[i][j], .color = color1};
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return (vertex_array);
}

sfVertexArray *create_line_u(int i, int j, sfVector2f **ddmap , float** dddmap)
{
    float c = (dddmap[j][i] + dddmap[j+1][i] + dddmap[j+1][i+1] + dddmap[j][i+1])/4.;
    sfColor color1 ;
    color1 = (sfColor){0+c*2, 0+c*2, 0+c*2, 255};
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = ddmap[i][j + 1], .color = color1};
    sfVertex vertex2 = {.position = ddmap[i + 1][j + 1], .color = color1};
    sfVertex vertex3 = {.position = ddmap[i + 1][j], .color = color1};
    sfVertex vertex4 = {.position = ddmap[i][j], .color = color1};
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return (vertex_array);
}

