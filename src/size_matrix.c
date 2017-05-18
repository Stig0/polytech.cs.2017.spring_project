#include "size_matrix.h"
/**  \fn void size_matrix(int *size_of_matrix, float bouncer_x, float bouncer_y)
        *Функция анализирует координаты нажатия мышью в режиме открытых настроек ,и изменяет размер матрицы

*/
void size_matrix(int *size_of_matrix, float bouncer_x, float bouncer_y) {
	if ( (bouncer_y > 370 && bouncer_y < 405) && (bouncer_x > 640 && bouncer_x < 850)) {
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
}
