#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 时间复杂度：O(N+range)
// 空间复杂度：O(range)
// 计数排序函数，参数a是待排序的数组，n是数组的长度
void count_sort(int* a, int n)
{
    int max = a[0], min = a[0];  // 初始化max和min为数组第一个元素

    // 找到数组中的最大值
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];  // 更新最大值
        }
    }

    // 找到数组中的最小值
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];  // 更新最小值
        }
    }

    // 确定计数数组的范围，即[min, max]的长度
    int range = max - min + 1;

    // 动态分配一个长度为range的数组countA，用来存储每个数字的出现次数
    int* countA = (int*)malloc(sizeof(int) * range);
    if (countA == NULL)
    {
        perror("malloc fail");  // 如果内存分配失败，打印错误信息并返回
        return;
    }

    // 将countA数组初始化为0，表示开始时每个数字的出现次数都为0
    memset(countA, 0, sizeof(int) * range);

    // 统计每个元素出现的次数
    // 例如，a[i] - min 的结果表示a[i]相对于最小值的偏移量
    // countA[a[i] - min] 用来记录这个偏移量所代表的数字出现了多少次
    for (int i = 0; i < n; i++)
    {
        countA[a[i] - min]++;  // 该元素对应的计数加1
        // 这里的逻辑是：a[i] - min得到的是一个索引，它对应的countA位置就是该数字相对于min的偏移量，
        // 通过++操作，记录该数字出现的次数。
    }

    int j = 0;  // j用来重新填充排序后的数组

    // 根据countA中的计数信息，按顺序填回原数组a
    for (int i = 0; i < range; i++)
    {
        // countA[i]中存储了某个值出现的次数
        // 每次执行while循环，表示该数字出现一次
        while (countA[i]--)
        {
            a[j++] = i + min;  // i + min 还原真实的值，j++表示往数组a中按顺序放入数字
            // 解释：i是countA的索引，它加上min后表示数组中实际的值，j++则是将排序后的值依次存入数组a。
        }
    }

    // 释放动态分配的内存
    free(countA);
}

int main()
{
    // 定义一个待排序的数组
    int a[] = { 4, 2, 2, 5, 3, 7, 7, 8, 1, 1 };
    int n = sizeof(a) / sizeof(a[0]);  // 计算数组的长度

    // 调用计数排序函数
    count_sort(a, n);

    // 输出排序后的数组
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
