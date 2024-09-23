#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 递归实现的归并排序，辅助函数
void _mergesort(int* a, int begin, int end, int* tmp)
{
    // 如果当前区间只有一个元素或无效，直接返回
    if (begin >= end)
    {
        return;
    }

    // 找到中点，将数组一分为二
    int mid = (begin + end) / 2;
    _mergesort(a, begin, mid, tmp); // 递归排序左半部分
    _mergesort(a, mid + 1, end, tmp); // 递归排序右半部分

    // 合并两部分有序数组
    int begin1 = begin, end1 = mid; // 左半部分的开始和结束索引
    int begin2 = mid + 1, end2 = end; // 右半部分的开始和结束索引
    int i = begin; // 临时数组索引

    // 将两部分的元素按顺序合并到临时数组
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (a[begin1] <= a[begin2])
        {
            tmp[i++] = a[begin1++]; // 左半部分元素较小，存入临时数组
        }
        else
        {
            tmp[i++] = a[begin2++]; // 右半部分元素较小，存入临时数组
        }
    }

    // 如果左半部分还有剩余，继续拷贝
    while (begin1 <= end1)
    {
        tmp[i++] = a[begin1++];
    }

    // 如果右半部分还有剩余，继续拷贝
    while (begin2 <= end2)
    {
        tmp[i++] = a[begin2++];
    }

    // 将临时数组中的元素拷贝回原数组
    memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

// 递归版归并排序的入口函数
void mergesort(int* a, int n)
{
    // 分配临时数组，用于存储归并结果
    int* tmp = (int*)malloc(n * sizeof(int));
    if (tmp == NULL)
    {
        perror("malloc fail"); // 内存分配失败
        return;
    }

    _mergesort(a, 0, n - 1, tmp); // 调用递归归并排序

    free(tmp); // 释放临时数组
}

// 非递归实现归并排序的第一个版本
// 复杂问题分解为多个简单问题，分类处理
// 1. end1越界，不归并
// 2. end1没有越界，begin2越界，跟1一样处理，不归并
// 3. end1、begin没有越界，end2越界，继续归并，修正end2
// 间距为gap的多组数据，归并完以后，一把拷贝(梭哈)
void mergesort_Non_recursive1(int* a, int n)
{
    // 分配临时数组用于存储合并结果
    int* tmp = (int*)malloc(n * sizeof(int));
    if (tmp == NULL)
    {
        perror("malloc fail");
        return;
    }

    int gap = 1; // 归并的初始间距为1（两两归并）

    // 不断扩大间距gap，直到遍历完所有元素
    while (gap < n)
    {
        // 按照间距gap进行分组处理
        for (int i = 0; i < n; i += gap * 2)
        {
            int begin1 = i, end1 = i + gap - 1; // 第一段的开始和结束
            int begin2 = i + gap, end2 = i + gap * 2 - 1; // 第二段的开始和结束

            // 如果第一段超出数组范围，设置为有效范围的最后一个元素
            if (end1 >= n)
            {
                end1 = n - 1;
                begin2 = n; // 设置为无效区间
                end2 = n - 1;
            }
            else if (begin2 >= n) // 如果第二段开始超出范围
            {
                begin2 = n;
                end2 = n - 1;
            }
            else if (end2 >= n) // 如果第二段结束超出范围，修正为数组最后一个元素
            {
                end2 = n - 1;
            }

            int j = i; // 临时数组的起始位置

            // 合并两段
            while (begin1 <= end1 && begin2 <= end2)
            {
                if (a[begin1] <= a[begin2])
                {
                    tmp[j++] = a[begin1++];
                }
                else
                {
                    tmp[j++] = a[begin2++];
                }
            }

            // 拷贝剩余的元素
            while (begin1 <= end1)
            {
                tmp[j++] = a[begin1++];
            }

            while (begin2 <= end2)
            {
                tmp[j++] = a[begin2++];
            }
        }

        // 将临时数组拷贝回原数组
        memcpy(a, tmp, sizeof(int) * n);

        gap *= 2; // 间距扩大一倍
    }

    free(tmp); // 释放临时数组
}

// 非递归实现归并排序的第二个版本，边归并边拷贝
void mergesort_Non_recursive2(int* a, int n)
{
    // 分配临时数组用于存储合并结果
    int* tmp = (int*)malloc(n * sizeof(int));
    if (tmp == NULL)
    {
        perror("malloc fail");
        return;
    }

    int gap = 1; // 初始间距

    // 不断扩大间距gap，直到遍历完所有元素
    while (gap < n)
    {
        // 按照间距gap进行分组处理
        for (int i = 0; i < n; i += gap * 2)
        {
            int begin1 = i, end1 = i + gap - 1; // 第一段的开始和结束
            int begin2 = i + gap, end2 = i + gap * 2 - 1; // 第二段的开始和结束

            // 如果第一段结束超出数组范围，或者第二段开始超出范围，跳过本轮
            if (end1 >= n || begin2 >= n)
            {
                break;
            }

            if (end2 >= n) // 修正第二段结束位置
            {
                end2 = n - 1;
            }

            int j = i; // 临时数组的起始位置

            // 合并两段
            while (begin1 <= end1 && begin2 <= end2)
            {
                if (a[begin1] <= a[begin2])
                {
                    tmp[j++] = a[begin1++];
                }
                else
                {
                    tmp[j++] = a[begin2++];
                }
            }

            // 拷贝剩余的元素
            while (begin1 <= end1)
            {
                tmp[j++] = a[begin1++];
            }

            while (begin2 <= end2)
            {
                tmp[j++] = a[begin2++];
            }

            // 将已合并部分拷贝回原数组
            memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
        }

        gap *= 2; // 间距扩大一倍
    }

    free(tmp); // 释放临时数组
}

int main()
{
    // 测试数组
    int a[20] = { 11,86,27,231,88,45,12,34,19,56,78,90,10,23,45,67,89,12,34,56 };

    // 调用非递归归并排序的第二个版本
    mergesort_Non_recursive2(a, 20);

    // 输出排序结果
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
