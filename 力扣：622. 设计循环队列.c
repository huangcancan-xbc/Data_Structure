#define _CRT_SECURE_NO_WARNINGS 1

//力扣：622. 设计循环队列
//https://leetcode.cn/problems/design-circular-queue/description/


#include <stdlib.h>
#include <stdbool.h>

// 定义循环队列的结构体
typedef struct {
    int* a;      // 用于存储队列元素的数组
    int front;   // 队首指针
    int rear;    // 队尾指针
    int k;       // 队列的容量（注意：实际数组的大小是 k+1，以区分队列满和空的状态）
} MyCircularQueue;

// 创建并初始化一个循环队列
MyCircularQueue* myCircularQueueCreate(int k) {
    // 为队列结构体分配内存
    MyCircularQueue* temp = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    // 初始化队首和队尾指针都指向 0
    temp->front = temp->rear = 0;
    // 为存储元素的数组分配内存，大小为 k+1
    temp->a = (int*)malloc(sizeof(int) * (k + 1));
    // 保存队列的容量
    temp->k = k;

    return temp; // 返回初始化好的队列指针
}

// 判断队列是否为空
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    // 当队首和队尾指针相等时，队列为空
    return obj->front == obj->rear;
}

// 判断队列是否已满
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    // 当 (rear + 1) % (k + 1) == front 时，队列已满
    return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

// 向循环队列中添加一个元素
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    // 如果队列已满，则不能添加新元素
    if (myCircularQueueIsFull(obj)) {
        return false;
    }

    // 将新元素放到队尾指针指向的位置
    obj->a[obj->rear++] = value;
    // 更新队尾指针，使其环绕队列
    obj->rear %= (obj->k + 1);

    return true; // 添加成功
}

// 从循环队列中删除一个元素
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    // 如果队列为空，则不能删除元素
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }

    // 队首指针向前移动，指向下一个元素
    ++obj->front;
    // 更新队首指针，使其环绕队列
    obj->front %= (obj->k + 1);

    return true; // 删除成功
}

// 获取队首元素
int myCircularQueueFront(MyCircularQueue* obj) {
    // 如果队列为空，返回 -1 表示错误
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    else {
        // 返回队首指针指向的元素
        return obj->a[obj->front];
    }
}

// 获取队尾元素
int myCircularQueueRear(MyCircularQueue* obj) {
    // 如果队列为空，返回 -1 表示错误
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    else {
        // 计算并返回队尾元素（队尾指针的前一个位置）
        return obj->a[(obj->rear - 1 + obj->k + 1) % (obj->k + 1)];
    }
}

// 释放循环队列占用的内存
void myCircularQueueFree(MyCircularQueue* obj) {
    // 释放存储队列元素的数组
    free(obj->a);
    // 释放队列结构体本身
    free(obj);
}

//代码解释:
//循环队列的基本概念：
//循环队列是一种特殊的队列，它的最后一个位置和第一个位置相连，形成一个环形结构。
//为了区分队列满和队列空的情况，通常会多分配一个位置。例如，如果容量 k 是 5，那么数组的大小将是 k + 1（即 6），这样就可以通过 front 和 rear 的关系来判断队列满和空。

// 创建队列(myCircularQueueCreate)：
//分配了一个 MyCircularQueue 结构体，并初始化 front 和 rear 指针为 0，同时为存储元素的数组分配了大小为 k + 1 的内存。

// 判断队列是否为空(myCircularQueueIsEmpty)：
//当 front 和 rear 相等时，队列为空。

//判断队列是否已满(myCircularQueueIsFull)：
//当(rear + 1) % (k + 1) 等于 front 时，表示队列已满。

//入队操作(myCircularQueueEnQueue)：
//如果队列未满，元素会被添加到 rear 指针指向的位置，并更新 rear 指针。

//出队操作(myCircularQueueDeQueue)：
//如果队列不为空，front 指针会向前移动，指向下一个元素。

//获取队首元素(myCircularQueueFront)：
//返回队首指针指向的元素，如果队列为空则返回 - 1。

//获取队尾元素(myCircularQueueRear)：
//返回队尾指针前一个位置的元素，如果队列为空则返回 - 1。

//释放内存(myCircularQueueFree)：
//释放为队列结构体及其数组分配的内存。