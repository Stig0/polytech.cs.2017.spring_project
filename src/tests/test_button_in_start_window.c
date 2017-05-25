/** @file test_button_in_start_window.c
* @brief Тест кнопок в меню
*@author Nikolaev Denis - den11nik@yandex.ru \n
    *@author Puzko Danila - danilapuzko@mail.ru
*/
#include "unity.h"
#include "unity_fixture.h"
#include "knopka.h"
#include "functions.h"
#include "lib.h"
#include "clean.h"
TEST_GROUP(TestButtonInStartWindow);

TEST_GROUP_RUNNER(TestButtonInStartWindow)
{
    RUN_TEST_CASE(TestButtonInStartWindow, buttonplay);
    RUN_TEST_CASE(TestButtonInStartWindow, buttonexit);
}

TEST_SETUP(TestButtonInStartWindow)
{
}

TEST_TEAR_DOWN(TestButtonInStartWindow)
{
}
/** \fn TEST(TestButtonInStartWindow, buttonplay)
Тестирование кнопки Играть в режиме стартового окна .
.
*/
TEST(TestButtonInStartWindow, buttonplay)
{
	int a[100][100], b[100][100];
	int i=0, j=0;
	int size_of_matrix=40, Game_on=1, size_settings=0, game_mode=0, game_window=0, count_of_clean=0;
	float  bouncer_x=0.0, bouncer_y=0.0;
	bouncer_x = 411.0;
	bouncer_y = 351.0;
	knopka(size_of_matrix, &Game_on, &size_settings, &game_mode, &game_window, &count_of_clean,b, bouncer_x, bouncer_y);
	TEST_ASSERT_EQUAL_INT(1, game_window);
	TEST_ASSERT_EQUAL_INT(0, size_settings);
	TEST_ASSERT_EQUAL_INT(99, count_of_clean);
}
/** \fn TEST(TestButtonInStartWindow, buttonexit)
Тестирование кнопки Выход в режиме стартового окна .
.
*/
TEST(TestButtonInStartWindow, buttonexit)
{
	int a[100][100], b[100][100];
	int i=0, j=0;
	int size_of_matrix=40, Game_on=1, size_settings=0, game_mode=0, game_window=0, count_of_clean=0;
	float  bouncer_x=0.0, bouncer_y=0.0;
	bouncer_x = 549.0;
	bouncer_y = 479.0;
	knopka(size_of_matrix, &Game_on, &size_settings, &game_mode, &game_window, &count_of_clean,b, bouncer_x, bouncer_y);
	TEST_ASSERT_EQUAL_INT(0, Game_on);

}

