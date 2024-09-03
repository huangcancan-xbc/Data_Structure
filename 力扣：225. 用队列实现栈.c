#define _CRT_SECURE_NO_WARNINGS 1

//力扣：225. 用队列实现栈
//https://leetcode.cn/problems/implement-stack-using-queues/description/

//思路：保持一个队列为空，一个队列存数据。出栈就把前面的数据导入到空队列

// 定义队列中节点存储的数据类型，这里定义为字符类型 char
typedef char Datatype;

// 定义队列节点的结构体
typedef struct queue_node
{
	struct queue_node* next; // 指向下一个节点的指针
	Datatype data;           // 节点中存储的数据
} Qn;

// 定义队列的结构体
typedef struct queue
{
	Qn* head; // 指向队列头部（队首）的指针
	Qn* tail; // 指向队列尾部（队尾）的指针
	int size; // 队列中的元素个数
} Q;

// 定义栈的结构体，栈由两个队列组成
typedef struct {
	Q q1; // 栈使用的第一个队列
	Q q2; // 栈使用的第二个队列
} MyStack;

// 初始化队列，将队列的指针和大小设置为初始状态
void init(Q* p)
{
	assert(p); // 检查传入的队列指针是否为空，防止程序崩溃

	p->head = p->tail = NULL; // 初始化队列的头尾指针为NULL，表示队列为空
	p->size = 0; // 初始化队列的大小为0，表示队列没有元素
}

// 销毁队列，释放队列中所有节点占用的内存
void destroy(Q* p)
{
	assert(p); // 检查队列指针是否为空

	Qn* temp = p->head; // 从队列头部开始遍历

	while (temp) // 只要当前节点不为空，继续循环
	{
		Qn* next = temp->next; // 保存下一个节点的指针
		free(temp); // 释放当前节点的内存
		temp = next; // 移动到下一个节点
	}

	p->head = p->tail = NULL; // 将头尾指针置为NULL，表示队列为空
	p->size = 0; // 将队列大小重置为0
}

// 向队列尾部添加一个新元素
void push(Q* p, Datatype x)
{
	Qn* newnode = (Qn*)malloc(sizeof(Qn)); // 为新节点分配内存

	if (newnode == NULL) // 检查内存分配是否成功
	{
		perror("malloc fail"); // 如果内存分配失败，打印错误信息
		return;
	}

	newnode->data = x; // 将传入的数据存储到新节点的 data 字段
	newnode->next = NULL; // 新节点是新的尾节点，所以 next 指针设为 NULL

	if (p->head == NULL) // 如果队列当前为空
	{
		assert(p->tail == NULL); // 断言：队列为空时，tail 也应为 NULL
		p->head = p->tail = newnode; // 队列的头和尾都指向这个新节点
	}
	else // 如果队列不为空
	{
		p->tail->next = newnode; // 将当前尾节点的 next 指针指向新节点
		p->tail = newnode; // 更新尾指针，使其指向新节点
	}

	p->size++; // 队列大小增加 1
}

// 从队列头部移除一个元素
void pop(Q* p)
{
	assert(p); // 检查队列指针是否为空
	assert(p->head != NULL); // 确保队列不为空

	if (p->head->next == NULL) // 如果队列中只有一个元素
	{
		free(p->head); // 释放这个唯一的节点
		p->head = p->tail = NULL; // 将头尾指针都设为 NULL，表示队列为空
	}
	else // 如果队列中有多个元素
	{
		Qn* next = p->head->next; // 保存队列中第二个节点的指针
		free(p->head); // 释放队列头节点
		p->head = next; // 更新头指针，使其指向原队列中的第二个节点
	}

	p->size--; // 队列大小减 1
}

// 返回队列中元素的个数
int size(Q* p)
{
	assert(p); // 检查队列指针是否为空

	return p->size; // 返回队列的大小
}

// 检查队列是否为空
bool empty(Q* p)
{
	assert(p); // 检查队列指针是否为空

	return p->size == 0; // 如果队列大小为 0，则队列为空，返回 true；否则返回 false
}

// 获取队列头部元素的数据
Datatype front(Q* p)
{
	assert(p); // 检查队列指针是否为空
	assert(!empty(p)); // 确保队列不为空

	return p->head->data; // 返回队首节点存储的数据
}

// 获取队列尾部元素的数据
Datatype back(Q* p)
{
	assert(p); // 检查队列指针是否为空
	assert(!empty(p)); // 确保队列不为空

	return p->tail->data; // 返回队尾节点存储的数据
}

// 创建并初始化一个栈
MyStack* myStackCreate() {
	MyStack* temp = (MyStack*)malloc(sizeof(MyStack)); // 为栈分配内存
	if (temp == NULL) // 检查内存分配是否成功
	{
		perror("malloc fail"); // 如果内存分配失败，打印错误信息
		return NULL; // 返回空指针，表示创建失败
	}

	init(&temp->q1); // 初始化栈中的第一个队列
	init(&temp->q2); // 初始化栈中的第二个队列

	return temp; // 返回创建的栈的指针
}

// 向栈中压入一个元素
void myStackPush(MyStack* obj, int x) {
	if (!empty(&obj->q1)) // 如果 q1 不为空
	{
		push(&obj->q1, x); // 将元素 x 推入 q1
	}
	else // 如果 q1 为空
	{
		push(&obj->q2, x); // 将元素 x 推入 q2
	}
}

// 从栈中弹出一个元素，并返回该元素的值
int myStackPop(MyStack* obj) {
	Q* yempty = &obj->q1; // 假设 q1 是空队列
	Q* noempty = &obj->q2; // 假设 q2 是非空队列

	if (!empty(&obj->q1)) // 如果 q1 不为空
	{
		yempty = &obj->q2; // 将 yempty 设为 q2（假设 q2 是空队列）
		noempty = &obj->q1; // 将 noempty 设为 q1（假设 q1 是非空队列）
	}

	// 将非空队列中的所有元素除了最后一个，转移到另一个空队列中
	while (size(noempty) > 1)
	{
		push(yempty, front(noempty)); // 将非空队列的队首元素推入空队列
		pop(noempty); // 移除非空队列的队首元素
	}

	int top = front(noempty); // 获取非空队列中剩下的最后一个元素的值
	pop(noempty); // 移除这个元素（相当于弹出栈顶元素）

	return top; // 返回栈顶元素的值
}

// 获取栈顶元素的值（但不弹出）
int myStackTop(MyStack* obj) {
	if (!empty(&obj->q1)) // 如果 q1 不为空
	{
		return back(&obj->q1); // 返回 q1 的队尾元素（即栈顶元素）的值
	}
	else // 如果 q1 为空
	{
		return back(&obj->q2); // 返回 q2 的队尾元素（即栈顶元素）的值
	}
}

// 检查栈是否为空
bool myStackEmpty(MyStack* obj) {
	return empty(&obj->q1) && empty(&obj->q2); // 如果两个队列都为空，说明栈为空
}

// 销毁栈，释放内存
void myStackFree(MyStack* obj) {
	destroy(&obj->q1); // 销毁栈中的第一个队列，释放内存
	destroy(&obj->q2); // 销毁栈中的第二个队列，释放内存
	free(obj); // 释放栈结构体的内存
}


//着重解释：
//栈的实现思路：使用两个队列q1和q2来实现栈的功能。
//每次push操作时，将元素添加到非空的队列中；每次pop操作时，将非空队列中的所有元素（除了最后一个）转移到空队列中，然后移除并返回最后一个元素。

//队列的操作：通过定义push、pop、front、back等函数，对队列进行标准操作。这些操作用来实现栈的基本功能。

//注意点：

//myStackPop 函数中，使用两个队列的交换和转移来保证最后弹出的是最后一个插入的元素，从而实现栈的“后进先出”性质。
//myStackTop 函数获取栈顶元素的值但不移除，类似于myStackPop，但不会真正删除该元素。