// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <assert.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int med_idx1, med_idx2;
    int num_idx1, num_idx2;
    int idx;
    int med1, med2;

    med_idx1 = (nums1Size + nums2Size - 1) / 2;
    med_idx2 = (nums1Size + nums2Size) / 2;

    if (nums1Size == 0) {
        return ((double) nums2[med_idx1] + (double) nums2[med_idx2]) / 2.0;
    } else if (nums2Size == 0) {
        return ((double) nums1[med_idx1] + (double) nums1[med_idx2]) / 2.0;
    }

    num_idx1 = 0;
    num_idx2 = 0;
    idx = 0;

    while (idx <= med_idx2) {
        if (num_idx1 < nums1Size && num_idx2 < nums2Size) {
            if (nums1[num_idx1] <= nums2[num_idx2]) {
                if (idx == med_idx1) {
                    med1 = nums1[num_idx1];
                }

                if (idx == med_idx2) {
                    med2 = nums1[num_idx1];
                }

                num_idx1++;
                idx++;
            } else {
                if (idx == med_idx1) {
                    med1 = nums2[num_idx2];
                }

                if (idx == med_idx2) {
                    med2 = nums2[num_idx2];
                }

                num_idx2++;
                idx++;
            }
        } else if (num_idx1 < nums1Size) {
            if (idx == med_idx1) {
                med1 = nums1[num_idx1];
            }

            if (idx == med_idx2) {
                med2 = nums1[num_idx1];
            }

            num_idx1++;
            idx++;
        } else if (num_idx2 < nums2Size) {
            if (idx == med_idx1) {
                med1 = nums2[num_idx2];
            }

            if (idx == med_idx2) {
                med2 = nums2[num_idx2];
            }

            num_idx2++;
            idx++;
        }
    }

    return ((double) med1 + (double) med2) / 2.0;
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
