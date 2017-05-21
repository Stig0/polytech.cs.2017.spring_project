/** @file functions.c
 *  @brief Файл содержит различные функции проекта
 *
 *
	*@author Nikolaev Denis - den11nik@yandex.ru \n
	*@author Puzko Danila - danilapuzko@mail.ru*/
#include "lib.h"
#include "functions.h"
int clear(int b[100][100]);
/** \fn void main_algorithm(int b[100][100], int a[100][100], int number_of_neighbors, int size_of_matrix,int *game_mode)
Поле представляет собой матрицу(массив) ,где каждая ячейка имеет свой номер.
Если клетка белая ,то значение соответствующего элемента массива 0,если черная ,то 1 .
Процесс игры будет представлять цикл при котором программа сравнивает каждый элемент массива
с его восьмью  соседями ,и от того сколько соседей она обнаружит изменяет массив-близнец.
Программа оставит 1 (при наличии 2 или 3 соседей),либо заменит на 0.
За один игровой шаг компьютер пробежит все ячейки.
После того   как шаг завершится  у нас будет два массива: массив 1 с исходными данными
и массив 2 с данными после первого шага , экран связан с массивом 2  .
После этого элементы массива 1 заменят на элементы  массива 2
Цикл будет повторяться при включенной кнопке «Старт»;
	\param int b[100][100] -буферная матрица
	\param int a[100][100] -основная матрица
	\param int number_of_neighbors -число соседей
	\param int size_of_matrix -размер матрицы
	\param int *game_mode -указатель на игровой режим
	\return это void-функция
*/
void main_algorithm(int b[100][100], int a[100][100], int number_of_neighbors, int size_of_matrix, int *game_mode) {
	int  i = 0, j = 0, x = 0, y = 0;

	for (j = 1; j < size_of_matrix; j++) {
		for (i = 1; i < size_of_matrix; i++) {
			//Поиск живых клеток,среди 8 соседей
			if (b[i - 1][j - 1] == 1) number_of_neighbors++;
			if (b[i][j - 1] == 1) number_of_neighbors++;
			if (b[i + 1][j - 1] == 1) number_of_neighbors++;
			if (b[i - 1][j] == 1) number_of_neighbors++;
			if (b[i + 1][j] == 1) number_of_neighbors++;
			if (b[i - 1][j + 1] == 1) number_of_neighbors++;
			if (b[i][j + 1] == 1) number_of_neighbors++;
			if (b[i + 1][j + 1] == 1) number_of_neighbors++;
			if (b[i][j] == 1)
			{
				if ((number_of_neighbors == 2) || (number_of_neighbors == 3))a[i][j] = 1;//Если клетка жива и 2 или 3 соседа, клетка живет
				else {
					a[i][j] = 0;//Если нет,то умирает

				}
			}
			if (b[i][j] == 0) {
				if ((number_of_neighbors == 3)) {
					a[i][j] = 1;//Если клетка мертва и 3 соседа, клетка оживает

				}
				else a[i][j] = 0;//Если нет,то остается мертвой
			}
			number_of_neighbors = 0;

		}
	}
	//Часть кода,отвечающая за автоотановку игры при совпадении текущей и предыдущей матриц
	int d = 0;
	for (y = 1; y < size_of_matrix; y++) {
		for (x = 1; x < size_of_matrix; x++)
		{
			if (b[x][y] == a[x][y]) d++;


		}
	}
	if (d > size_of_matrix*size_of_matrix - 2 * size_of_matrix) { d = 0; (*game_mode) = 0; }

	//Приравнивание текущей и предыдущей матриц
	for (y = 1; y < size_of_matrix; y++) {
		for (x = 1; x < size_of_matrix; x++)
		{
			b[x][y] = a[x][y];

		}
	}
}
/** \fn planer(int b[100][100])
Функция присваивающая определенные значения матрице b для отрисовки фигуры planer
  \param int b[100][100] буферная матрица
   \return  буферную матрицу с определенными элементами

*/
int planer(int b[100][100])
{
	b[2][1] = 1;
	b[3][2] = 1;
	b[1][3] = 1;
	b[2][3] = 1;
	b[3][3] = 1;

	return b[100][100];
}
/** \fn planer(int b[100][100])
Функция присваивающая определенные значения матрице b для отрисовки фигуры planer
\param int b[100][100] буферная матрица
\param int size_of_matrix размер матрицы
\return  буферную матрицу со случайными элементами

*/
int random(int b[100][100], int size_of_matrix)
{
	int randon_number = 0, i = 0, j = 0;;
	srand((unsigned)time(NULL));
	for (j = 1; j < size_of_matrix; j++) {
		for (i = 1; i < size_of_matrix; i++) {
			randon_number = rand() % 2;
			b[i][j] = randon_number;
		}
	}
	return b[100][100];
}
/** \fn int blue_or_white(int b[100][100],int size_of_matrix, float bouncer_x, float bouncer_y)
{
Функция присваивающая определенные значения матрице b для отрисовки фигуры rellay
\param int b[100][100] буферная матрица
\param int size_of_matrix размер матрицы
\param float bouncer_x  -координаты по x
\param float bouncer_y -координаты по y
\return  буферную матрицу с определенными элементами
*/
int blue_or_white(int b[100][100], int size_of_matrix, float bouncer_x, float bouncer_y)
{
	int x, y;
	for (y = 1; y < size_of_matrix; y++) {
		if ((bouncer_y > 100 - 160 / size_of_matrix + (400 / size_of_matrix) * y) && (bouncer_y < 100 + 160 / size_of_matrix + (400 / size_of_matrix) * y))
			for (x = 1; x < size_of_matrix; x++)
			{
				if ((bouncer_x > 320 - 160 / size_of_matrix + (400 / size_of_matrix) * x) && (bouncer_x < 320 + 160 / size_of_matrix + (400 / size_of_matrix) * x)) {
					if (b[x][y] == 1) {
						b[x][y] = 0;
					}
					else
					{
						b[x][y] = 1;
					}
				}
			}
	}
	return b[100][100];
}
/** \fn int rellay(int b[100][100])
Функция присваивающая определенные значения матрице b для отрисовки фигуры rellay
  \param int b[100][100] буферная матрица
  \return  буферную матрицу с определенными элементами
*/
int rellay(int b[100][100])
{
	b[5][9] = 1;
	b[6][9] = 1;
	b[7][9] = 1;
	b[8][9] = 1;
	b[9][9] = 1;
	b[11][9] = 1;
	b[12][9] = 1;
	b[13][9] = 1;
	b[14][9] = 1;
	b[15][9] = 1;
	b[10][5] = 1;
	b[10][6] = 1;
	b[10][7] = 1;
	b[10][8] = 1;
	b[10][10] = 1;
	b[10][11] = 1;
	b[10][12] = 1;
	b[10][13] = 1;
	b[9][14] = 1;
	b[11][14] = 1;
	b[9][4] = 1;
	b[11][4] = 1;
	b[7][5] = 1;
	b[8][6] = 1;
	b[8][7] = 1;
	b[6][7] = 1;
	b[7][7] = 1;
	b[6][11] = 1;
	b[7][11] = 1;
	b[8][11] = 1;
	b[8][12] = 1;
	b[7][13] = 1;
	b[13][5] = 1;
	b[12][6] = 1;
	b[12][7] = 1;
	b[13][7] = 1;
	b[14][7] = 1;
	b[12][11] = 1;
	b[13][11] = 1;
	b[14][11] = 1;
	b[12][12] = 1;
	b[13][13] = 1;

	return b[100][100];
}

/** \fn int Twin_Bees(int b[100][100])
Функция присваивающая определенные значения матрице b для отрисовки фигуры Twin_Bees
  \param int b[100][100] буферная матрица
   \return  буферную матрицу с определенными элементами
*/
int Twin_Bees(int b[100][100])
{
	b[7][12] = 1;
	b[8][12] = 1;
	b[9][12] = 1;
	b[10][12] = 1;
	b[11][12] = 1;
	b[12][12] = 1;
	b[7][13] = 1;
	b[8][13] = 1;
	b[9][13] = 1;
	b[10][13] = 1;
	b[10][14] = 1;
	b[11][14] = 1;
	b[12][15] = 1;
	b[13][15] = 1;
	b[13][14] = 1;
	b[13][17] = 1;
	b[12][17] = 1;
	b[13][18] = 1;
	b[11][18] = 1;
	b[10][18] = 1;
	b[10][19] = 1;
	b[10][20] = 1;
	b[11][20] = 1;
	b[12][20] = 1;
	b[18][20] = 1;
	b[19][20] = 1;
	b[20][20] = 1;
	b[21][20] = 1;
	b[18][19] = 1;
	b[19][19] = 1;
	b[21][19] = 1;
	b[21][18] = 1;
	b[20][17] = 1;
	b[19][17] = 1;
	b[19][15] = 1;
	b[20][15] = 1;
	b[21][14] = 1;
	b[21][13] = 1;
	b[21][12] = 1;
	b[20][12] = 1;
	b[19][12] = 1;
	b[18][12] = 1;
	b[18][13] = 1;
	b[19][13] = 1;
	b[34][12] = 1;
	b[35][12] = 1;
	b[34][13] = 1;
	b[35][13] = 1;
	return b[100][100];
}
