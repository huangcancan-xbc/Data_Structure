#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 打印数组的函数
void print(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);  // 打印数组中的每一个元素
    }
    printf("\n");  // 换行
}

// 希尔排序1：
// 时间复杂度最好：O(n * log n)
// 时间复杂度最坏：O(n^2)
// 使用的增量序列是 n / 2，逐步减小到 1，
// 内部使用插入排序对每个分组进行排序。
void shellsort1(int* a, int n)
{
    int gap = n / 2;  // 初始增量
    while (gap > 0)
    {
        for (int j = 0; j < gap; j++)  // 针对每个起始位置进行插入排序
        {
            for (int i = j; i < n; i += gap)  // 遍历整个数组并对每个分组进行插入排序
            {
                int tmp = a[i];  // 当前元素
                int end = i;
                // 将当前元素 tmp 插入到其正确的位置
                while (end >= gap && tmp < a[end - gap])
                {
                    a[end] = a[end - gap];  // 元素向右移
                    end -= gap;
                }
                a[end] = tmp;  // 插入元素到正确位置
            }
        }
        gap /= 2;  // 减小增量
        print(a, n);  // 打印当前数组状态
    }
}

// 希尔排序2：
// 时间复杂度最好：O(n * log n)
// 时间复杂度最坏：O(n^2)
// 使用的增量序列是 n / 2，逐步减小到 1，
// 使用更优化的插入排序结构。
void shellsort2(int* a, int n)
{
    int gap = n / 2;  // 初始增量
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)  // 从 gap 位置开始进行插入排序
        {
            int tmp = a[i];
            int end = i;
            // 插入排序逻辑，找到合适位置插入 tmp
            while (end >= gap && tmp < a[end - gap])
            {
                a[end] = a[end - gap];  // 元素向右移
                end -= gap;
            }
            a[end] = tmp;  // 插入元素到正确位置
        }
        gap /= 2;  // 减小增量
        print(a, n);  // 打印当前数组状态
    }
}

// 希尔排序3：
// 时间复杂度最好：O(n * log n)
// 时间复杂度最坏：O(n^2)
// 内部逻辑经过简化，减少了一些不必要的操作。
void shellsort3(int* a, int n)
{
    int gap = n / 2;  // 初始增量
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)  // 从 gap 位置开始遍历
        {
            int tmp = a[i];
            int j = i - gap;
            // 插入排序逻辑，移动较大的元素
            while (j >= 0 && a[j] > tmp)
            {
                a[j + gap] = a[j];  // 元素向右移
                j -= gap;
            }
            a[j + gap] = tmp;  // 插入元素到正确位置
        }
        gap /= 2;  // 减小增量
        print(a, n);  // 打印当前数组状态
    }
}

// 希尔排序4：
// 时间复杂度最好：O(n * log n)
// 时间复杂度最坏：O(n^2)
// 使用更复杂的增量序列：gap = gap / 3 + 1
// 增量序列的优化在数据量较大的情况下性能表现更好。
// 数据量大时，Shellsort4 使用复杂增量序列表现更好，效率提升明显。
// 数据量小时，Shellsort4 可能没有显著优势，甚至由于增量序列复杂性带来的额外开销，效率反而可能不如简单的希尔排序实现（如 shellsort2）。
void shellsort4(int* a, int n)
{
    int gap = n;  // 初始增量
    while (gap > 1)
    {
        gap = gap / 3 + 1;  // 动态调整增量
        for (int i = 0; i < n - gap; i++)  // 从 0 开始进行插入排序
        {
            int tmp = a[i + gap];
            int end = i;
            // 插入排序逻辑，找到合适位置插入 tmp
            while (end >= 0)
            {
                if (tmp < a[end])
                {
                    a[end + gap] = a[end];  // 元素向右移
                    end -= gap;
                }
                else
                {
                    break;  // 如果已经到合适位置，则跳出循环
                }
            }
            a[end + gap] = tmp;  // 插入元素到正确位置
            print(a, n);  // 打印当前数组状态
        }
    }
}

int main()
{
    int a[20] = { 11,567,78,34,23,91,10,29,45,67,89,32,19,50,72,81,69,102,111,312 };
    int n = sizeof(a) / sizeof(a[0]);  // 数组大小
    //shellsort1(a, n);  // 可以在此调用不同版本的希尔排序进行测试
    //shellsort2(a, n);
    //shellsort3(a, n);
    //shellsort4(a, n);

    return 0;
}
