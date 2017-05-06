#include "unity.h"
#include "clean.h"

void test_clean(void)
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
