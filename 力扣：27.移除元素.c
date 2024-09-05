#define _CRT_SECURE_NO_WARNINGS 1

//力扣：27.移除元素
//https://leetcode.cn/problems/remove-element/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int head = 0, tail = 0;
    while (head < numsSize)
    {
        if (nums[head] != val)
        {
            nums[tail++] = nums[head++];
        }
        else
        {
            head++;
        }
    }

    return tail;
}