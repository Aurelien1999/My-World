/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** getisoposmouse
*/

#include "include.h"

sfVector2f getisoposmouse(int x, int y, float z)
{
    sfVector2f ddpoint;
    ddpoint.x = cos(0.8) * x - cos(0.8) * y + 100;
    ddpoint.y = sin(0.4) * y + sin(0.4) * x - z + 100;

    return (ddpoint);
}
