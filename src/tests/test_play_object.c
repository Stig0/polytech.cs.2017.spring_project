#include "functions.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(TestPlayObject);

TEST_GROUP_RUNNER(TestPlayObject)
{
    RUN_TEST_CASE(TestPlayObject,TestPlaner);
    RUN_TEST_CASE(TestPlayObject, TestRellay);
    RUN_TEST_CASE(TestPlayObject, TestTwinBees);
}

TEST_SETUP(TestPlayObject)
{
}

TEST_TEAR_DOWN(TestPlayObject)
{
}



TEST(TestPlayObject, TestPlaner )
{
	int  b[100][100], c[100][100];
	int i, j = 0, number=0, game_mode=1;
	int size_of_matrix = 100;
	for (j = 0; j < size_of_matrix; j++) {
		for (i = 0; i < size_of_matrix; i++) {
			b[i][j] = 0;
			c[i][j] = 0;
		}
	}
	b[2][1] = 1;
	b[3][2] = 1;
	b[1][3] = 1;
	b[2][3] = 1;
	b[3][3] = 1;
	planer(c);
	TEST_ASSERT_EQUAL_INT_ARRAY(b, c, 10000);
}

TEST(TestPlayObject, TestRellay )
{
	int  b[100][100], c[100][100];
	int i, j = 0, number=0, game_mode=1;
	int size_of_matrix = 100;
	for (j = 0; j < size_of_matrix; j++) {
		for (i = 0; i < size_of_matrix; i++) {
			b[i][j] = 0;
			c[i][j] = 0;
		}
	}
	b[5][9] = 1;
	b[6][9] = 1;
	b[7][9] = 1;
	b[8][9] = 1;
	b[9][9] = 1;
	b[11][9] = 1;
	b[12][9] = 1;
	b[13][9] = 1;
	b[14][9] = 1;
	b[15][9] = 1;
	b[10][5] = 1;
	b[10][6] = 1;
	b[10][7] = 1;
	b[10][8] = 1;
	b[10][10] = 1;
	b[10][11] = 1;
	b[10][12] = 1;
	b[10][13] = 1;
	b[9][14] = 1;
	b[11][14] = 1;
	b[9][4] = 1;
	b[11][4] = 1;
	b[7][5] = 1;
	b[8][6] = 1;
	b[8][7] = 1;
	b[6][7] = 1;
	b[7][7] = 1;
	b[6][11] = 1;
	b[7][11] = 1;
	b[8][11] = 1;
	b[8][12] = 1;
	b[7][13] = 1;
	b[13][5] = 1;
	b[12][6] = 1;
	b[12][7] = 1;
	b[13][7] = 1;
	b[14][7] = 1;
	b[12][11] = 1;
	b[13][11] = 1;
	b[14][11] = 1;
	b[12][12] = 1;
	b[13][13] = 1;
	rellay(c);
	TEST_ASSERT_EQUAL_INT_ARRAY(b, c, 10000);
}
TEST(TestPlayObject, TestTwinBees )
{
	int  b[100][100], c[100][100];
	int i, j = 0, number=0, game_mode=1;
	int size_of_matrix = 100;
	for (j = 0; j < size_of_matrix; j++) {
		for (i = 0; i < size_of_matrix; i++) {
			b[i][j] = 0;
			c[i][j] = 0;
		}
	}
	b[7][12] = 1;
	b[8][12] = 1;
	b[9][12] = 1;
	b[10][12] = 1;
	b[11][12] = 1;
	b[12][12] = 1;
	b[7][13] = 1;
	b[8][13] = 1;
	b[9][13] = 1;
	b[10][13] = 1;
	b[10][14] = 1;
	b[11][14] = 1;
	b[12][15] = 1;
	b[13][15] = 1;
	b[13][14] = 1;
	b[13][17] = 1;
	b[12][17] = 1;
	b[13][18] = 1;
	b[11][18] = 1;
	b[10][18] = 1;
	b[10][19] = 1;
	b[10][20] = 1;
	b[11][20] = 1;
	b[12][20] = 1;
	b[18][20] = 1;
	b[19][20] = 1;
	b[20][20] = 1;
	b[21][20] = 1;
	b[18][19] = 1;
	b[19][19] = 1;
	b[21][19] = 1;
	b[21][18] = 1;
	b[20][17] = 1;
	b[19][17] = 1;
	b[19][15] = 1;
	b[20][15] = 1;
	b[21][14] = 1;
	b[21][13] = 1;
	b[21][12] = 1;
	b[20][12] = 1;
	b[19][12] = 1;
	b[18][12] = 1;
	b[18][13] = 1;
	b[19][13] = 1;
	b[34][12] = 1;
	b[35][12] = 1;
	b[34][13] = 1;
	b[35][13] = 1;

	Twin_Bees(c);
	TEST_ASSERT_EQUAL_INT_ARRAY(b, c, 10000);
}
