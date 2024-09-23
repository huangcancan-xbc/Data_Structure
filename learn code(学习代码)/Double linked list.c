#define _CRT_SECURE_NO_WARNINGS 1
#include "Double linked list.h"

//Double linked list：双链表

//创建一个新的节点：Create a new node
DLL* Cnew_node(int x)
{
	DLL* newnode = (DLL*)malloc(sizeof(DLL));
	if (newnode == NULL)
	{
		perror("malloc fail");
		//exit(-1);//如果分配内存失败，则终止程序
	}

	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}


//初始化空的双向循环链表，返回指向头结点的指针，initialize：初始化
DLL* init_list()
{
	DLL* phead = Cnew_node(-1);

	phead->next = phead;
	phead->prev = phead;

	return phead;
}


//打印链表内容
void print(DLL* phead)
{
	assert(phead);

	printf("<->head<->");
	DLL* temp = phead->next;

	while (temp != phead)
	{
		printf("%d<->", temp->data);
		temp = temp->next;
	}

	printf("\n");
}


//检查链表是否为空:Check if the linked list is empty
bool empty(DLL* phead)
{
	assert(phead);

	return phead->next == phead;
}


//尾插：Tail plugging
void tail_plug(DLL* phead, int x)
{
	assert(phead);

	insert(phead, x);
}


//头插：Header
void header(DLL* phead, int x)
{
	assert(phead);

	insert(phead->next, x);
}


//在给定的位置 pos 插入一个包含 x 的新节点:Insert a new node containing x at the given location pos
void insert(DLL* pos, int x)
{
	assert(pos); // 确保 pos 不是 NULL

	DLL* prev = pos->prev; // 获取 pos 节点的前一个节点
	DLL* newnode = Cnew_node(x); // 创建一个包含数据 x 的新节点

	// 更新 prev 节点的 next 指针，使其指向新节点
	prev->next = newnode;

	// 设置新节点的 prev 指针，使其指向 prev 节点
	newnode->prev = prev;

	// 设置新节点的 next 指针，使其指向 pos 节点
	newnode->next = pos;

	// 更新 pos 节点的 prev 指针，使其指向新节点
	pos->prev = newnode;
}


