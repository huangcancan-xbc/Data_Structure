#define _CRT_SECURE_NO_WARNINGS 1

#pragma once // 防止头文件重复包含

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// 定义栈结构体
typedef struct stack {
    int capacity; // 栈的容量
    int top; // 指向栈顶元素的下一个位置
    int* a; // 存储栈元素的数组指针
} ST;

// 初始化栈，分配内存并初始化Stack结构体
void STInit(ST* p) {
    assert(p != NULL);
    p->capacity = 4; // 初始容量为4
    p->top = 0; // 栈顶元素下标初始化为0
    p->a = (int*)malloc(p->capacity * sizeof(int)); // 为栈元素分配内存
    assert(p->a != NULL); // 检查内存分配是否成功
}

// 销毁栈，释放内存
void STDestroy(ST* p) {
    assert(p != NULL);
    free(p->a); // 释放栈元素数组的内存
    p->a = NULL; // 指针置空
    p->capacity = 0; // 容量清零
    p->top = 0; // 栈顶位置清零
}

// 将给定的元素压入栈中
void STPush(ST* p, int x) {
    assert(p != NULL);
    // 如果栈满，扩大容量
    if (p->top == p->capacity) {
        p->capacity *= 2; // 容量翻倍
        p->a = (int*)realloc(p->a, p->capacity * sizeof(int));
        assert(p->a != NULL); // 检查内存分配是否成功
    }
    p->a[p->top] = x; // 将元素x压入栈顶
    p->top++; // 栈顶位置上移
}

// 弹出栈顶元素
void STPop(ST* p) {
    assert(p != NULL);
    assert(p->top > 0); // 确保栈非空
    p->top--; // 栈顶位置下移，相当于弹出元素
}

// 返回栈中元素的数量
int STSize(ST* p) {
    assert(p != NULL);
    return p->top; // 栈顶位置即为栈中元素数量
}

// 判断栈是否为空
bool STEmpty(ST* p) {
    assert(p != NULL);
    return p->top == 0; // 若栈顶位置为0，则栈为空
}

// 获取栈顶元素的值
int STTop(ST* p) {
    assert(p != NULL);
    assert(p->top > 0); // 确保栈非空
    return p->a[p->top - 1]; // 返回栈顶元素的值
}

// 测试代码
int main() {
    ST stack;
    STInit(&stack);

    // 测试STPush
    printf("将元素压入堆栈： \n");
    for (int i = 1; i <= 5; ++i) {
        STPush(&stack, i);
        printf("将 %d 推入堆栈。\n", i);
    }

    // 测试STSize
    printf("\n当前堆栈大小： %d\n", STSize(&stack));

    // 测试STTop
    printf("\n栈顶元素： %d\n", STTop(&stack));

    // 测试STPop
    printf("\n从堆栈中弹出元素：\n");
    while (!STEmpty(&stack)) {
        printf("从堆栈中弹出 %d 个。\n", STTop(&stack));
        STPop(&stack);
    }

    // 测试STEmpty
    printf("\n堆栈是否为空？ %s\n", STEmpty(&stack) ? "Yes" : "No");

    // 销毁栈
    STDestroy(&stack);

    return 0;
}
