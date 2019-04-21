// https://leetcode.com/problems/longest-palindromic-substring/
#include <assert.h>
#include <string.h>

char *longestPalindrome(char *s)
{
    int len;
    int mid;
    int max_len = 0;
    char *result = s;
    int i;

    len = (int) strlen(s);

    for (mid = 0; mid < len; mid++) {
        // The length of palindrome is odd
        i = 0;

        while (mid - i > 0 && mid + i < len - 1) {
            if (s[mid - i - 1] != s[mid + i + 1]) {
                break;
            }

            i++;
        }

        if (i * 2 + 1 > max_len) {
            max_len = i * 2 + 1;
            result = &s[mid - i];
        }

        // The length of palindrome is even
        if (mid + 1 < len && s[mid] == s[mid + 1]) {
            i = 0;

            while (mid - i > 0 && mid + i + 1 < len - 1) {
                if (s[mid - i - 1] != s[mid + i + 2]) {
                    break;
                }

                i++;
            }

            if (i * 2 + 2 > max_len) {
                max_len = i * 2 + 2;
                result = &s[mid - i];
            }
        }
    }

    *(result + max_len) = '\0';
    return result;
}

/**
 * Test code.
 */
void test1()
{
    char input[] = {'b', 'a', 'b', 'a', 'd', '\0'};
    char *result;

    result = longestPalindrome(input);
    assert(strcmp(result, "bab") == 0 || strcmp(result, "aba") == 0);
}

void test2()
{
    char input[] = {'c', 'b', 'b', 'd', '\0'};
    char *result;

    result = longestPalindrome(input);
    assert(strcmp(result, "bb") == 0);
}

void test3()
{
    char input[] = { '\0' };
    char *result;

    result = longestPalindrome(input);
    assert(strcmp(result, "") == 0);
}

int main()
{
    test1();
    test2();
    return 0;
}
