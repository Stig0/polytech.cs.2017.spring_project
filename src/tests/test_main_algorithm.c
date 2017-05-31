/** @file test_main_algorithm.c
* @brief Тест главного алгоритма игры
*@author Nikolaev Denis - den11nik@yandex.ru \n
    *@author Puzko Danila - danilapuzko@mail.ru
*/
#include "functions.h"
#include "unity.h"
#include "unity_fixture.h"
#define SIZE 100

TEST_GROUP(TestMainAlgorithm);

TEST_GROUP_RUNNER(TestMainAlgorithm)
{
    RUN_TEST_CASE(TestMainAlgorithm, mainalgorithm1);
    RUN_TEST_CASE(TestMainAlgorithm, mainalgorithm2);
    RUN_TEST_CASE(TestMainAlgorithm, mainalgorithm3);
}

TEST_SETUP(TestMainAlgorithm)
{
}

TEST_TEAR_DOWN(TestMainAlgorithm)
{
}
/** \fn TEST(TestMainAlgorithm, mainalgorithm1)
Тестирование главного алгоритма.
Сравнивает две матрицы. Шаг(ход) в первой матрице сделан вручную, во второй - с помощью тестируемого алгоритма.
*/
TEST(TestMainAlgorithm, mainalgorithm1)
{
    int a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE];
    int i, j = 0, number = 0, game_mode = 1;
    int size_of_matrix = 100;
    for (j = 0; j < size_of_matrix; j++) {
        for (i = 0; i < size_of_matrix; i++) {
            b[i][j] = 0;
            a[i][j] = 0;
            c[i][j] = 0;
        }
    }
    b[3][3] = 1;
    b[2][3] = 1;
    b[3][2] = 1;

    main_algorithm(b, a, number, size_of_matrix, &game_mode);
    c[3][3] = 1;
    c[2][2] = 1;
    c[2][3] = 1;
    c[3][2] = 1;
    TEST_ASSERT_EQUAL_INT_ARRAY(a, c, 10000);
}
/** \fn TEST(TestMainAlgorithm, mainalgorithm2)
Аналогичный первому тест. Сравнивается шаг с иными начальными положениями "живых" клеток.
*/
TEST(TestMainAlgorithm, mainalgorithm2)
{
    int a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE];
    int i, j = 0, number = 0, game_mode = 1;
    int size_of_matrix = 100;
    for (j = 0; j < size_of_matrix; j++) {
        for (i = 0; i < size_of_matrix; i++) {
            b[i][j] = 0;
            a[i][j] = 0;
            c[i][j] = 0;
        }
    }
    b[3][3] = 1;
    b[2][3] = 1;
    b[4][3] = 1;

    main_algorithm(b, a, number, size_of_matrix, &game_mode);
    c[3][3] = 1;
    c[3][2] = 1;
    c[3][4] = 1;
    TEST_ASSERT_EQUAL_INT_ARRAY(a, c, 10000);
}
/** \fn TEST(TestMainAlgorithm, mainalgorithm3)
Аналогичный первому тест. Сравнивается шаг с иными начальными положениями "живых" клеток.
*/
TEST(TestMainAlgorithm, mainalgorithm3)
{
    int a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE];
    int i, j = 0, number = 0, game_mode = 1;
    int size_of_matrix = 100;
    for (j = 0; j < size_of_matrix; j++) {
        for (i = 0; i < size_of_matrix; i++) {
            b[i][j] = 0;
            a[i][j] = 0;
            c[i][j] = 0;
        }
    }
    b[2][1] = 1;
    b[3][2] = 1;
    b[3][3] = 1;
    b[2][3] = 1;
    b[1][3] = 1;

    main_algorithm(b, a, number, size_of_matrix, &game_mode);
    c[1][2] = 1;
    c[3][2] = 1;
    c[2][3] = 1;
    c[2][4] = 1;
    c[3][3] = 1;
    TEST_ASSERT_EQUAL_INT_ARRAY(a, c, 10000);
}
