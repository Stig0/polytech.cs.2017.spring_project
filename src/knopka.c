#include "knopka.h"
#include "lib.h"
#include "functions.h"
void knopka(int size_of_matrix, int *Game_on, int *size_settings,int *game_mode, int *game_window, int *count_of_clean, int b[100][100], float bouncer_x, float bouncer_y)
 {

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
			*game_mode=0;
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
			(*count_of_clean) = 99;
			clear(b);

		}
		if ((bouncer_y > 450 && bouncer_y < 480) && (bouncer_x > 450 && bouncer_x < 550)) {//Описание нажатия кнопки Выход

			(*Game_on) = 0;
		}

	}
}
