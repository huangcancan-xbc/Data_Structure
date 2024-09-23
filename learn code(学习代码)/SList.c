#define _CRT_SECURE_NO_WARNINGS 1
//Single-linked lists：单链表
//Singly linked list nodes:单链表节点(SLLN)
//list:列表
//head:头
//tail:尾，尾巴
//temp:临时的

#include "SList.h"

// 单链表打印
//可以使用二级指针，但没必要，要改变实参用二级，不改变用一级！可以加 const，不建议，会带来一些不必要的麻烦！
void SList_print(SLLN* phead)
{
	//此处切不可断言（assert），空链表可以打印，此处使用断言会终止程序！
	//(单链表为空，此处指针（phead）为空。顺序表此处需断言（assert），顺序表是一个结构体，结构体里有一个指针指向一块数组空间，结构体指针为空，程序就走不了了)

	SLLN* temp = phead;
	//注意：切不可写成 while (temp->next != NULL),最后一个数据无法打印！
	 
	//正确写法：
	//while (temp != NULL)
	while (temp)
	{
		printf("%d->", temp->data);
		temp = temp->next;
		//temp++/++temp,注意：切不可加加！节点地址不能保证连续！
	}

	printf("NULL\n");
}

//提取一个公共函数：找一个新节点,lookup：查找
//这个函数全部内容来自void SList_tplug(SLLN** pphead, int x)函数的 122-135 行 
SLLN* lookup(int x)
{
	SLLN* newnode = (SLLN*)malloc(sizeof(SLLN)); // newnode: 新节点
	if (newnode == NULL) // 检查
	{
		perror("malloc fail");
		return NULL; // 返回 NULL 表示失败
	}

	// 新节点初始化为空
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

////虽然是错，但要从中吸取教训！！！总结结论！！！（着重看和理解注释部分！！！）
//// 单链表尾插	Tail plugging:尾插
//void SList_tplug(SLLN* phead, int x)
//{
//	//此处切不可断言（assert），链表为空，指针（phead）为空，此处使用断言会终止程序！
//
//	SLLN* newnode = (SLLN*)malloc(sizeof(SLLN));//newnode:新节点
//	if (newnode == NULL)//检查
//	{
//		perror("malloc fail");
//		return;
//	}
//
//	//新节点初始化为空
//	newnode->data = x;
//	newnode->next = NULL;
//
//	if (phead == NULL)
//	{
//		phead = newnode;
//	}
//	else
//	{
//		//找尾，尾插的本质：原尾节点中要存储新的尾节点地址
//		//"正确"写法(相对于此情况，但此情况（函数部分）有错)：
//		SLLN* tail = phead;//tail:尾
//		while (tail->next != NULL)
//		{
//			tail = tail->next;
//		}
//		tail->next = newnode;//精华所在！
//
//		//错误写法：
//		//SLLN* tail = phead;//tail:尾
//		//while (tail != NULL)
//		//{
//		//	tail = tail->next;
//		//}
//		//tail = newnode;
//		//原因：函数栈帧知识：tail是局部变量，之后会销毁！
//	}
//}//整个函数错误原因：
////请对比：
////
////void temp(int *p)						void temp(int *ptr)
////{										{
////	*p = 1;									ptr = (int*)malloc(sizeof(int));
////}										}
////int main()				    和			int main()
////{							和			{
////	int x = 0;				和				int* px=NULL;
////	temp(&x);								temp(px);
////
////	return 0;								return 0;
////}										}
////
////改变的是int，使用的是int的指针；改变int*要使用int*的地址，int**指针！！！
////所以要改变*ptr，使用的是*ptr的指针
////即：
////int main()
////{
////	int* px = NULL;
////	Func(&px);
////
////	free(px);
////
////	return 0;
////}
////正确的函数写法：
void SList_tplug(SLLN** pphead, int x)
{
	//为了使用 35 行的 lookup 函数将此 122 到 135 行注释掉！改成 137 行的 SLLN* newnode = lookup(x);
	
	////此处切不可断言（assert），链表为空，指针（phead）为空，此处使用断言会终止程序！

	//SLLN* newnode = (SLLN*)malloc(sizeof(SLLN));//newnode:新节点
	//if (newnode == NULL)//检查
	//{
	//	perror("malloc fail");
	//	return;
	//}

	////新节点初始化为空
	//newnode->data = x;
	//newnode->next = NULL;

	SLLN* newnode = lookup(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾，尾插的本质：原尾节点中要存储新的尾节点地址

		SLLN* tail = *pphead;//tail:尾
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;//精华所在！！！（改变指针，改变结构体成员，用一级指针，函数栈帧的知识要深挖！！！）
	}
}



// 单链表的头插		Header:头插
void SList_header(SLLN** pphead, int x)
{
	assert(pphead);

	SLLN* newnode = lookup(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

// 单链表的尾删		Tail deletion:尾删
void SList_tdel(SLLN** pphead)
{
	////错误写法：
	//SLLN* tail = *pphead;
	//while (tail->next != NULL)
	//{
	//	tail = tail->next;
	//}

	//free(tail);
	//tail = NULL;//错误原因：此行tail是局部变量，没有把前一个next节点置空，前一个节点是一个结构体，要将前一个结构体节点置空，需要一个结构体的指针！
	
	//检查二选一
	//暴力的检查
	assert(pphead);
	assert(*pphead);//或者assert(*pphead!=NULL);
	//温柔的检查
	//if (*pphead == NULL)
	//{
	//	return;
	//}

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//正确写法1：
		SLLN* temp = NULL;
		SLLN* tail = *pphead;
		while (tail->next != NULL)
		{
			temp = tail;
			tail = tail->next;
		}

		free(tail);
		tail = NULL;

		temp->next = NULL;

		//正确写法2：
		//SLLN* tail = *pphead;
		//while (tail->next->next != NULL)
		//{
			//tail = tail->next;
		//}

		//free(tail->next);
		//tail->next = NULL;
	}
}

// 单链表头删		Header deleted:头删
void SList_hdel(SLLN** pphead)
{
	//检查二选一
	//暴力的检查
	assert(pphead);
	assert(*pphead);//或者assert(*pphead!=NULL);
	//温柔的检查
	//if (*pphead == NULL)
	//{
	//	return;
	//}

	SLLN* first = *pphead;//first:第一
	*pphead = first->next;
	free(first);
	first = NULL;
}

// 单链表查找		Find:查找
SLLN* SList_find(SLLN* phead, int x)
{
	SLLN* temp = phead;

	while (temp)
	{
		if (temp->data == x)
		{
			return temp;
		}

		temp = temp->next;//更新temp
	}
	return NULL;
}
//或者使用查找打印函数：
//void SList_print_matching(SLLN* phead, int x)
//{
//	SLLN* temp = phead;
//	int found = 0; // 标记是否找到了匹配的节点
//
//	while (temp)
//	{
//		if (temp->data == x)
//		{
//			printf("%d ", temp->data); // 打印匹配的节点数据
//			found = 1; // 标记找到了匹配的节点
//		}
//		temp = temp->next;
//	}
//
//	if (!found)
//	{
//		printf("No matching elements found.\n"); // 如果没有找到匹配的节点
//	}
//	else
//	{
//		printf("\n"); // 打印换行符，使输出更加清晰
//	}
//}


//在指定节点 pos 之前插入一个新节点:Inserts a new node before specifying it
void SList_before(SLLN** pphead, SLLN* pos, int x)
{
	assert(pos);
	assert(pphead);

	if (pos == *pphead)
	{
		SList_header(pphead, x);
	}
	else
	{
		//找pos的前一个位置
		SLLN* temp = *pphead;
		while (temp->next != pos)
		{
			temp = temp->next;
		}

		SLLN* newnode = lookup(x);
		temp->next = newnode;
		newnode->next = pos;
	}
}

//删除指定节点 pos :Deletes the specified node		
void SList_del(SLLN** pphead, SLLN* pos)
{
	assert(pphead);
	assert(pos);
	//assert(*pphead);可要可不要

	if (*pphead == pos)
	{
		SList_hdel(pphead);
	}
	else
	{
		//找到pos的前一个位置
		SLLN* temp = *pphead;
		while (temp->next != pos)
		{
			temp = temp->next;
		}

		temp->next = pos->next;
		free(pos);

		//pos=NULL;没用，因为形参不改变实参（对应text6）
	}
}

//后：after
//在指定节点 pos 之后插入一个新节点:Inserts a new node after the specified node
void SList_after(SLLN* pos, int x)
{
	//经典错误！！！
	//assert(pos);
	//SLLN* newnode = lookup(x);
	//pos->next = newnode;
	//newnode->next = pos->next;
	//在将 pos 的 next 指针指向新节点 newnode 之前，必须先保存 pos 节点的下一个节点的地址，否则这部分链表将丢失。


	//正确写法：
	assert(pos);
	SLLN* newnode = lookup(x);
	newnode->next = pos->next;//保存 pos 节点的下一个节点的地址
	pos->next = newnode;//将 pos 的 next 指针指向新节点 newnode
}

//删除指定节点 pos 之后的节点:Deletes a node after the specified node
void SList_del2(SLLN* pos)
{
	assert(pos);
	assert(pos->next);

	//错误写法（不可单独出现）：
	//pos->next = pos->next->next;

	//正确写法1：
	SLLN* temp = pos->next;
	pos->next = pos->next->next;
	free(temp);
	temp = NULL;

	//正确写法2：
	//SLLN* temp = pos->next;
	//pos->next = temp->next;
	//free(temp);
	//temp = NULL;
}

//链表销毁，Destroyed：销毁
void Destroyed(SLLN* phead)
{
	//经典错误：
	//错误写法1：
	//SLLN* temp = phead;
	//while (temp)
	//{
	//	free(temp);
	//	temp = temp->next;
	//}
	//错误写法2：
	//SLLN* temp = phead;
	//while (temp)
	//{
	//	SLLN* tmp = temp;
	//	free(temp);
	//	temp = tmp->next;
	//}


	//正确写法：
	SLLN* temp = phead;
	while (temp)
	{
		SLLN* tmp = temp->next;
		free(temp);
		temp = tmp;
	}

	//phead=NULL;
}
//或者：
//void Destroyed(SLLN** pphead)
//{
//	assert(pphead);
//	SLLN* temp = *pphead;
//	while (temp)
//	{
//		SLLN* tmp = temp->next;
//		free(temp);
//		temp = tmp;
//	}
//
//	*pphead = NULL;
//}