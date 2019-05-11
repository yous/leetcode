// https://leetcode.com/problems/reverse-integer/
#include <assert.h>
#include <stdint.h>

int reverse(int x)
{
    int result = 0;
    int sign = 1;

    // -2 ** 31
    if (x == INT32_MIN) {
        return 0;
    }

    if (x < 0) {
        sign = -1;
        x = -x;
    }

    while (x > 0) {
        if (result > INT32_MAX / 10) {
            return 0;
        }

        result *= 10;

        if (result > INT32_MAX - x % 10) {
            return 0;
        }

        result += x % 10;
        x /= 10;
    }

    return sign < 0 ? -result : result;
}

/**
 * Test code.
 */
void test1()
{
    int input = 123;
    int result;

    result = reverse(input);
    assert(result == 321);
}

void test2()
{
    int input = -123;
    int result;

    result = reverse(input);
    assert(result == -321);
}

void test3()
{
    int input = 120;
    int result;

    result = reverse(input);
    assert(result == 21);
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
