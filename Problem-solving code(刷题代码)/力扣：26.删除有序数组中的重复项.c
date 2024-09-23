#define _CRT_SECURE_NO_WARNINGS 1

//力扣：26.删除有序数组中的重复项
//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int head = 0, tail = 1;
    while (tail < numsSize)
    {
        if (nums[head] == nums[tail])
        {
            tail++;
        }
        else
        {
            nums[++head] = nums[tail++];
        }
    }

    return head + 1;
}