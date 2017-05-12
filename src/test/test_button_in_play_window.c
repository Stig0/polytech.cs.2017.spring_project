#include "unity.h"
#include "knopka.h"
#include "functions.h"
#include "lib.h"
#include "clean.h"
void test_button_start(void)
{
	int a[100][100], b[100][100];
	int i=0, j=0;
	int size_of_matrix=40, Game_on=0, size_settings=0, game_mode=0, game_window=1, count_of_clean=0;
	float  bouncer_x=0.0, bouncer_y=0.0;
	//Test button start
	bouncer_x = 200.0;
	bouncer_y = 40.0;
	knopka(size_of_matrix, &Game_on, &size_settings, &game_mode, &game_window, &count_of_clean,b, bouncer_x, bouncer_y);
	TEST_ASSERT_EQUAL_INT(10, game_mode);
}
void test_button_step(void)
{
	int a[100][100], b[100][100];
	int i=0, j=0;
	int size_of_matrix=40, Game_on=0, size_settings=0, game_mode=0, game_window=1, count_of_clean=0;
	float  bouncer_x=0.0, bouncer_y=0.0;
	//Test button step
	bouncer_x = 400.0;
	bouncer_y = 40.0;
	knopka(size_of_matrix, &Game_on, &size_settings, &game_mode, &game_window, &count_of_clean, b, bouncer_x, bouncer_y);
	TEST_ASSERT_EQUAL_INT(1, game_mode);
}
void test_button_stop(void)
{	
	int a[100][100], b[100][100];
	int i=0, j=0;
	int size_of_matrix=40, Game_on=0, size_settings=0, game_mode=0, game_window=1, count_of_clean=0;
	float  bouncer_x=0.0, bouncer_y=0.0;
	//Test button stop
	bouncer_x = 600.0;
	bouncer_y = 40.0;
	knopka(size_of_matrix, &Game_on, &size_settings, &game_mode, &game_window, &count_of_clean, b, bouncer_x, bouncer_y);
	TEST_ASSERT_EQUAL_INT(3, game_mode);
}
void test_button_clean(void)
{
	int a[100][100], b[100][100];
	int i=0, j=0;
	int size_of_matrix=40, Game_on=0, size_settings=0, game_mode=0, game_window=1, count_of_clean=0;
	float  bouncer_x=0.0, bouncer_y=0.0;
	//Test button clean
	for (j = 0; j < 100; j++) {
		for (i = 0; i < 100; i++) {
			a[i][j] = 0;
		}
	}
	bouncer_x = 800.0;
	bouncer_y = 40.0;
	knopka(size_of_matrix, &Game_on, &size_settings, &game_mode, &game_window, &count_of_clean, b, bouncer_x, bouncer_y);
	TEST_ASSERT_EQUAL_INT_ARRAY(a, b, 10000);
}
void test_button_menu(void)
{
	int a[100][100], b[100][100];
	int i=0, j=0;
	int size_of_matrix=40, Game_on=0, size_settings=0, game_mode=0, game_window=1, count_of_clean=0;
	float  bouncer_x=0.0, bouncer_y=0.0;
	//Test button menu
	bouncer_x = 900.0;
	bouncer_y = 550.0;
	knopka(size_of_matrix, &Game_on, &size_settings, &game_mode, &game_window, &count_of_clean, b, bouncer_x, bouncer_y);
	TEST_ASSERT_EQUAL_INT(0, game_window);
TEST_ASSERT_EQUAL_INT(99, count_of_clean);
	
	
}
