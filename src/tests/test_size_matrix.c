/** @file test_size_matrix.c
* @brief Тест функции size_matrix
*/
#include "unity.h"
#include "unity_fixture.h"
#include "size_matrix.h"

TEST_GROUP(TestSizeMatrix);

TEST_GROUP_RUNNER(TestSizeMatrix)
{
    RUN_TEST_CASE(TestSizeMatrix, sizematrix);
}

TEST_SETUP(TestSizeMatrix)
{
}

TEST_TEAR_DOWN(TestSizeMatrix)
{
}
/** \fn TEST(TestSizeMatrix, sizematrix)
Тестирование функции size_matrix.
4 теста с разными начальными координатами. Сравниает ожидаемую и получвшуюся переменную size_of_matrix.
*/
TEST(TestSizeMatrix, sizematrix)
{
	int size_of_matrix=0;
	size_matrix(&size_of_matrix, 660, 420);
	TEST_ASSERT_EQUAL_INT( 21, size_of_matrix );
	size_matrix(&size_of_matrix, 710, 380);
	TEST_ASSERT_EQUAL_INT( 11, size_of_matrix );
	size_matrix(&size_of_matrix, 650, 440);
	TEST_ASSERT_EQUAL_INT( 31, size_of_matrix );
	size_matrix(&size_of_matrix, 700, 470);
	TEST_ASSERT_EQUAL_INT( 41, size_of_matrix );
}



