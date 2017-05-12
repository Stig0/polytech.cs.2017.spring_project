#include "unity.h"
#include "unity_fixture.h"
#include "size_matrix.h"

TEST_GROUP(TestArray3);

TEST_GROUP_RUNNER(TestArray3)
{
    RUN_TEST_CASE(TestArray3, sizematrix);
}

TEST_SETUP(TestArray3)
{
}

TEST_TEAR_DOWN(TestArray3)
{
}

TEST(TestArray3, sizematrix)
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
	


