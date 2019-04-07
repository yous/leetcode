// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <assert.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int *m_arr;
    int *n_arr;
    int m, n;
    int i_min, i_max;
    int i, j;

    if (nums1Size > nums2Size) {
        m_arr = nums2;
        n_arr = nums1;
        m = nums2Size;
        n = nums1Size;
    } else {
        m_arr = nums1;
        n_arr = nums2;
        m = nums1Size;
        n = nums2Size;
    }

    i_min = 0;
    i_max = m;

    while (i_min <= i_max) {
        i = (i_min + i_max) / 2;
        j = (m + n + 1) / 2 - i;

        if (i < i_max && n_arr[j - 1] > m_arr[i]) {
            i_min = i + 1;
        } else if (i > i_min && m_arr[i - 1] > n_arr[j]) {
            i_max = i - 1;
        } else {
            int max_left;
            int min_right;

            if (i == 0) {
                max_left = n_arr[j - 1];
            } else if (j == 0) {
                max_left = m_arr[i - 1];
            } else {
                max_left = m_arr[i - 1] > n_arr[j - 1]
                    ? m_arr[i - 1] : n_arr[j - 1];
            }

            if ((m + n) % 2 == 1) {
                return max_left;
            }

            if (i == m) {
                min_right = n_arr[j];
            } else if (j == n) {
                min_right = m_arr[i];
            } else {
                min_right = m_arr[i] < n_arr[j] ? m_arr[i] : n_arr[j];
            }

            return (max_left + min_right) / 2.0;
        }
    }

    return 0.0;
}

/**
 * Test code.
 */
void test1()
{
    int nums1[] = {1, 3};
    int nums2[] = {2};
    double result;

    result = findMedianSortedArrays(nums1, 2, nums2, 1);
    assert(result == 2.0);
}

void test2()
{
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};
    double result;

    result = findMedianSortedArrays(nums1, 2, nums2, 2);
    assert(result == 2.5);
}

void test3()
{
    int nums1[] = {1, 3, 4};
    int nums2[] = {2};
    double result;

    result = findMedianSortedArrays(nums1, 3, nums2, 1);
    assert(result == 2.5);
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
