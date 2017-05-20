/** @file test_module_func_arr.c
 *  @brief An example of tests for the module.c (scalar part).
 *
 *  This is an example. Please, change the description.
 *
 *  @author Name Surname - xxx@spbstu.ru
 */

#include "unity.h"
#include "unity_fixture.h"
#include "module.h"

/** @brief The name of the group of the tests.
 */
TEST_GROUP(TestSqr);

/** @brief The list of the tests in the group.
 */
TEST_GROUP_RUNNER(TestSqr)
{
    RUN_TEST_CASE(TestSqr, test_sqr_func_0);
    RUN_TEST_CASE(TestSqr, test_sqr_func_float_2p4);
}

/** @brief The test runner will run this procedure prior to each test.
 */
TEST_SETUP(TestSqr)
{
}

/** @brief The test runner will invoke that method after each test.
 */
TEST_TEAR_DOWN(TestSqr)
{
}

/** @brief Check the correctness of sqr calculation for zero value.
 *
 *  Check: sqr function @see sqr()
 */
TEST(TestSqr, test_sqr_func_0)
{
    float x = 0.0f;
    float result = sqr(x);
    TEST_ASSERT_EQUAL_FLOAT(x, result);
}

/** @brief Check the correctness of sqr calculation for 2.4.
 *
 *  Check: sqr function @see sqr()
 */
TEST(TestSqr, test_sqr_func_float_2p4)
{
    float x = 2.4f;
    float result = sqr(x);
    TEST_ASSERT_EQUAL_FLOAT(x*x, result);
}
