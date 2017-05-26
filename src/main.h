/** @file main.h
	*@author Nikolaev Denis - den11nik@yandex.ru \n
	*@author Puzko Danila - danilapuzko@mail.ru*/
#ifndef MAIN_H
#define MAIN_H
#define SIZE 100
#define FPS 60 //const float FPS FPS
/** Ширина экрана*/
#define SCREEN_W 1000
/** Высота экрана*/
#define SCREEN_H 600
/**Основная матрица*/
int main_matrix[SIZE][SIZE];
/**Буферная матрица*/
int buffer_matrix[SIZE][SIZE];
const int BOUNCER_SIZE = 32;
int clear(int b[100][100]);//Очистка матрицы b
/** Переменная ,отвечающая за размер матрицы*/
int size_of_matrix = 99;
/** Координата нажатия  оси х*/
float bouncer_x = 0.0;
/**Координаты нажатия  оси у*/
float bouncer_y = 0.0;
/**
   Переменная game_mode отвечает за игровой режим ,если
   game_mode==1 режим шага. \n
   game_mode==10 режим многократных действий. \n
   game_mode==3 режим остановки.
*/
int game_mode = 0;
/**Режим меню выбора размера матрицы(при size_settings=0 меню закрыто,при size_settings=1 меню открыто*/
int size_settings = 0;
/**Game_on = 1 игра активна ,Game_on = 0 игра выключается */
int Game_on = 1;
int count_of_clean = 99;
int planer(int b[100][100]);//Функции прорисовки различных фигур
int rellay(int  b[100][100]);//Функции прорисовки различных фигур
int Twin_Bees(int b[100][100]);//Функции прорисовки различных фигур
/** int game_window Переменная game_window отвечает за открытие определенного окна ,если game_window=0 - стартовое ,game_window=1 -игровое*/
int game_window = 0;
//Функция knopka обрабатывает координаты полученные при нажатии пользователем на экран в режиме игрового окна
void knopka(int size_of_matrix, int *Game_on, int *size_settings, int *game_mode, int *game_window, int *count_of_clean, int b[100][100], float bouncer_x, float bouncer_y);
//Функция size_matrix обрабатывает координаты полученные при нажатии пользователем на экран в режиме настрое размера поля
void size_matrix(int *size_of_matrix, float bouncer_x, float bouncer_y);
//Функция main_algorithm отвечает за главный алгоритм игры (ищет соседей живых клеток ,далее выполняет действия в соответствии с правилами игры )
void main_algorithm(int b[100][100], int a[100][100], int number_of_neighbors, int size_of_matrix, int *game_mode);
int main(int argc, char **argv);
#endif
