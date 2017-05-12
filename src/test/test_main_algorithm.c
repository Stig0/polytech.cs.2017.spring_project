#include "functions.h"
#include "unity.h"

void test_main_alghorithm_1(void)
{
	int a[100][100], b[100][100], c[100][100];
	int i, j = 0, number=0, game_mode=1;
	int size_of_matrix = 100;
	for (j = 0; j < size_of_matrix; j++) {
		for (i = 0; i < size_of_matrix; i++) {
			b[i][j] = 0;
			a[i][j] = 0;
			c[i][j] = 0;
		}
	}
	b[3][3]=1;
	b[2][3]=1;
	b[3][2]=1;

	main_algorithm(b, a, number, size_of_matrix, &game_mode);
	c[3][3]=1;
	c[2][2]=1;
	c[2][3]=1;
	c[3][2]=1;
	TEST_ASSERT_EQUAL_INT_ARRAY(a, c, 10000);
}

void test_main_alghorithm_2(void)
{
	int a[100][100], b[100][100], c[100][100];
	int i, j = 0, number=0, game_mode=1;
	int size_of_matrix = 100;
	for (j = 0; j < size_of_matrix; j++) {
		for (i = 0; i < size_of_matrix; i++) {
			b[i][j] = 0;
			a[i][j] = 0;
			c[i][j] = 0;
		}
	}
	b[3][3]=1;
	b[2][3]=1;
	b[4][3]=1;

	main_algorithm(b, a, number, size_of_matrix, &game_mode);
	c[3][3]=1;
	c[3][2]=1;
	c[3][4]=1;
	TEST_ASSERT_EQUAL_INT_ARRAY(a, c, 10000);
}

void test_main_alghorithm_3(void)
{
	int a[100][100], b[100][100], c[100][100];
	int i, j = 0, number=0, game_mode=1;
	int size_of_matrix = 100;
	for (j = 0; j < size_of_matrix; j++) {
		for (i = 0; i < size_of_matrix; i++) {
			b[i][j] = 0;
			a[i][j] = 0;
			c[i][j] = 0;
		}
	}
	b[2][1]=1;
	b[3][2]=1;
	b[3][3]=1;
	b[2][3]=1;
	b[1][3]=1;

	main_algorithm(b, a, number, size_of_matrix, &game_mode);
	c[1][2]=1;
	c[3][2]=1;
	c[2][3]=1;
	c[2][4]=1;
	c[3][3]=1;
	TEST_ASSERT_EQUAL_INT_ARRAY(a, c, 10000);
}
