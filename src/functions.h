#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void main_algorithm(int b[100][100], int a[100][100], int number_of_neighbors, int size_of_matrix, int *game_mode);
int clear(int b[100][100]);
int planer(int b[100][100]);
int rellay(int b[100][100]);
int Twin_Bees(int b[100][100]);
int blue_or_white(int b[100][100], int size_of_matrix, float bouncer_x, float bouncer_y);
int random(int b[100][100], int size_of_matrix);
#endif