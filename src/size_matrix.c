/** @file size_matrix.c
 *  @brief Файл содержит функцию,которая устанавливает размер матрицы
 *
 *
    *@author Nikolaev Denis - den11nik@yandex.ru \n
    *@author Puzko Danila - danilapuzko@mail.ru*/
#include "size_matrix.h"
#include "assert.h"
#define NULL 0
/**  \fn void size_matrix(int *size_of_matrix, float bouncer_x, float bouncer_y)
        *Функция анализирует координаты нажатия мышью в режиме открытых настроек ,и изменяет размер матрицы
    \param int *size_of_matrix -указатель на размер матрицы
    \param float bouncer_x  -координаты по x
    \param float bouncer_y -координаты по y
    \return это void-функция
*/
void size_matrix(int *size_of_matrix, float bouncer_x, float bouncer_y) {
	assert(size_of_matrix!=NULL);
	if ( (bouncer_y > 375 && bouncer_y < 405) && (bouncer_x > 640 && bouncer_x < 850)) {
		(*size_of_matrix )= 11;

	}
	else if (  (bouncer_y > 405 && bouncer_y < 435) && (bouncer_x > 640 && bouncer_x < 850)) {
		(*size_of_matrix) = 21;

	}
	else if (  (bouncer_y > 435 && bouncer_y < 465) && (bouncer_x > 640 && bouncer_x < 850)) {
		(*size_of_matrix) = 31;

	}
	else if (  (bouncer_y > 465 && bouncer_y < 495) && (bouncer_x > 640 && bouncer_x < 850)) {
		(*size_of_matrix) = 41;
	}
	else if (  (bouncer_y > 495 && bouncer_y < 525) && (bouncer_x > 640 && bouncer_x < 850)) {
		(*size_of_matrix) = 99;
	}
	else{}
}
