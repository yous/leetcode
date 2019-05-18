// https://leetcode.com/problems/string-to-integer-atoi/
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

int myAtoi(char *str)
{
    int result = 0;
    int sign = 1;
    char ch;

    if (str == NULL) {
        return 0;
    }

    while (*str == ' ') {
        str++;
    }

    if (*str == '+') {
        sign = 1;
        str++;
    } else if (*str == '-') {
        sign = -1;
        str++;
    }

    ch = *str;

    while ('0' <= ch && ch <= '9') {
        int num = ch - '0';

        if (result > INT32_MAX / 10) {
            return sign > 0 ? INT32_MAX : INT32_MIN;
        } else if (result == INT32_MAX / 10) {
            if (sign > 0 && num >= 7) {
                return INT32_MAX;
            } else if (sign < 0 && num >= 8) {
                return INT32_MIN;
            }
        }

        result = result * 10 + num;
        str++;
        ch = *str;
    }

    return result * sign;
}

/**
 * Test code.
 */
void test1(void)
{
    char input[] = "42";
    int result;

    result = myAtoi(input);
    assert(result == 42);
}

void test2(void)
{
    char input[] = "   -42";
    int result;

    result = myAtoi(input);
    assert(result == -42);
}

void test3(void)
{
    char input[] = "4193 with words";
    int result;

    result = myAtoi(input);
    assert(result == 4193);
}

void test4(void)
{
    char input[] = "words and 987";
    int result;

    result = myAtoi(input);
    assert(result == 0);
}

void test5(void)
{
    char input[] = "-91283472332";
    int result;

    result = myAtoi(input);
    assert(result == -2147483648);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
