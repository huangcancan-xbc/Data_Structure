#define _CRT_SECURE_NO_WARNINGS 1
#include  "stack.h"

//初始化栈，分配内存并初始化Stack结构体。
void STInit(ST* p)
{
	assert(p);

	p->a = (int*)malloc(sizeof(int) * 4);

	if (p->a == NULL) { // 如果分配失败
		perror("malloc fail");
		return;
	}

	p->capacity = 4; // 设置栈的初始容量
	p->top = -1;//top是栈顶元素位置
	//p->top=0; //top 是线顶元素的下一个位置
}


// 销毁栈，释放内存。
//如果一个数组有五个元素，前四个都有值，最后一个元素的空间被释放掉了，那么这个数组仍然有五个元素。
// 释放内存是指释放了该元素所占用的地址空间，但它不会改变数组本身的大小。
// 因此，即使最后一个元素的内存被释放，数组的大小仍然是五个元素。不过，释放后的元素不能再被访问，否则可能导致未定义行为。
void STDestroy(ST* p)
{
	assert(p);
	free(p->a);
	p->a = NULL;
	p->top = -1;
	p->capacity = 0;
}


//将给定的元素压入栈中。
void STPush(ST* p, int x)
{
	assert(p);

	if (p->top == p->capacity)
	{
		int* temp = (int*)realloc(p->a, sizeof(int) * p->capacity * 2);// 重新分配双倍空间

		if (temp == NULL)
		{
			perror("realloc fail");
			return;
		}

		p->a = temp;//更新指针
		p->capacity *= 2;//更新容量
	}

	p->a[++p->top] = x;// 压入新元素到栈顶( a[p->top++] )
}


//弹出栈顶元素。
void STPop(ST* p)
{
	assert(p);//如果栈为空，尝试弹出栈顶元素会导致未定义的行为。
	assert(!STEmpty(p)); // 检查栈是否已满

	p->top--;
}


//返回栈中元素的数量。
int STSize(ST* p)
{
	assert(p);
	return p->top;
}


//判断栈是否为空。
bool STEmpty(ST* p)
{
	assert(p);
	return p->top == -1;//如果栈为空，则返回true，否则返回false
}


//获取栈顶元素的值。
int STTop(ST* p)
{
	assert(p);
	assert(!STEmpty(p));//如果栈为空，尝试获取栈顶元素会导致未定义的行为。
	return p->a[p->top];
	//return ps->a[ps->top - 1];
}