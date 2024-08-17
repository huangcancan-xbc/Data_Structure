#pragma once
//stack:栈

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct stack
{
	int capacity;//capacity:容量
	int top;//top 是线顶元素的下一个位置
	int* a;// 存储栈元素的指针
}ST;


//初始化栈，分配内存并初始化Stack结构体。
void STInit(ST* p);


// 销毁栈，释放内存。
void STDestroy(ST* p);

//将给定的元素压入栈中。
void STPush(ST* p, int x);


//弹出栈顶元素。
void STPop(ST* p);


//返回栈中元素的数量。
int STSize(ST* p);


//判断栈是否为空。
bool STEmpty(ST* p);


//获取栈顶元素的值。
int STTop(ST* p);