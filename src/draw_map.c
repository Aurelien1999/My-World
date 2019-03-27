/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** draw_map
*/

#include "include.h"

sfColor getcolorfromnb(int nb, brush_t keys)
{
  sfColor color;
  sfColor grey = (sfColor){132, 132, 132 , 255};
  sfColor grey_d = (sfColor){210, 210, 210 , 255};
  if (nb == 0)
    keys.up == 1 ? color = grey : (color = grey_d);
  if (nb == 20)
    keys.down == 1 ? color = grey : (color = grey_d);
  if (nb == 40)
    keys.plain == 1 ? color = grey : (color = grey_d);
  return(color);
}

void draw_rectangle_tiles(sfRenderWindow *window, int nb, brush_t keys)
{
  sfColor color = getcolorfromnb(nb, keys);
  sfVertexArray *vertex_array = sfVertexArray_create();
  sfVertex vertex1 = {.position = (sfVector2f){175, 20+nb}, .color = color};
  sfVertex vertex2 = {.position = (sfVector2f){175, 26+nb} ,.color = color};
  sfVertex vertex3 = {.position = (sfVector2f){195, 20+nb}, .color = color};
  sfVertex vertex4 = {.position = (sfVector2f){195, 26+nb}, .color = color};
  sfVertexArray_append(vertex_array, vertex1);
  sfVertexArray_append(vertex_array, vertex2);
  sfVertexArray_append(vertex_array, vertex3);
  sfVertexArray_append(vertex_array, vertex4);
  sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesStrip);
  sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
}

int draw_2d_map(sfRenderWindow *window, sfVector2f **ddmap , float ** dddmap , int **co_map ,int color_w)
{
    for (int i = 0 ; i < MAP_Y - 1; i++) {
        for (int j = 0 ; j < MAP_X - 1; j++) {

            float c = (dddmap[j][i] + dddmap[j+1][i] + dddmap[j+1][i+1] + dddmap[j][i+1])/4.;
            sfColor color1 ;
            sfColor water =  (sfColor) {68, 224, 208, 40};
            sfColor water_m =  (sfColor) {68+c*9-85, 224+c*9-85, 208+c*9-85, 255};
            sfVector3f normal_v = normal(dddmap, i, j);
            if ( c >= 49. && (i != 0 && i != 99) && (j != 0 && j != 99))
                color1 = (sfColor) {(0+(c-30)*2)*scal(normal_v), (89+(c-30)*2)*scal(normal_v), (33+(c-30)*2)*scal(normal_v), 255};
            else
                color1 = (sfColor){(0+c*2)*scal(normal_v), (0+c*2)*scal(normal_v), (0+c*2)*scal(normal_v), 255};
            if (co_map[j][i] == 1 &&  co_map[j+1][i] == 1 && co_map[j+1][i+1] == 1 && co_map[j][i+1] == 1) {
                color1 = color_w == 1 ? water_m : water;
            }
            color1.r += 30 / 100;
            color1.g += 30 / 100;
            color1.b += 30 / 100;
            sfVertexArray *vertex_array = sfVertexArray_create();
            sfVertex vertex1 = {.position = ddmap[i + 0][j + 1], .color = color1};
            sfVertex vertex2 = {.position = ddmap[i + 1][j + 1], .color = color1};
            sfVertex vertex3 = {.position = ddmap[i + 1][j + 0], .color = color1};
            sfVertex vertex4 = {.position = ddmap[i + 0][j + 1], .color = color1};
            sfVertexArray_append(vertex_array, vertex1);
            sfVertexArray_append(vertex_array, vertex2);
            sfVertexArray_append(vertex_array, vertex3);
            sfVertexArray_append(vertex_array, vertex4);
            sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesStrip);
            sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
            sfVertexArray_destroy(vertex_array);
            color1.r += 3;
            color1.g += 3;
            color1.b += 3;
            vertex_array = sfVertexArray_create();
            sfVertex vertex5 = {.position = ddmap[i + 0][j + 1], .color = color1};
            sfVertex vertex6 = {.position = ddmap[i + 1][j + 0], .color = color1};
            sfVertex vertex7 = {.position = ddmap[i + 0][j + 0], .color = color1};
            sfVertex vertex8 = {.position = ddmap[i + 0][j + 1], .color = color1};
            sfVertexArray_append(vertex_array, vertex5);
            sfVertexArray_append(vertex_array, vertex6);
            sfVertexArray_append(vertex_array, vertex7);
            sfVertexArray_append(vertex_array, vertex8);
            sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesStrip);
            sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
            sfVertexArray_destroy(vertex_array);
        }
    }
    return (0);
}

int draw_2d_map_u(sfRenderWindow *window, sfVector2f **ddmap , float ** dddmap)
{
    for (int i = 0 ; i < MAP_Y - 1; i++) {
        for (int j = 0 ; j < MAP_X - 1; j++) {

            float c = (dddmap[j][i] + dddmap[j+1][i] + dddmap[j+1][i+1] + dddmap[j][i+1])/4.;
            sfColor color1 = (sfColor){0+c*2, 0+c*2, 0+c*2, 255};
            color1.r += 3;
            color1.g += 3;
            color1.b += 3;
            sfVertexArray *vertex_array = sfVertexArray_create();
            sfVertex vertex1 = {.position = ddmap[i + 0][j + 1], .color = color1};
            sfVertex vertex2 = {.position = ddmap[i + 1][j + 1], .color = color1};
            sfVertex vertex3 = {.position = ddmap[i + 1][j + 0], .color = color1};
            sfVertex vertex4 = {.position = ddmap[i + 0][j + 1], .color = color1};
            sfVertexArray_append(vertex_array, vertex1);
            sfVertexArray_append(vertex_array, vertex2);
            sfVertexArray_append(vertex_array, vertex3);
            sfVertexArray_append(vertex_array, vertex4);
            sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesStrip);
            sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
            sfVertexArray_destroy(vertex_array);
            color1.r += 3;
            color1.g += 3;
            color1.b += 3;
            vertex_array = sfVertexArray_create();
            sfVertex vertex5 = {.position = ddmap[i + 0][j + 1], .color = color1};
            sfVertex vertex6 = {.position = ddmap[i + 1][j + 0], .color = color1};
            sfVertex vertex7 = {.position = ddmap[i + 0][j + 0], .color = color1};
            sfVertex vertex8 = {.position = ddmap[i + 0][j + 1], .color = color1};
            sfVertexArray_append(vertex_array, vertex5);
            sfVertexArray_append(vertex_array, vertex6);
            sfVertexArray_append(vertex_array, vertex7);
            sfVertexArray_append(vertex_array, vertex8);
            sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesStrip);
            sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
            sfVertexArray_destroy(vertex_array);
        }
    }
    return (0);
}

int draw_2d_map_map(sfRenderWindow *window, sfVector2f **ddmap , float ** dddmap)
{
    for (int i = 0 ; i < MAP_Y - 1; i++) {
        for (int j = 0 ; j < MAP_X - 1; j++) {

            float c = (dddmap[j][i] + dddmap[j+1][i] + dddmap[j+1][i+1] + dddmap[j][i+1])/15.;
            sfColor color1 = (sfColor){0+c*2, 0+c*2, 0+c*2, 127};
            color1.r += i;
            color1.g += i;
            color1.b += i;
            sfVertexArray *vertex_array = sfVertexArray_create();
            sfVertex vertex1 = {.position = ddmap[i + 0][j + 1], .color = color1};
            sfVertex vertex2 = {.position = ddmap[i + 1][j + 1], .color = color1};
            sfVertex vertex3 = {.position = ddmap[i + 1][j + 0], .color = color1};
            sfVertex vertex4 = {.position = ddmap[i + 0][j + 1], .color = color1};
            sfVertexArray_append(vertex_array, vertex1);
            sfVertexArray_append(vertex_array, vertex2);
            sfVertexArray_append(vertex_array, vertex3);
            sfVertexArray_append(vertex_array, vertex4);
            sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesStrip);
            sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
            sfVertexArray_destroy(vertex_array);
            vertex_array = sfVertexArray_create();
            sfVertex vertex5 = {.position = ddmap[i + 0][j + 1], .color = color1};
            sfVertex vertex6 = {.position = ddmap[i + 1][j + 0], .color = color1};
            sfVertex vertex7 = {.position = ddmap[i + 0][j + 0], .color = color1};
            sfVertex vertex8 = {.position = ddmap[i + 0][j + 1], .color = color1};
            sfVertexArray_append(vertex_array, vertex5);
            sfVertexArray_append(vertex_array, vertex6);
            sfVertexArray_append(vertex_array, vertex7);
            sfVertexArray_append(vertex_array, vertex8);
            sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesStrip);
            sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
            sfVertexArray_destroy(vertex_array);
        }
    }
    return (0);
}
