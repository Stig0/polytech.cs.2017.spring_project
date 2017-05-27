/** @file test_button_in_play_window.c
* @brief Тест кнопок в игре
*@author Nikolaev Denis - den11nik@yandex.ru \n
*@author Puzko Danila - danilapuzko@mail.ru
*/

#include "unity.h"
#include "unity_fixture.h"
#include "knopka.h"
#include "functions.h"
#include "lib.h"
#include "clean.h"
#define SIZE 100
TEST_GROUP(TestButtonInPlayWindow);

TEST_GROUP_RUNNER(TestButtonInPlayWindow)
{
    RUN_TEST_CASE(TestButtonInPlayWindow, buttonstart);
    RUN_TEST_CASE(TestButtonInPlayWindow, buttonstep);
    RUN_TEST_CASE(TestButtonInPlayWindow, buttonstop);
    RUN_TEST_CASE(TestButtonInPlayWindow, buttonclean);
    RUN_TEST_CASE(TestButtonInPlayWindow, buttonmenu);
}

TEST_SETUP(TestButtonInPlayWindow)
{
}

TEST_TEAR_DOWN(TestButtonInPlayWindow)
{
}
/** \fn TEST(TestButtonInPlayWindow, buttonstart)
Тестирование кнопки Start.
Сравнивает ожидаемую переменную game_mode с получившейся.
*/
TEST(TestButtonInPlayWindow, buttonstart)
{
	int b[SIZE][SIZE];
	int size_of_matrix=40, Game_on=0, size_settings=0, game_mode=0, game_window=1, count_of_clean=0;
	float  bouncer_x=0.0, bouncer_y=0.0;
	//Test button start
	bouncer_x = 200.0;
	bouncer_y = 40.0;
	knopka(size_of_matrix, &Game_on, &size_settings, &game_mode, &game_window, &count_of_clean,b, bouncer_x, bouncer_y);
	TEST_ASSERT_EQUAL_INT(10, game_mode);
}
/** \fn TEST(TestButtonInPlayWindow, buttonstep)
Тестирование кнопки Step.
Сравнивает ожидаемую переменную game_mode с получившейся.
*/
TEST(TestButtonInPlayWindow, buttonstep)
{
	int b[SIZE][SIZE];
	int size_of_matrix=40, Game_on=0, size_settings=0, game_mode=0, game_window=1, count_of_clean=0;
	float  bouncer_x=0.0, bouncer_y=0.0;
	//Test button step
	bouncer_x = 400.0;
	bouncer_y = 40.0;
	knopka(size_of_matrix, &Game_on, &size_settings, &game_mode, &game_window, &count_of_clean, b, bouncer_x, bouncer_y);
	TEST_ASSERT_EQUAL_INT(1, game_mode);
}
/** \fn TEST(TestButtonInPlayWindow, buttonstop)
Тестирование кнопки Stop.
Сравнивает ожидаемую переменную game_mode с получившейся.
*/
TEST(TestButtonInPlayWindow, buttonstop)
{
	int b[SIZE][SIZE];
	int size_of_matrix=40, Game_on=0, size_settings=0, game_mode=0, game_window=1, count_of_clean=0;
	float  bouncer_x=0.0, bouncer_y=0.0;
	//Test button stop
	bouncer_x = 600.0;
	bouncer_y = 40.0;
	knopka(size_of_matrix, &Game_on, &size_settings, &game_mode, &game_window, &count_of_clean, b, bouncer_x, bouncer_y);
	TEST_ASSERT_EQUAL_INT(3, game_mode);
}
/** \fn TEST(TestButtonInPlayWindow, buttonclean)
Тестирование кнопки Clean.
Сравнивает две матрица, одна из которых очищена вручную, вторая - с помощью функции clean.
*/
TEST(TestButtonInPlayWindow, buttonclean)
{
	int a[SIZE][SIZE], b[SIZE][SIZE];
	int i=0, j=0;
	int size_of_matrix=40, Game_on=0, size_settings=0, game_mode=0, game_window=1, count_of_clean=0;
	float  bouncer_x=0.0, bouncer_y=0.0;
	//Test button clean
	for (j = 0; j < 100; j++) {
		for (i = 0; i < 100; i++) {
			a[i][j] = 0;
		}
	}
	bouncer_x = 681.0;
	bouncer_y = 79.0;
	knopka(size_of_matrix, &Game_on, &size_settings, &game_mode, &game_window, &count_of_clean, b, bouncer_x, bouncer_y);
	TEST_ASSERT_EQUAL_INT_ARRAY(a, b, 10000);
}
/** \fn TEST(TestButtonInPlayWindow, buttonmenu)
Тестирование кнопки Menu.
Сравнивает ожидаемые переменные game_mode и count_of_clean с получившимися.
*/
TEST(TestButtonInPlayWindow, buttonmenu)
{
	int b[SIZE][SIZE];
	int size_of_matrix=40, Game_on=0, size_settings=0, game_mode=0, game_window=1, count_of_clean=0;
	float  bouncer_x=0.0, bouncer_y=0.0;
	//Test button menu
	bouncer_x = 900.0;
	bouncer_y = 550.0;
	knopka(size_of_matrix, &Game_on, &size_settings, &game_mode, &game_window, &count_of_clean, b, bouncer_x, bouncer_y);
	TEST_ASSERT_EQUAL_INT(0, game_window);
    TEST_ASSERT_EQUAL_INT(99, count_of_clean);


}
