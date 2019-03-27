/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** create_loading
*/

 #include "include.h"

 float**create_loading(void){
  float** loading = malloc(sizeof(float*)*300);
  for(int i = 0 ; i < 300 ; i++){
    loading[i] = malloc(sizeof(float)*300);
    for(int j = 0 ; j < 300 ; j++){
      loading[i][j] = 30;
    }
  }
  return(loading);
}