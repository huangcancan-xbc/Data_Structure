#define _CRT_SECURE_NO_WARNINGS 1

//力扣：232. 用栈实现队列
//https://leetcode.cn/problems/implement-queue-using-stacks/description/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// 定义栈结构体
typedef struct stack {
    int capacity;  // 栈的容量，即最多可以存储多少个元素
    int top;       // 栈顶元素的索引
    int* a;        // 指向存储栈元素的数组指针
} ST;

// 初始化栈，分配内存并初始化Stack结构体。
void STInit(ST* p) {
    assert(p);

    p->a = (int*)malloc(sizeof(int) * 4);  // 初始分配大小为4的内存空间
    if (p->a == NULL) {  // 如果分配失败
        perror("malloc fail");
        return;
    }

    p->capacity = 4;  // 设置栈的初始容量为4
    p->top = -1;  // 初始化栈顶索引为-1，表示栈为空
}

// 销毁栈，释放内存
void STDestroy(ST* p) {
    assert(p);
    free(p->a);  // 释放栈数组的内存
    p->a = NULL;
    p->top = -1;  // 重置栈顶索引为-1
    p->capacity = 0;  // 重置栈的容量为0
}

// 将给定的元素压入栈中
void STPush(ST* p, int x) {
    assert(p);

    // 如果栈满了，则需要扩展栈的容量
    if (p->top == p->capacity - 1) {
        int* temp = (int*)realloc(p->a, sizeof(int) * p->capacity * 2);  // 扩展为原来的2倍
        if (temp == NULL) {
            perror("realloc fail");
            return;
        }

        p->a = temp;  // 更新栈的指针
        p->capacity *= 2;  // 更新容量
    }

    p->a[++p->top] = x;  // 将新元素压入栈顶，并更新栈顶索引
}

// 判断栈是否为空
bool STEmpty(ST* p) {
    assert(p);
    return p->top == -1;  // 如果栈顶索引为-1，则栈为空
}

// 弹出栈顶元素
void STPop(ST* p) {
    assert(p);  // 检查栈指针是否为空
    assert(!STEmpty(p));  // 检查栈是否为空，空栈不能弹出元素

    p->top--;  // 将栈顶索引减1，表示弹出了栈顶元素
}

// 返回栈中元素的数量
int STSize(ST* p) {
    assert(p);
    return p->top + 1;  // 栈顶索引 + 1 就是栈中元素的数量
}

// 获取栈顶元素的值
int STTop(ST* p) {
    assert(p);
    assert(!STEmpty(p));  // 如果栈为空，尝试获取栈顶元素会导致未定义的行为
    return p->a[p->top];  // 返回栈顶元素
}

// 定义一个包含两个栈的结构体，用于实现队列
typedef struct {
    ST n1;  // 用于入队的栈
    ST n2;  // 用于出队的栈
} MyQueue;

// 创建一个队列
MyQueue* myQueueCreate() {
    MyQueue* temp = (MyQueue*)malloc(sizeof(MyQueue));  // 为队列分配内存
    if (temp == NULL) {  // 检查内存分配是否成功
        perror("malloc fail");
        return NULL;
    }

    STInit(&temp->n1);  // 初始化第一个栈
    STInit(&temp->n2);  // 初始化第二个栈

    return temp;  // 返回创建的队列指针
}

// 将元素推入队列
void myQueuePush(MyQueue* obj, int x) {
    STPush(&obj->n1, x);  // 将元素压入第一个栈中
}

// 获取队列中的第一个元素
int myQueuePeek(MyQueue* obj) {
    // 如果第二个栈为空，则将第一个栈中的所有元素转移到第二个栈中
    if (STEmpty(&obj->n2)) {
        while (!STEmpty(&obj->n1)) {
            STPush(&obj->n2, STTop(&obj->n1));  // 将第一个栈的栈顶元素压入第二个栈
            STPop(&obj->n1);  // 弹出第一个栈的栈顶元素
        }
    }

    return STTop(&obj->n2);  // 返回第二个栈的栈顶元素（即队列的第一个元素）
}

// 弹出队列中的第一个元素
int myQueuePop(MyQueue* obj) {
    int temp = myQueuePeek(obj);  // 获取队列的第一个元素
    STPop(&obj->n2);  // 弹出第二个栈的栈顶元素（即队列的第一个元素）
    return temp;  // 返回弹出的元素
}

// 判断队列是否为空
bool myQueueEmpty(MyQueue* obj) {
    // 如果两个栈都为空，则队列为空
    return STEmpty(&obj->n1) && STEmpty(&obj->n2);
}

// 释放队列的内存
void myQueueFree(MyQueue* obj) {
    STDestroy(&obj->n1);  // 销毁第一个栈，释放内存
    STDestroy(&obj->n2);  // 销毁第二个栈，释放内存
    free(obj);  // 释放队列结构体的内存
}

//代码的关键点:

//双栈实现队列：
//n1 栈用于入队操作：每次调用 myQueuePush 时，元素都被压入 n1。
//n2 栈用于出队操作：当 n2 栈为空时，将 n1 栈的元素依次弹出并压入 n2，从而实现队列的顺序（先进先出）。
//当 n2 非空时，直接弹出 n2 的栈顶元素即可。
//
//时间复杂度：
//入队操作 myQueuePush 的时间复杂度是 O(1)。
//出队操作 myQueuePop 的最坏时间复杂度是 O(n)，但均摊时间复杂度是 O(1)，因为每个元素只会被移动一次，从 n1 到 n2。
//
//栈的动态扩展：
//当栈满时，会通过 realloc 函数将栈的容量扩展为原来的两倍，以适应更多的元素。