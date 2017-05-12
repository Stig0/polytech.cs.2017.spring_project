#include "unity.h"
#include "unity_fixture.h"
#include "clean.h"


TEST_GROUP(TestArray1);

TEST_GROUP_RUNNER(TestArray1)
{
    RUN_TEST_CASE(TestArray1, addToArray);
}

TEST_SETUP(TestArray1)
{
}

TEST_TEAR_DOWN(TestArray1)
{
}

TEST(TestArray1, addToArray)
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
