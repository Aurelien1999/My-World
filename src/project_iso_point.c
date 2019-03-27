/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** project_iso_point
*/

#include "include.h"

float scalin = 1.;
sfVector2f project_iso_point(double a, double b, int x, int y, float z)
{
     sfVector2f ddpoint;
     ddpoint.x = (scalin * cos(a) * x - scalin * cos(a) * y + 87);
     ddpoint.y = (scalin * sin(b) * y + scalin * sin(b) * x - z + 105);

     return (ddpoint);
}

sfVector2f project_iso_point_map_map(int x, int y, float z)
{
    sfVector2f ddpoint;
    ddpoint.x = (0.6 *cos(0.8) * x - 0 * 0.6*cos(0.8) * y * 0 + 0);
    ddpoint.y = (0.6 *sin(1.58) * y + 0 * 0.6*sin(1.58) * x - z * 0 + 0);

    return (ddpoint);
}

sfVector2f project_iso_point_l(double a, double b, int x, int y, float z)
{
    sfVector2f ddpoint;
    ddpoint.x = 8*(cos(a) * x - cos(a) * y);
    ddpoint.y = 8*(sin(b) * y + sin(b) * x - z);

    return (ddpoint);
}

sfVector2f project_iso_point_map(int x, int y, float z)
{
    sfVector2f ddpoint;
    ddpoint.x = (2.2 * cos(0.8) * x - 0 * 2.2 * cos(0.8) * y * 0 + 170);
    ddpoint.y = (2.2 * sin(1.58) * y + 0 * 2.2 * sin(1.58) * x - z * 0 + 0);

    return (ddpoint);
}

int scaling()
{
    if (sfKeyboard_isKeyPressed(sfKeyPageDown) == sfTrue)
        scalin -= 0.1;
    if (sfKeyboard_isKeyPressed(sfKeyPageUp) == sfTrue)
        scalin += 0.1;
}