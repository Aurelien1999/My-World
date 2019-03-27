/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** pixel
*/

#include "include.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));
    framebuffer->pixels = malloc(sizeof(sfUint8) * 4 * width * height);
    framebuffer->width = width;
    framebuffer->height = height;

    return (framebuffer);
}

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color)
{
    int i = ((framebuffer->width * y + x) * 4);
    framebuffer->pixels[i + 0] = color.r;
    framebuffer->pixels[i + 1] = color.g;
    framebuffer->pixels[i + 2] = color.b;
    framebuffer->pixels[i + 3] = color.a;
}

void draw_background(sfRenderWindow *window,sfColor** background, framebuffer_t *framebuffer)
{
    framebuffer = framebuffer_create(200, 200);
    sfTexture *text = sfTexture_create(200, 200);
    sfSprite *back;
    back = sfSprite_create();

    for(unsigned int i = 0 ; i < 200 ; i++){
        for(unsigned int j = 0 ; j < 200 ; j++){
            my_put_pixel(framebuffer, j, i, background[i][j]);
        }
    }
    sfTexture_updateFromPixels(text, framebuffer->pixels, 200, 200, 0, 0);
    sfSprite_setTexture(back, text, sfTrue);
    sfRenderWindow_drawSprite(window, back, NULL);
}
