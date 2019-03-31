// https://leetcode.com/problems/two-sum/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target)
{
    int *result;
    int remain;
    int i, j;

    result = (int *) malloc(sizeof(int) * 2);

    for (i = 0; i < numsSize - 1; i++) {
        remain = target - nums[i];
        for (j = i + 1; j < numsSize; j++) {
            if (nums[j] == remain) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return result;
}

int main()
{
    int nums[4] = {2, 7, 11, 15};
    int *result;

    result = twoSum(nums, 4, 9);
    assert(nums[result[0]] + nums[result[1]] == 9);

    free(result);
    return 0;
}
