#define _CRT_SECURE_NO_WARNINGS 1

//力扣：88. 合并两个有序数组
//https://leetcode.cn/problems/merge-sorted-array/

//思想：一个新数组从后往前存，从末尾大数往前存，数越来越小，巧妙利用两个数组有序从而方便解决
#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int arr1 = m - 1, arr2 = n - 1;
    int total = m + n - 1;//total:总的
    while (arr1 >= 0 && arr2 >= 0)
    {
        if (nums1[arr1] > nums2[arr2])
        {
            nums1[total--] = nums1[arr1--];
        }
        else
        {
            nums1[total--] = nums2[arr2--];
        }
    }

    while (arr2 >= 0)
    {
        nums1[total--] = nums2[arr2--];
    }
}