/** @file test_clean.c
* @brief Тест функции clean
*@author Nikolaev Denis - den11nik@yandex.ru \n
    *@author Puzko Danila - danilapuzko@mail.ru
*/
#include "unity.h"
#include "unity_fixture.h"
#include "clean.h"
#define SIZE 100

TEST_GROUP(TestClean);

TEST_GROUP_RUNNER(TestClean)
{
    RUN_TEST_CASE(TestClean, FunctionClean);
}

TEST_SETUP(TestClean)
{
}

TEST_TEAR_DOWN(TestClean)
{
}
/** \fn TEST(TestClean, FunctionClean)
Тестирование функции clean.
Сравнивает две матрицы. Одна очищена вручную, вторая - с помощью функции clean.
*/
TEST(TestClean, FunctionClean)
{
	int a[SIZE][SIZE], b[SIZE][SIZE];
	a[1][1]=0;
	a[1][2]=0;
	a[2][1]=0;
	a[2][2]=0;
	b[1][1]=1;
	b[1][2]=1;
	b[2][1]=1;
	b[2][2]=1;
	clear(b);
	TEST_ASSERT_EQUAL_INT_ARRAY( a, b, 4);
}
