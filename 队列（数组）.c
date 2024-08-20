#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100  // 定义队列的最大容量

typedef struct {
    int data[MAX_SIZE];  // 用于存储队列元素的数组
    int front;           // 队首指针，指向队列的第一个元素
    int rear;            // 队尾指针，指向队列的最后一个元素
    int size;            // 当前队列中的元素数量
} Queue;

// 初始化队列
void initQueue(Queue* q) {
    q->front = 0;       // 队首指针初始值为0
    q->rear = -1;       // 队尾指针初始值为-1，因为队列为空
    q->size = 0;        // 初始时队列大小为0
}

// 检查队列是否为空
bool isEmpty(Queue* q) {
    return q->size == 0;  // 如果队列大小为0，返回true，否则返回false
}

// 检查队列是否已满
bool isFull(Queue* q) {
    return q->size == MAX_SIZE;  // 如果队列大小达到最大容量，返回true，否则返回false
}

// 入队操作：将元素添加到队尾
bool enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");  // 如果队列已满，打印错误信息并返回false
        return false;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;  // 循环更新队尾指针
    q->data[q->rear] = value;            // 将新元素添加到队尾
    q->size++;                           // 队列大小加1
    return true;
}

// 出队操作：从队首移除元素
bool dequeue(Queue* q, int* value) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");  // 如果队列为空，打印错误信息并返回false
        return false;
    }
    *value = q->data[q->front];        // 将队首元素的值赋给传入的指针
    q->front = (q->front + 1) % MAX_SIZE;  // 循环更新队首指针
    q->size--;                            // 队列大小减1
    return true;
}

// 获取队首元素，但不移除
bool front(Queue* q, int* value) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");  // 如果队列为空，打印错误信息并返回false
        return false;
    }
    *value = q->data[q->front];  // 将队首元素的值赋给传入的指针
    return true;
}

// 获取当前队列的大小
int queueSize(Queue* q) {
    return q->size;  // 返回队列当前的大小
}

int main() {
    Queue q;
    initQueue(&q);  // 初始化队列

    enqueue(&q, 10);  // 入队操作
    enqueue(&q, 20);
    enqueue(&q, 30);

    int value;
    if (front(&q, &value)) {
        printf("队首元素 : %d\n", value);  // 打印队首元素
    }

    while (!isEmpty(&q)) {
        if (dequeue(&q, &value)) {
            printf("出队: %d\n", value);  // 依次出队并打印元素
        }
    }

    return 0;
}
