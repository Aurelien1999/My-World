/*
** EPITECH PROJECT, 2019
** ...
** File description:
** ...
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <SFML/Graphics/Export.h>
#include <math.h>
#define MAP_X 100
#define MAP_Y 100
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307

typedef struct brush_t {
  int up;
  int down;
  int plain;
}brush_t;

void draw_rectangle_tiles(sfRenderWindow *window, int nb, brush_t keys);

float **click_up(sfRenderWindow *, float **);

sfVector2f **create_2d_map_map(float **dddmap);

sfVector2f project_iso_point(double a, double b, int x, int y, float z);

sfVector2f project_iso_point_l(double a, double b, int x, int y, float z);

float Interpolate(float a, float b, float x);

float Noise(int x, int y);

float SmoothedNoise_1(float x, float y);

float InterpolatedNoise_1(float x, float y , float pas3D);

float PerlinNoise_2D(float x, float y , double nb , float pas3D);

sfVector2f **create_2d_map_l(double a, double b, float **dddmap);

sfVector2f **create_2d_map(double a, double b, float **dddmap);

float **create_map(float **ddd_map, int increase , int increase2);

sfVector3f normalise(sfVector3f normal_v);

sfVector3f normal(float **dddmap , int i , int j);

float scal(sfVector3f norm);

int create_random(void);

float **wave(float **ddmap , float inc, int **co_map);

float **wave_l(float **ddmap , int inc, int **co_map);

float **create_water(float **water_map);

float **create_water_l(float **water_map);

sfColor **create_background_l(sfColor ** background , int w);

sfColor **create_background(sfColor ** background);

sfColor **create_background2(sfColor ** background, float o);

sfVertexArray *create_line(int i, int j, sfVector2f **ddmap , float **dddmap, int **co_map);

sfVertexArray *create_line_u(int i, int j, sfVector2f **ddmap , float **dddmap);

int draw_2d_map(sfRenderWindow *window, sfVector2f **ddmap , float **dddmap , int **co_map, int color_w);

int draw_2d_map_u(sfRenderWindow *window, sfVector2f **ddmap , float **dddmap);

int draw_2d_map_map(sfRenderWindow *window, sfVector2f **ddmap , float **dddmap);

int **create_co_map(float **dddmap);

void elevate(float **dddmap, float **dddmap_cpy, sfVector2i compare);

void elevate_2(float **dddmap, float **dddmap_cpy, sfVector2i compare);

void do_brush_up(sfRenderWindow* window, float **dddmap, float **dddmap_cpy, int **co_map, double a , double b);

void do_brush_up_C(sfRenderWindow* window, float **dddmap, float **dddmap_cpy, double a , double b,brush_t keys);

float compare_tmp(float tmp3 , sfVector2i * tmp, float average , int  i , int j);

sfVector2i comparemap(sfVector2i iso_mouse , float **dddmap_cpy, double a , double b);

float compare_tmp(float tmp3 , sfVector2i * tmp, float average , int  i , int j);

float compare_tmp(float tmp3 , sfVector2i * tmp, float average , int  i , int j);

sfVector2f getisoposmouse(int x, int y, float z);

float **create_board(float **dddmap);

float **create_loading(void);

int scaling();

void elevate_3(float ** dddmap, float ** dddmap_cpy, sfVector2i compare);

sfVector2f project_iso_point_map(int x, int y, float z);

sfVector2f **create_2d_map_map_map(float **dddmap);

sfVector2f project_iso_point_map_map(int x, int y, float z);

sfColor reacteFont(void);

int my_supergetnbr(char *str, int i);

int my_getnbr(char *str);

char *my_revstr(char *str);

int my_strlen(char *const str);

void my_swap(char *a, char *b);

char *my_itoa(int nb);

void create_file_and_write_seed(int inc);

char *generate_map(int ac, char **av);

int upload(int ac, char **av);

float **copy_map(float **dddmap);

typedef struct rotation {
    int x;
    int y;
}rotation_t;

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_
struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};
typedef struct framebuffer framebuffer_t;
#endif

void draw_background(sfRenderWindow *window, sfColor** background, framebuffer_t *framebuffer);

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color);
