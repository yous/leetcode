// https://leetcode.com/problems/regular-expression-matching/
#include <assert.h>
#include <stdbool.h>

bool isMatch(char *s, char *p) {
    char *s_ptr = s;
    char *p_ptr = p;
    char pat;
    int repeat;

    if (*p_ptr == '\0') {
        return *s_ptr == '\0';
    }

    if (*s_ptr == '\0') {
        while (*p_ptr != '\0') {
            p_ptr++;

            if (*p_ptr == '*') {
                p_ptr++;
            } else {
                return false;
            }
        }

        return true;
    }

    while (*p_ptr != '\0' && *s_ptr != '\0') {
        pat = *p_ptr++;

        if (*p_ptr == '*') {
            p_ptr++;
            repeat = 1;
        } else {
            repeat = 0;
        }

        if (repeat) {
            if (isMatch(s_ptr, p_ptr)) {
                return true;
            }

            while ((pat == '.' && *s_ptr != '\0') || *s_ptr == pat) {
                s_ptr++;

                if (isMatch(s_ptr, p_ptr)) {
                    return true;
                }
            }
        } else {
            if (pat == '.' || *s_ptr == pat) {
                s_ptr++;
            } else {
                return false;
            }
        }
    }

    return isMatch(s_ptr, p_ptr);
}

/**
 * Test code.
 */
void test1() {
    char s[] = "aa";
    char p[] = "a";
    bool result;

    result = isMatch(s, p);
    assert(result == false);
}

void test2() {
    char s[] = "aa";
    char p[] = "a*";
    bool result;

    result = isMatch(s, p);
    assert(result == true);
}

void test3() {
    char s[] = "ab";
    char p[] = ".*";
    bool result;

    result = isMatch(s, p);
    assert(result == true);
}

void test4() {
    char s[] = "aab";
    char p[] = "c*a*b";
    bool result;

    result = isMatch(s, p);
    assert(result == true);
}

void test5() {
    char s[] = "mississippi";
    char p[] = "mis*is*p*.";
    bool result;

    result = isMatch(s, p);
    assert(result == false);
}

void test6() {
    char s[] = "ab";
    char p[] = ".*c";
    bool result;

    result = isMatch(s, p);
    assert(result == false);
}

void test7() {
    char s[] = "a";
    char p[] = "ab*";
    bool result;

    result = isMatch(s, p);
    assert(result == true);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    return 0;
}
