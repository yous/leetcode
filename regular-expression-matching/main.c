// https://leetcode.com/problems/regular-expression-matching/
#include <assert.h>
#include <stdbool.h>

bool isMatch(char *s, char *p) {
    char pat;
    char following;

    if (*p == '\0') {
        return *s == '\0';
    }

    pat = *p;
    following = *(p + 1);

    if (following == '*') {
        return isMatch(s, p + 2) ||
            (*s != '\0' && (pat == '.' || *s == pat) && isMatch(s + 1, p));
    } else {
        return *s != '\0' && (pat == '.' || *s == pat) && isMatch(s + 1, p + 1);
    }
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
