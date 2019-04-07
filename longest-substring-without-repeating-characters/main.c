// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char *s)
{
    int indices[256] = {0};
    size_t len;
    size_t i;
    int max_len = 0;
    int start = 0;

    len = strlen(s);

    for (i = 0; i < len; i++) {
        unsigned char index = (unsigned char) s[i];
        if (indices[index] == 0) {
            indices[index] = i + 1;
            continue;
        }

        if (indices[index] - 1 >= start) {
            if (i - start > max_len) {
                max_len = i - start;
            }

            start = indices[index];
        }

        indices[index] = i + 1;
    }

    if (i - start > max_len) {
        max_len = i - start;
    }

    return max_len;
}

/**
 * Test code.
 */
void test1()
{
    char *input = "abcabcbb";
    int result;

    result = lengthOfLongestSubstring(input);
    assert(result == 3);
}

void test2()
{
    char *input = "bbbbb";
    int result;

    result = lengthOfLongestSubstring(input);
    assert(result == 1);
}

void test3()
{
    char *input = "pwwkew";
    int result;

    result = lengthOfLongestSubstring(input);
    assert(result == 3);
}

void test4()
{
    char *input = "abba";
    int result;

    result = lengthOfLongestSubstring(input);
    assert(result == 2);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}
