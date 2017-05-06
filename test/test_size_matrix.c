#include "unity.h"
#include "size_matrix.h"

void test_size_matrix(void)
{
	int size_of_matrix=0;
	size_matrix(&size_of_matrix, 660, 420);
	TEST_ASSERT_EQUAL_INT( 20, size_of_matrix );
	size_matrix(&size_of_matrix, 710, 380);
	TEST_ASSERT_EQUAL_INT( 10, size_of_matrix );
	size_matrix(&size_of_matrix, 650, 440);
	TEST_ASSERT_EQUAL_INT( 30, size_of_matrix );
	size_matrix(&size_of_matrix, 700, 470);
	TEST_ASSERT_EQUAL_INT( 40, size_of_matrix );
}
	


