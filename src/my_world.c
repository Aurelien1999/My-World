/*
** EPITECH PROJECT, 2019
** ..
** File description:
** ..
*/

#include "include.h"

void draw_info_text(sfRenderWindow *window, sfFont* font)
{
  sfText* info_text;
  info_text = sfText_create();
  sfText_setString(info_text, "INFO :\n. Press R to reload a\n diffrent map\n\n. Press S to save seed\nas a txt file\n\n. to load seed execute\n the program with\n seed as argument\nexemple :\n ./my_word seed.txt");
  sfText_setFont(info_text, font);
  sfText_setCharacterSize(info_text, 150);
  sfText_setColor(info_text,sfWhite);
  sfText_scale(info_text,(sfVector2f){0.02,0.04});
  sfText_setPosition(info_text, (sfVector2f){171, 79});
  sfRenderWindow_drawText(window, info_text, NULL);
}

void draw_text(sfRenderWindow *window, sfFont* font)
{
  sfText* info_text;
  info_text = sfText_create();
  sfText_setString(info_text, "   BRUSH UP");
  sfText_setFont(info_text, font);
  sfText_setCharacterSize(info_text, 150);
  sfText_setColor(info_text,sfBlue);
  sfText_scale(info_text,(sfVector2f){0.02,0.04});
  sfText_setPosition(info_text, (sfVector2f){175, 19});
  sfRenderWindow_drawText(window, info_text, NULL);
  sfText_setString(info_text, "BRUSH DOWN");
  sfText_setPosition(info_text, (sfVector2f){176, 39});
  sfRenderWindow_drawText(window, info_text, NULL);
  sfText_setString(info_text, "      LEVEL");
  sfText_setPosition(info_text, (sfVector2f){176, 59});
  sfRenderWindow_drawText(window, info_text, NULL);
  draw_info_text(window, font);
}

void manege_keys(int brush_up, int brush_down, int brush_plain , brush_t *keys)
{
    keys -> up = 0;
    keys -> down = 0;
    keys -> plain = 0;
    if (brush_up == 1){
        keys -> up = 1;
    }
    if (brush_down == 1){
        keys -> down = 1;
    }
    if (brush_plain == 1){
        keys -> plain = 1;
  }
}

void manege_mouse(sfRenderWindow *window, float **dddmap, float **dddmap_cpy, double a, double b, brush_t *keys)
{
    sfVector2u sizemap = sfRenderWindow_getSize(window);
    sfVector2f scaling;
    sfVector2i mouse;
    scaling.x = sizemap.x/200.;
    scaling.y = sizemap.y/200.;
    mouse = sfMouse_getPositionRenderWindow(window);
    mouse.x = (mouse.x / scaling.x);
    mouse.y = (mouse.y / scaling.y);
    if (mouse.x < 170){
        do_brush_up_C(window,dddmap,dddmap_cpy,a,b,*keys);
        return;
    }
    if (mouse.x >= 175 && mouse.x <= 195 && mouse.y >= 20 && mouse.y <=26)
      manege_keys(1, 0, 0,keys);
    if (mouse.x >= 175 && mouse.x <= 195 && mouse.y >= 40 && mouse.y <=46)
      manege_keys(0, 1, 0,keys);
    if (mouse.x >= 175 && mouse.x <= 195 && mouse.y >= 60 && mouse.y <=66)
      manege_keys(0, 0, 1,keys);

}

int main (int ac, char **av)
{
    srand(time(NULL));
    int increase = rand()%1000;
    int increase2 = increase;
    if (ac == 2) {
        increase = upload(ac, av);
        increase2 = upload(ac, av);
    }
    brush_t keys;
    float **dddmap = create_map(dddmap,increase,increase2);
    float **cardmap = create_map(dddmap, increase, increase2);
    float **cardmapmap = create_map(dddmap, increase, increase2);
    float **dddmap_cpy = copy_map(dddmap);
    dddmap_cpy = create_board(dddmap_cpy);
    dddmap = create_water(dddmap);
    int ** co_map = create_co_map(dddmap);
    sfVideoMode mode = {200, 200, 32};
    sfRenderWindow* window;
    sfEvent event;
    double a = 0.8;
    sfFont* font = sfFont_createFromFile("ttf/FoglihtenNo04-070.otf");
    sfText* loading_text;
    loading_text = sfText_create();
    sfText_setString(loading_text, "\n    MY INCREADIBLE WORLD");
    sfText_setFont(loading_text, font);
    sfText_setCharacterSize(loading_text, 150);
    sfText_setColor(loading_text,sfRed);
    sfText_scale(loading_text,(sfVector2f){0.1,0.2});
    double b = 0.4;
    sfColor w = {10, 0 , 20, 255};
    framebuffer_t *framebuffer = NULL;
    rotation_t *rotation = NULL;
    sfVector2u sizemap;
    int sce = 1;
    float o = 0;
    float** loading_map = create_loading();
    loading_map = create_water(loading_map);
    window = sfRenderWindow_create(mode, "My world", sfResize | sfClose, NULL);
    sfVector2f **iso_map = create_2d_map(a , b, dddmap);
    sfVector2f **iso_map_u = create_2d_map(a , b, dddmap_cpy);
    sfVector2f **iso_map_l = create_2d_map(a , b, loading_map);
    sfVector2f **iso_map_map = create_2d_map_map(cardmap);
    sfVector2f **iso_map_map_map  = create_2d_map_map_map(cardmap);
    co_map = create_co_map(loading_map);
    sfColor ** background = create_background_l(background,30);
    int boo = 0;
    float i = 0;

        sfRenderWindow_setFramerateLimit(window,40 );
        while (sfRenderWindow_isOpen(window)){
            if (sfRenderWindow_pollEvent(window, &event)){
                if (event.type == sfEvtClosed)
                    sfRenderWindow_close(window);
                if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
                    sfRenderWindow_close(window);
            }
            if(sce == 1){
                // background = create_background_l(background,i);
                // draw_background(window, background , framebuffer);
                sfText_setColor(loading_text,reacteFont());
                loading_map = wave_l(loading_map,boo++, co_map);
                iso_map_l = create_2d_map_l(a , b, loading_map);
                draw_2d_map(window, iso_map_l, loading_map , co_map,0);
                sfRenderWindow_drawText(window, loading_text, NULL);
                sfRenderWindow_display(window);
                sfRenderWindow_clear(window, (sfColor) {22, 99, 50, 255});
                o+=0.3;
                if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
                    sce = 0;
            }
            if (sce == 0) {
                co_map = create_co_map(dddmap);
                if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue){
                    manege_mouse(window,dddmap,dddmap_cpy,a,b,&keys);
                }
                if (sfKeyboard_isKeyPressed(sfKeyF) == sfTrue)
                    b += 0.02;
                if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue){
                  increase += 2;
                  dddmap = create_map(dddmap, increase , increase2);
                  dddmap_cpy = copy_map(dddmap);
                  dddmap_cpy = create_board(dddmap_cpy);
                  dddmap = create_water(dddmap);
                  co_map = create_co_map(dddmap);
                }
                if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue){
                  increase -= 2;
                  dddmap = create_map(dddmap, increase , increase2);
                  dddmap_cpy = copy_map(dddmap);
                  dddmap_cpy = create_board(dddmap_cpy);
                  dddmap = create_water(dddmap);
                  co_map = create_co_map(dddmap);
                }
                if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue){
                  increase2 += 2;
                  dddmap = create_map(dddmap, increase , increase2);
                  dddmap_cpy = copy_map(dddmap);
                  dddmap_cpy = create_board(dddmap_cpy);
                  dddmap = create_water(dddmap);
                  co_map = create_co_map(dddmap);
                }
                if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue){
                  increase2 -= 2;
                  dddmap = create_map(dddmap, increase , increase2);
                  dddmap_cpy = copy_map(dddmap);
                  dddmap_cpy = create_board(dddmap_cpy);
                  dddmap = create_water(dddmap);
                  co_map = create_co_map(dddmap);
                }
                if(sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
                    b -= 0.02;
                if (sfKeyboard_isKeyPressed(sfKeyR) == sfTrue) {
                    increase = rand()%10000;
                    increase2 = rand()%10000;
                    dddmap = create_map(dddmap, increase,increase2);
                    dddmap_cpy = copy_map(dddmap);
                    dddmap_cpy = create_board(dddmap_cpy);
                    dddmap = create_water(dddmap);
                    co_map = create_co_map(dddmap);
                    cardmap = create_map(dddmap, increase, increase2);
                }
                if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
                    create_file_and_write_seed(increase);
                scaling();
        sizemap.x = 1600;
        sizemap.y = 900;
        iso_map_u = create_2d_map(a , b, dddmap_cpy);
        iso_map = create_2d_map(a , b , dddmap);
        dddmap = create_water(dddmap);
        co_map = create_co_map(dddmap);
        dddmap = wave(dddmap,i, co_map);
        draw_background(window, background , framebuffer);
        draw_2d_map_u(window, iso_map_u , dddmap_cpy);
        draw_2d_map_map(window, iso_map_map , cardmap);
        draw_2d_map(window, iso_map_map_map,dddmap, co_map, 1);
        draw_2d_map(window, iso_map, dddmap , co_map , 0);
        draw_rectangle_tiles(window,0,keys);
        draw_rectangle_tiles(window,20,keys);
        draw_rectangle_tiles(window,40,keys);
        draw_text(window,font);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, (w));
        i+= 0.18;
            }
        }
    return (0);
}
