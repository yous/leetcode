// https://leetcode.com/problems/palindrome-number/
#include <assert.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    int top = 1;
    int bottom = 1;
    int first;
    int last;

    if (x < 0) {
        return false;
    }

    while (x / top / 10 > 0) {
        top *= 10;
    }

    first = x / top % 10;
    last = x / bottom % 10;

    while (top > bottom) {
        if (first != last) {
            return false;
        }

        top /= 10;
        bottom *= 10;
        first = x / top % 10;
        last = x / bottom % 10;
    }

    return true;
}

/**
 * Test code.
 */
void test1(void)
{
    int input = 121;
    bool result;

    result = isPalindrome(input);
    assert(result == true);
}

void test2(void)
{
    int input = -121;
    bool result;

    result = isPalindrome(input);
    assert(result == false);
}

void test3(void)
{
    int input = 10;
    bool result;

    result = isPalindrome(input);
    assert(result == false);
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
