/** @file test_clean.c
* @brief Тест функции clean
*/
#include "unity.h"
#include "unity_fixture.h"
#include "clean.h"


TEST_GROUP(TestClean);

TEST_GROUP_RUNNER(TestClean)
{
    RUN_TEST_CASE(TestClean, FuncionClean);
}

TEST_SETUP(TestClean)
{
}

TEST_TEAR_DOWN(TestClean)
{
}
/** \fn TEST(TestClean, FucntionClean)
Тестирование функции clean.
Сравнивает две матрицы. Одна очищена вручную, вторая - с помощью функции clean.
*/
TEST(TestClean, FuncionClean)
{
	int a[100][100], b[100][100];
	int i=0, j=0;
	for (j = 0; j < 100; j++) {
		for (i = 0; i < 100; i++) {
			a[i][j] = 0;
		}
	}
	clear(b);


	TEST_ASSERT_EQUAL_INT_ARRAY( a, b, 10000);


}
