#include "knopka.h"
#include "lib.h"
#include "functions.h"
/** @file knopka.c
 *  @brief Файл содержит различные функцию обработки координат мыши
 *
 *
	*@author Nikolaev Denis - den11nik@yandex.ru \n
	*@author Puzko Danila - danilapuzko@mail.ru*/
	/** \fn void knopka(int size_of_matrix, int *Game_on, int *size_settings,int *game_mode, int *game_window, int *count_of_clean, int b[100][100], float bouncer_x, float bouncer_y)
	##Функция обрабатывает координаты нажатия мыши
	##Обработка при нажатии на кнопки
			####Действие,при нажатии на кнопку Start:
		  **  *Переход в режим многократных действий*
			#### Действие,при нажатии на кнопку Step:
		**	*Переход в режим однократного действия*
			#### Действие,при нажатии на кнопку Stop:
		**	*Остановка игрового процесса*
			#### Действие,при нажатии на кнопку Menu:
		**	*Открытие стартового окна*
	##Проверка на попадание координат в игровую ячейку
			Далее идет проверка попадания пользователем в игровые ячейки ,если координаты мыши удовлетворяют
			определенным условиям(пользователь попадает в игровую ячейку,связанную с матрицей b) ТО: \n
			если элемент b был равен 0 ,то он становится равным 1 \n
			если элемент b был равен 1 ,то он становится равным 0 \n
	  \param int b[100][100] буферная матрица
		\param int *count_of_clean  -указатель на счетчик очистки
		\param int *Game_on -указатель на активность цикла
		\param int *size_settings -указатель на рефим меню настроек
		\param int size_of_matrix -размер матрицы
		\param int *game_mode -указатель на игровой режим
		\param float bouncer_x  -координаты по x
		\param float bouncer_y -координаты по y
		\param int *game_window -указатель на режим игрового окна
		\return это void-функция
	*/

void knopka(int size_of_matrix, int *Game_on, int *size_settings, int *game_mode, int *game_window, int *count_of_clean, int b[100][100], float bouncer_x, float bouncer_y)
{
	assert(game_mode != NULL);
	assert(game_window != NULL);
	assert(Game_on != NULL);
	assert(size_settings != NULL);
	assert(count_of_clean != NULL);
	if ((*game_window) == 1) {
		if ((bouncer_y > 0 && bouncer_y < 80) && (bouncer_x > 180 && bouncer_x < 330)) {
			(*game_mode) = 10;
		}
		else if (((bouncer_y > 0 && bouncer_y < 80) && (bouncer_x > 340 && bouncer_x < 490))) {
			(*game_mode) = 1;
		}
		else if ((bouncer_y > 0 && bouncer_y < 80) && (bouncer_x > 500 && bouncer_x < 670)) {
			(*game_mode) = 3;
		}
		else if ((bouncer_y > 0 && bouncer_y < 80) && (bouncer_x > 680 && bouncer_x < 840)) {
			clear(b);
			(*game_mode) = 0;
		}
		else if ((bouncer_y > 525 && bouncer_y < 600) && (bouncer_x > 800 && bouncer_x < 1000)) {
			(*game_window) = 0;
			(*count_of_clean) = 99;
		}
		else if ((bouncer_y > 500 && bouncer_y < 550) && (bouncer_x > 155 && bouncer_x < 260)) {
			clear(b);
			planer(b);
		}
		else if ((bouncer_y > 500 && bouncer_y < 550) && (bouncer_x > 290 && bouncer_x < 380)) {
			clear(b);
			rellay(b);
		}
		else if ((bouncer_y > 500 && bouncer_y < 550) && (bouncer_x > 430 && bouncer_x < 570)) {
			clear(b);
			Twin_Bees(b);
		}
		else if ((bouncer_y > 500 && bouncer_y < 550) && (bouncer_x > 10 && bouncer_x < 120)) {
			random(b, size_of_matrix);
		}
		else {
			blue_or_white(b, size_of_matrix, bouncer_x, bouncer_y);
		}
	}
	if ((*game_window) == 0) {
		if ((bouncer_y > 350 && bouncer_y < 390) && (bouncer_x > 410 && bouncer_x < 600)) {//Описание нажатия кнопки Играть
			(*game_window) = 1;
			(*size_settings) = 0;
			(*count_of_clean) = 99;
			clear(b);
		}
		else if ((bouncer_y > 450 && bouncer_y < 480) && (bouncer_x > 450 && bouncer_x < 550)) {//Описание нажатия кнопки Выход
			(*Game_on) = 0;
		}
	}
}
