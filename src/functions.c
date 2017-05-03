#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
int clear(int b[100][100]);
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
	if (d >size_of_matrix*size_of_matrix - 2 * size_of_matrix) { d = 0; (*game_mode) = 0; }

	//Приравнивание текущей и предыдущей матриц
	for (y = 1; y < size_of_matrix; y++) {
		for (x = 1; x < size_of_matrix; x++)
		{
			b[x][y] = a[x][y];

		}
	}
}
void size_matrix(int *size_of_matrix, float bouncer_x, float bouncer_y) {
	if ( (bouncer_y > 370 && bouncer_y < 405) && (bouncer_x > 640 && bouncer_x < 850)) {
		(*size_of_matrix )= 10;


	}
	else if (  (bouncer_y > 405 && bouncer_y < 435) && (bouncer_x > 640 && bouncer_x < 850)) {
		(*size_of_matrix) = 20;

	}
	else if (  (bouncer_y > 435 && bouncer_y < 465) && (bouncer_x > 640 && bouncer_x < 850)) {
		(*size_of_matrix) = 30;

	}
	else if (  (bouncer_y > 465 && bouncer_y < 495) && (bouncer_x > 640 && bouncer_x < 850)) {
		(*size_of_matrix) = 40;

	}
}
void knopka(int size_of_matrix, int *Game_on, int *size_settings,int *game_mode, int *game_window, int *count_of_clean, int b[100][100], float bouncer_x, float bouncer_y) {
	int randon_number = 0, i = 0, j = 0;
	if ((*game_window) == 1) {
		/*Далее,действие,при нажатии на кнопку Start:
		Переход в режим многократных действий
		*/
		if ((bouncer_y > 0 && bouncer_y < 80) && (bouncer_x > 180 && bouncer_x < 330)) {
			(*game_mode) = 10;
		}
		/*Далее,действие,при нажатии на кнопку Step:
		Переход в режим однократного действия
		*/
		else if (((bouncer_y > 0 && bouncer_y < 80) && (bouncer_x > 340 && bouncer_x < 490))) {
			(*game_mode) = 1;
		}
		/*Далее,действие,при нажатии на кнопку Stop:
		Остановка игрового процесса
		*/
		else if ((bouncer_y > 0 && bouncer_y < 80) && (bouncer_x > 500 && bouncer_x < 670)) {
			(*game_mode) = 3;
		}
		/*Далее,действие,при нажатии на кнопку Clear:
		Обнуление матрицы b
		*/
		else if ((bouncer_y > 0 && bouncer_y < 80) && (bouncer_x > 680 && bouncer_x < 840)) {
			clear(b);
		}
		/*Далее,действие,при нажатии на кнопку Menu:
		Открытие стартового окна
		*/
		else if ((bouncer_y > 525 && bouncer_y < 600) && (bouncer_x > 800 && bouncer_x < 1000)) {
			(*game_window) = 0;
			(*count_of_clean) = 99;
		}
		/*Далее,деяствие,при нажатии на кнопку Planer :
		Пtрвоначальная очиства матрицы b ,далее выполнение функции b1,которая присваивает матрице b нужные значения
		*/
		else if ((bouncer_y > 500 && bouncer_y < 550) && (bouncer_x > 155 && bouncer_x < 260)) {
			clear(b);
			planer(b);
		}
		/*Далее,деяствие,при нажатии на кнопку Rellay :
		Пtрвоначальная очиства матрицы b ,далее выполнение функции b2,которая присваивает матрице b нужные значения
		*/
		else if ((bouncer_y > 500 && bouncer_y < 550) && (bouncer_x > 290 && bouncer_x < 380)) {
			clear(b);
			rellay(b);
		}
		//Кнопка "Twin Bees":
		else if ((bouncer_y > 500 && bouncer_y < 550) && (bouncer_x > 430 && bouncer_x < 570)) {
			clear(b);
			Twin_Bees(b);
		}
		/*Далее,деяствие,при нажатии на кнопку Random :
		Каждой ячейче матрицы b присваивается рандомное значение 0 или 1
		*/
		else if ((bouncer_y > 500 && bouncer_y < 550) && (bouncer_x > 10 && bouncer_x < 120)) {
			srand((unsigned)time(NULL));
			for (j = 1; j < size_of_matrix; j++) {

				for (i = 1; i < size_of_matrix; i++) {

					randon_number = rand() % 2;
					b[i][j] = randon_number;
				}
			}
		}
		/*
		Далее идет проверка попадания пользователем в игровые ячейки ,если координаты мыши удовлетворяют
		определенным условиям(пользователь попадает в игровую ячейку,связанную с матрицей b) ТО:
		если элемент b был равен 0 ,то он становится равным 1
		если элемент b был равен 1 ,то он становится равным 0
		*/
		else {
			int x, y;
			for (y = 1; y < size_of_matrix; y++) {
				if ((bouncer_y > 100 - 160 / size_of_matrix + (400 / size_of_matrix) * y) && (bouncer_y < 100 + 160 / size_of_matrix + (400 / size_of_matrix) * y))
					for (x = 1; x < size_of_matrix; x++)
					{
						if ((bouncer_x > 320 - 160 / size_of_matrix + (400 / size_of_matrix) * x) && (bouncer_x < 320 + 160 / size_of_matrix + (400 / size_of_matrix) * x)) {
							if (b[x][y] == 1) {
								b[x][y] = 0;
							}
							else if ((b[x][y] == 0)) {
								b[x][y] = 1;

							}

						}

					}
			}
		}

	}
	if ((*game_window) == 0) {
		if ((bouncer_y > 350 && bouncer_y < 390) && (bouncer_x > 410 && bouncer_x < 600)) {//Описание нажатия кнопки Играть
			(*game_window) = 1;
			(*size_settings )= 0;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			(*count_of_clean) = 99;
			clear(b);

		}
		if ((bouncer_y > 450 && bouncer_y < 480) && (bouncer_x > 450 && bouncer_x < 550)) {//Описание нажатия кнопки Выход

			(*Game_on) = 0;
		}

	}
}

int planer(int b[100][100])
{
	b[2][1] = 1;
	b[3][2] = 1;
	b[1][3] = 1;
	b[2][3] = 1;
	b[3][3] = 1;

	return b[100][100];
}

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
