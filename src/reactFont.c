/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** reactFont
*/

#include "include.h"

sfColor reacteFont(void)
{
  static int a = 0;
  static int z = 245;
  sfColor color = {255,0,0,z};
  if (a == 0)
    z-=4;
  else
    z+=4;
  if (z <15)
    a = 1;
  if (z > 245)
    a = 0;
  return(color);
}