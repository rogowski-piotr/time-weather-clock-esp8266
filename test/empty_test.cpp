#include <Arduino.h>
#include <unity.h>


void setUp(void) {
    ArduinoFakeReset();
}

void tearDown(void) {
}

void test_1(void) {
    TEST_ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_1);

    return UNITY_END();
}
