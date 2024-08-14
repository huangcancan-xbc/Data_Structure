#pragma once
//Single-linked lists：单链表(SList)
//list:列表

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//node:节点
//next:下一个
//data：数据
//Singly linked list nodes:单链表节点(SLLN)

typedef struct SListnode
{
	int data;
	struct SListnode* next;
}SLLN;
//等价于：
//struct SListnode
//{
//	int data;
//	struct SListnode* next;
//};
//typedef struct SListnode SLLN;

//找节点
SLLN* lookup(int x);

// 动态申请一个节点:Dynamically apply for a node
//SLLN* Da_node(int x);

// 单链表打印
void SList_print(SLLN* phead);


// 单链表尾插	Tail plugging:尾插
//void SList_tplug(SLLN* phead, int x);//错！
void SList_tplug(SLLN** pphead, int x);//对！


// 单链表的头插		Header:头插
void SList_header(SLLN** pphead, int x);

// 单链表的尾删		Tail deletion:尾删
void SList_tdel(SLLN** pphead);

// 单链表头删		Header deleted:头删
void SList_hdel(SLLN** pphead);

// 单链表查找		Find:查找
SLLN* SList_find(SLLN* phead, int x);
//void SList_print_matching(SLLN* phead, int x);

//在指定节点 pos 之前插入一个新节点:Inserts a new node before specifying it
void SList_before(SLLN** pphead, SLLN* pos, int x);

//删除指定节点 pos :Deletes the specified node		
void SList_del(SLLN** pphead, SLLN* pos);

//后：after
//在指定节点 pos 之后插入一个新节点:Inserts a new node after the specified node
void SList_after(SLLN* pos, int x);

//删除指定节点 pos 之后的节点:Deletes a node after the specified node
void SList_del2(SLLN* pos);

//链表销毁，Destroyed：销毁
void Destroyed(SLLN* phead);
//void Destroyed(SLLN** pphead);或者
