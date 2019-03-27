/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** brush
*/

#include "include.h"

void elevate(float ** dddmap, float ** dddmap_cpy, sfVector2i compare){
    //  dddmap[compare.x][compare.y] += 2;
  for(int i = 0 ; i < 8 ; i++){
    if (!((compare.x-i > 1 && compare.x+i < 99)&&(compare.y-i > 1 && compare.y+i < 99)))
      break;
    float tmp = -1*(pow(i,2))+3*i+40;
    if (isfinite(tmp)){
    for(int j = -i +1 ; j < i ; j++){
      dddmap[compare.x+j][compare.y+i] += tmp/50;
      dddmap[compare.x-i][compare.y+j] += tmp/50;
      dddmap[compare.x+i][compare.y+j] += tmp/50;
      dddmap[compare.x+j][compare.y-i] += tmp/50;
      dddmap_cpy[compare.x+j][compare.y+i] += tmp/50;
      dddmap_cpy[compare.x-i][compare.y+j] += tmp/50;
      dddmap_cpy[compare.x+i][compare.y+j] += tmp/50;
      dddmap_cpy[compare.x+j][compare.y-i] += tmp/50;
    }
    dddmap[compare.x+i][compare.y+i] += tmp/50;
    dddmap[compare.x][compare.y] -= tmp/50/2;
    dddmap[compare.x-i][compare.y+i] += tmp/50;
    dddmap[compare.x+i][compare.y-i] += tmp/50;
    dddmap[compare.x-i][compare.y-i] += tmp/50;

  }

  }
}

void elevate_3(float ** dddmap, float ** dddmap_cpy, sfVector2i compare){
    //  dddmap[compare.x][compare.y] += 2;
  compare.x -= 4;
  compare.y -= 4;
  float tmp = dddmap[compare.x+4][compare.y+4];
  for(int i = compare.y ; i < compare.y+8 ; i++){
    for(int j = compare.x; j < compare.x+8  ; j++){
      if (j < 1 || j > 99 || i < 1 || i > 99 )
        break;
      dddmap[j][i] = tmp;
      dddmap_cpy[j][i] = tmp;
    }
  }
}

void elevate_2(float ** dddmap, float ** dddmap_cpy, sfVector2i compare){
    //  dddmap[compare.x][compare.y] += 2;
  for(int i = 0 ; i < 8 ; i++){
    if (!((compare.x-i > 1 && compare.x+i < 99)&&(compare.y-i > 1 && compare.y+i < 99)))
      break;
    float tmp = 3*(pow(i,2))+4*i+40;
    if (isfinite(tmp)){
    for(int j = -i +1; j < i ; j++){
      dddmap[compare.x+j][compare.y+i] -= tmp/100;
      dddmap[compare.x-i][compare.y+j] -= tmp/100;
      dddmap[compare.x+i][compare.y+j] -= tmp/100;
      dddmap[compare.x+j][compare.y-i] -= tmp/100;
      dddmap_cpy[compare.x+j][compare.y+i] -= tmp/100;
      dddmap_cpy[compare.x-i][compare.y+j] -= tmp/100;
      dddmap_cpy[compare.x+i][compare.y+j] -= tmp/100;
      dddmap_cpy[compare.x+j][compare.y-i] -= tmp/100;
    }
    dddmap[compare.x+i][compare.y+i] -= tmp/50;
//    dddmap[compare.x][compare.y] += tmp/50/2;
    dddmap[compare.x-i][compare.y+i] -= tmp/50;
    dddmap[compare.x+i][compare.y-i] -= tmp/50;
    dddmap[compare.x-i][compare.y-i] -= tmp/50;
  }
  }
}

void do_brush_up_C(sfRenderWindow* window, float** dddmap, float** dddmap_cpy, double a ,double b, brush_t keys)
{
    sfVector2u sizemap = sfRenderWindow_getSize(window);
    sfVector2f scaling;
    sfVector2i mouse;
    scaling.x = sizemap.x/200.;
    scaling.y = sizemap.y/200.;
    mouse = sfMouse_getPositionRenderWindow(window);
    mouse.x = (mouse.x / scaling.x);
    mouse.y = (mouse.y / scaling.y);
    sfVector2i compare = comparemap(mouse , dddmap_cpy , a , b);
    if (keys.down == 1)
      elevate_2(dddmap,dddmap_cpy,compare);
    if (keys.up == 1)
      elevate(dddmap,dddmap_cpy,compare);
    if (keys.plain == 1)
      elevate_3(dddmap,dddmap_cpy,compare);
}
