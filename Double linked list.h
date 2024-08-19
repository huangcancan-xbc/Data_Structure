#pragma once
//Double linked list：双链表

#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<stdbool.h>

typedef struct Double_linked_list
{
	struct Double_linked_list* prev;
	int data;
	struct Double_linked_list* next;
}DLL;

//创建一个新的节点：Create a new node
DLL* Cnew_node(int x);


//初始化空的双向循环链表，返回指向头结点的指针，initialize：初始化
DLL* init_list();


//打印链表内容
void print(DLL* phead);


//检查链表是否为空:Check if the linked list is empty
bool empty(DLL* phead);


//尾插：Tail plugging
void tail_plug(DLL* phead, int x);


//头插：Header
void header(DLL* phead, int x);


//在给定的位置 pos 插入一个包含 x 的新节点:Insert a new node containing x at the given location pos
void insert(DLL* pos, int x);