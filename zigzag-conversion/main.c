// https://leetcode.com/problems/zigzag-conversion/
#include <assert.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows)
{
    size_t len;
    char *result;
    int row;
    int out_idx;
    int i;

    if (s == NULL) {
        return NULL;
    }

    len = strlen(s);

    if (numRows == 1) {
        return s;
    }

    result = (char *) malloc(sizeof(char) * (len + 1));
    out_idx = 0;

    // row = 0
    i = 0;

    while (i < len) {
        result[out_idx] = s[i];
        out_idx++;
        i += numRows * 2 - 2;
    }

    for (row = 1; row < numRows - 1; row++) {
        i = row;

        while (i < len) {
            result[out_idx] = s[i];
            out_idx++;
            i += (numRows - 1 - row) * 2;

            if (i >= len) {
                break;
            }

            result[out_idx] = s[i];
            out_idx++;
            i += row * 2;
        }
    }

    // row = numRows - 1
    i = numRows - 1;

    while (i < len) {
        result[out_idx] = s[i];
        out_idx++;
        i += numRows * 2 - 2;
    }

    result[len] = '\0';
    return result;
}

/**
 * Test code.
 */
void test1()
{
    char s[] = "PAYPALISHIRING";
    char *result;

    result = convert(s, 3);
    assert(strcmp(result, "PAHNAPLSIIGYIR") == 0);
}

void test2()
{
    char s[] = "PAYPALISHIRING";
    char *result;

    result = convert(s, 4);
    assert(strcmp(result, "PINALSIGYAHRPI") == 0);
}

int main()
{
    test1();
    return 0;
}
