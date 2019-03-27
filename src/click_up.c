/*
** EPITECH PROJECT, 2019
** ..
** File description:
** .
*/
#include "include.h"

float** click_up(sfRenderWindow *window, float **dddmap)
{
    sfVector2i pos;
    pos = sfMouse_getPositionRenderWindow(window);
    int a  = 0;
    int b = 0;
    a = (int)((pos.x - 100 + cos(0.6) * 50) / cos(0.6));
    a = a%100;
    printf("%d\n",a);
    if (a >= 0 && a <= 100){
      printf("uyzeaizhdiauzhd\n");
      dddmap[50][a] += 10;
    }
    return (dddmap);
}
