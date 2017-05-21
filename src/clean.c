/** @file clean.c
 *  @brief Функция очистки буферной матрицы
 *
 *
	*@author Nikolaev Denis - den11nik@yandex.ru \n
	*@author Puzko Danila - danilapuzko@mail.ru*/
#include "clean.h"
	/** \fn int clear(int b[100][100])
	Функция присваивает всем элементам матрицы b значения 0,чтобы очистить игровое поле
		\param int b[100][100] -буферная матрица
		\return Обнуленную буферную матрицу
	*/
int clear(int b[100][100]) {
	int i, j = 0;
	int size_of_matrix = 100;
	for (j = 0; j < size_of_matrix; j++) {
		for (i = 0; i < size_of_matrix; i++) {
			b[i][j] = 0;
		}
	}
	return b[100][100];
}
