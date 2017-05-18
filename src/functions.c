#include "lib.h"
#include "functions.h"
int clear(int b[100][100]);
/**Поле представляет собой матрицу(массив) ,где каждая ячейка имеет свой номер.
Если клетка белая ,то значение соответствующего элемента массива 0,если черная ,то 1 .
Процесс игры будет представлять цикл при котором программа сравнивает каждый элемент массива
с его восьмью  соседями ,и от того сколько соседей она обнаружит изменяет массив-близнец.
Программа оставит 1 (при наличии 2 или 3 соседей),либо заменит на 0.
За один игровой шаг компьютер пробежит все ячейки.
После того   как шаг завершится  у нас будет два массива: массив 1 с исходными данными
и массив 2 с данными после первого шага , экран связан с массивом 2  .
После этого элементы массива 1 заменят на элементы  массива 2
Цикл будет повторяться при включенной кнопке «Старт»;
*/
void main_algorithm(int b[100][100], int a[100][100], int number_of_neighbors, int size_of_matrix,int *game_mode) {
	int  i = 0, j = 0,x=0,y=0;

	for (j = 1; j < size_of_matrix; j++) {
		for (i = 1; i <size_of_matrix; i++) {
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
	if (d >size_of_matrix*size_of_matrix-2*size_of_matrix) { d = 0; (*game_mode) = 0; }

	//Приравнивание текущей и предыдущей матриц
	for (y = 1; y < size_of_matrix; y++) {
		for (x = 1; x < size_of_matrix; x++)
		{
			b[x][y] = a[x][y];

		}
	}
}
