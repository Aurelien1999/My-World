/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** shader
*/

#include "include.h"

sfVector3f normalise(sfVector3f normal_v)
{
    float norm = sqrt(pow(normal_v.x,2)+pow(normal_v.y,2)+pow(normal_v.z,2));

    normal_v.x /= norm;
    normal_v.y /= norm;
    normal_v.z /= norm;
    return(normal_v);
}

sfVector3f normal(float** dddmap , int i , int j)
{
    sfVector3f normal_v1;
    sfVector3f normal_v2;
    sfVector3f normal_v;

    normal_v1.x = ((i+1) - i);
    normal_v1.y = ((j+1) - j);
    normal_v1.z = ((dddmap[j+1][i+1]) - dddmap[j][i]);
    normal_v2.x = (i-i);
    normal_v2.y = ((j+1)-j);
    normal_v2.z = (dddmap[j+1][i] - dddmap[j][i]);
    normal_v.x = (normal_v1.x * normal_v2.x);
    normal_v.y = (normal_v1.y * normal_v2.y);
    normal_v.z = (normal_v1.z * normal_v2.z);
    normal_v = normalise(normal_v);
    return(normal_v);
}

float scal(sfVector3f norm)
{
    float r = norm.x*(1) + norm.y*0 + norm.z*((float)1);

    return(0.5+((r+2)/2)/2);
}