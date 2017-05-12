#include "unity.h"
#include "unity_fixture.h"

static void RunAllTests(void)
{
    RUN_TEST_GROUP(TestArray);
    RUN_TEST_GROUP(TestArray1);
    RUN_TEST_GROUP(TestArray2);
    RUN_TEST_GROUP(TestArray3);
}

int main(int argc, const char * argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
