#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//非递归的栈的头文件
//#include "stack.h"


// 打印数组的函数，遍历数组并输出每个元素
void print(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);  // 打印数组中的每一个元素
    }
    printf("\n");  // 换行，输出结束
}


// 交换两个整数的值
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


// 快排方法1：标准版快排
// 选择最左边元素为基准元素（key），然后进行左右指针法的排序
void quicksort1(int* a, int left, int right)
{
    if (left >= right)  // 递归终止条件：如果左指针 >= 右指针，数组已排好序
    {
        return;
    }

    int begin = left, end = right;  // 记录起始和结束位置
    int key = left;  // 基准元素位置的索引，初始为最左边的元素

    // 开始左右指针法进行分区
    while (left < right)
    {
        // 从右边找到第一个比基准元素小的元素
        while (left < right && a[right] >= a[key])
        {
            right--;
        }
        // 从左边找到第一个比基准元素大的元素
        while (left < right && a[left] <= a[key])
        {
            left++;
        }

        // 交换左右指针分别找到的比基准元素大的左边元素和比基准元素小的右边元素
        swap(&a[left], &a[right]);
    }

    // 最后将基准元素和 left 指针位置的元素交换
    swap(&a[key], &a[left]);
    key = left;

    // 递归排序左半部分和右半部分
    quicksort1(a, begin, key - 1);  // 排序左半部分
    quicksort1(a, key + 1, end);    // 排序右半部分
}


// 快排方法2：随机选取基准元素
// 随机选择一个基准元素，防止在某些特定数据集上的最坏情况发生
void quicksort2(int* a, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int begin = left, end = right;

    // 随机选取一个元素作为基准元素，并将它与最左边元素交换
    int random = left + (rand() % (right - left + 1));
    swap(&a[random], &a[left]);

    int key = left;

    while (left < right)
    {
        while (left < right && a[right] >= a[key])
        {
            right--;
        }
        while (left < right && a[left] <= a[key])
        {
            left++;
        }

        swap(&a[left], &a[right]);
    }

    swap(&a[key], &a[left]);
    key = left;

    quicksort2(a, begin, key - 1);
    quicksort2(a, key + 1, end);
}


// 三数取中法：从左、中、右三个元素中选出中间值作为基准元素
int find_middle(int* a, int left, int right)
{
    int mid = (left + right) / 2;  // 找到中间位置
    // 比较三个位置的元素，选择中间值
    if (a[left] < a[mid])
    {
        if (a[mid] < a[right])
        {
            return mid;
        }
        else if (a[left] > a[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
    else // a[left] > a[mid]
    {
        if (a[mid] > a[right])
        {
            return mid;
        }
        else if (a[left] < a[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}


// 快排方法3：三数取中法
// 使用三数取中法选择基准元素，提升效率，避免极端情况
void quicksort3(int* a, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int begin = left, end = right;

    // 三数取中法选出基准元素，并将它交换到最左边
    int mid = find_middle(a, left, right);
    if (mid != left)
    {
        swap(&a[mid], &a[left]);
    }

    int key = left;
    while (left < right)
    {
        while (left < right && a[right] >= a[key])
        {
            right--;
        }

        while (left < right && a[left] <= a[key])
        {
            left++;
        }

        swap(&a[left], &a[right]);
    }

    swap(&a[key], &a[left]);
    key = left;

    quicksort3(a, begin, key - 1);
    quicksort3(a, key + 1, end);
}


// 快排方法4：挖坑法
// 通过挖坑法，每次找到比基准元素大的和小的元素，依次填充"坑"位
void quicksort4(int* a, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int begin = left, end = right;

    // 挖坑法：最左边元素作为基准元素
    int key = a[left];
    int hole = left;  // "坑"的初始位置是基准元素的位置

    while (left < right)
    {
        // 从右侧找到比基准元素小的元素，并填入当前左侧的"坑"
        while (left < right && a[right] >= key)
        {
            right--;
        }
        a[hole] = a[right];  // 填坑
        hole = right;  // 更新"坑"位

        // 从左边找到比基准元素大的元素，填到右边"坑"位
        while (left < right && a[left] <= key)
        {
            left++;
        }
        a[hole] = a[left];  // 填坑
        hole = left;  // 更新"坑"位
    }

    a[hole] = key;  // 最后将基准元素填回坑位

    quicksort4(a, begin, hole - 1);
    quicksort4(a, hole + 1, end);
}


// 前后指针法：使用两个指针前后进行比较与交换
// 1. cur找到比key小的值，++prev,cur和prev位置交换，++cur
// 2. cur找到比key大的值，++cur
// 说明：1. prev要么紧跟着cur(prev下一个就是cur)
// prev跟cur中间间隔着比key大的一段值区间
// (把比key大的值往右翻，比key小的值翻到左边)
int quicksort5(int* a, int left, int right)
{
    int midi = find_middle(a, left, right);  // 选取三数取中基准
    if (midi != left)
        swap(&a[midi], &a[left]);

    int key = left;
    int prev = left, cur = left + 1;

    // cur指针遍历数组，找到比key小的元素，与prev交换
    while (cur <= right)
    {
        if (a[cur] < a[key] && ++prev != cur)
        {
            swap(&a[prev], &a[cur]);
        }
        cur++;
    }

    // 最后将基准元素放到prev指针的位置
    swap(&a[prev], &a[key]);
    key = prev;

    return key;
}
//// 快排驱动函数，搭配前后指针法(quicksort5)使用
//void quickSort(int* a, int left, int right)
//{
//    if (left >= right)
//    {
//        return;
//    }
//    int keyi = quicksort5(a, left, right);
//    quickSort(a, left, keyi - 1);
//    quickSort(a, keyi + 1, right);
//}
//// 快排驱动函数的小区间优化版本，搭配前后指针法(quicksort5)使用
//void quickSort(int* a, int left, int right)
//{
//    if (left >= right)
//    {
//        return;
//    }
//    
//    if (right - left + 1 > 10)
//    {
//        int keyi = quicksort5(a, left, right);
//        quickSort(a, left, keyi - 1);
//        quickSort(a, keyi + 1, right);
//    }
//    else
//    {
//        // 小区间优化：选择插入排序
//        for (int i = left + 1; i <= right; i++)  // 从left+1开始插入排序
//        {
//            int tmp = a[i];  // 当前要插入的元素
//            int end = i - 1;  // end初始为已排序部分的最后一个元素
//
//            // 从end往回比较，如果tmp小于a[end]，则将a[end]右移
//            while (end >= left && tmp < a[end])
//            {
//                a[end + 1] = a[end];  // 将a[end]右移
//                end--;
//            }
//
//            // 插入tmp到正确位置
//            a[end + 1] = tmp;
//        }
//    }
//}


////快排的非递归版本(此处需要用到关于栈的代码，假设有栈结构ST)
//void QuickSort_Non_recursive(int* a, int left, int right)
//{
//    ST st;
//    STInit(&st);// 初始化栈
//    STPush(&st, right);// 先将区间右边界压入栈
//    STPush(&st, left);// 再将区间左边界压入栈
//
//    // 栈不为空时，继续分区
//    while (!STEmpty(&st))
//    {
//        int begin = STTop(&st);// 取栈顶元素（左边界）
//        STPop(&st);
//        int end = STTop(&st);// 取栈顶元素（右边界）
//        STPop(&st);
//
//        int keyi = PartSort3(a, begin, end);// 使用已有的分区函数进行分区
//        // 分区后，[begin, keyi-1] 和 [keyi+1, end] 两部分再压入栈
//        if (keyi + 1 < end)
//        {
//            STPush(&st, end);// 压入右边区间
//            STPush(&st, keyi + 1);// 压入右边区间起点
//        }
//
//        if (begin < keyi - 1)
//        {
//            STPush(&st, keyi - 1);// 压入左边区间终点
//            STPush(&st, begin);// 压入左边区间起点
//        }
//    }
//
//    STDestroy(&st);// 销毁栈
//}


int main()
{
    int a[20] = { 11,567,78,34,23,91,10,29,45,67,89,32,19,50,72,81,69,102,111,312 };
    int n = sizeof(a) / sizeof(a[0]);  // 数组大小

    //根据需求选择不同的快排实现
    //quicksort1(a, 0, n - 1);
    //quicksort2(a, 0, n - 1);
    //quicksort3(a, 0, n - 1);
    //quicksort4(a, 0, n - 1);
    //quickSort(a, 0, n - 1);

    //打印结果
    //print(a, n);

    return 0;
}
