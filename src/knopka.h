/** @file knopka.h
    *@author Nikolaev Denis - den11nik@yandex.ru \n
    *@author Puzko Danila - danilapuzko@mail.ru*/
#ifndef KNOPKA_H
#define KNOPKA_H
#define SIZE 100
int clear(int b[SIZE][SIZE]);
void knopka(int size_of_matrix, int *Game_on, int *size_settings, int *game_mode, int *game_window, int *count_of_clean, int b[SIZE][SIZE], float bouncer_x, float bouncer_y);
#endif
