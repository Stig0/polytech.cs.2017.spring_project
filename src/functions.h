/** @file functions.h
    *@author Nikolaev Denis - den11nik@yandex.ru \n
    *@author Puzko Danila - danilapuzko@mail.ru*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define SIZE 100
void main_algorithm(int b[SIZE][SIZE], int a[SIZE][SIZE], int number_of_neighbors, int size_of_matrix, int *game_mode);
int clear(int b[SIZE][SIZE]);
int planer(int b[SIZE][SIZE]);
int rellay(int b[SIZE][SIZE]);
int Twin_Bees(int b[SIZE][SIZE]);
int blue_or_white(int b[SIZE][SIZE], int size_of_matrix, float bouncer_x, float bouncer_y);
int random(int b[SIZE][SIZE], int size_of_matrix);
#endif
