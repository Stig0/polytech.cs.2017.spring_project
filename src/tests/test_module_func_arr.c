/** @file test_module_func_arr.c
 *  @brief An example of tests for the module.c (array part).
 *
 *  This is an example. Please, change the description.
 *
 *  @author Name Surname - xxx@spbstu.ru
 */

#include "unity.h"
#include "unity_fixture.h"
#include "module.h"

#define SIZE 5

/** @brief The name of the group of the tests.
 */
TEST_GROUP(TestSqrArr);

/** @brief The list of the tests in the group.
 */
TEST_GROUP_RUNNER(TestSqrArr)
{
    RUN_TEST_CASE(TestSqrArr, test_clear_array);
    RUN_TEST_CASE(TestSqrArr, test_sqr_array_rand);
}

/** @brief The list of the tests in the group.
 */
TEST_SETUP(TestSqrArr)
{
}

/** @brief The test runner will run this procedure prior to each test.
 */
TEST_TEAR_DOWN(TestSqrArr)
{
}

/** @brief Check the correctness of an array clearing.
 *
 *  Check: clear_arr function @see clear_arr()
 */
TEST(TestSqrArr, test_clear_array)
{
    float x[SIZE] = {1.0f, 2.4f, 3.8f, 9.12f, 3.14f};
    float empty[SIZE] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    clear_arr(x, SIZE);
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(empty, x, SIZE);
}

/** @brief Check the correctness of application sqr function to array.
 *
 *  Check: sqr_arr function @see sqr_arr() @see sqr()
 */
TEST(TestSqrArr, test_sqr_array_rand)
{
    float x[SIZE] = {1.0f, 2.4f, 3.8f, 9.12f, 3.14f};
    float empty[SIZE] = {1.0f, 5.76f, 14.44f, 83.1744f, 9.8596f};
    sqr_arr(x, SIZE);
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(empty, x, SIZE);
}
