/** @file runner.c
* @brief Функция запуска всех тестов
*/
#include "unity.h"
#include "unity_fixture.h"

static void RunAllTests(void)
{
    RUN_TEST_GROUP(TestButtonInPlayWindow);
    RUN_TEST_GROUP(TestButtonInStartWindow);
    RUN_TEST_GROUP(TestClean);
    RUN_TEST_GROUP(TestMainAlgorithm);
    RUN_TEST_GROUP(TestSizeMatrix);
    RUN_TEST_GROUP(TestPlayObject);
}

int main(int argc, const char * argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
