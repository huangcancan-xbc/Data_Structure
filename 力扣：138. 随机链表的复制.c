#define _CRT_SECURE_NO_WARNINGS 1

//力扣：138. 随机链表的复制
//https://leetcode.cn/problems/copy-list-with-random-pointer/description/

#include <stdio.h>
//思路：插入拷贝节点：
//创建一个新节点，并将其值设置为当前节点的值。
//将新节点插入到当前节点和当前节点的下一个节点之间。
//这样做之后，原链表变成了一个交错的形式，例如原链表为 A->B->C->D，现在变为 A->A' -> B -> B'->C->C' -> D -> D'，其中带 ' 的节点是拷贝节点。
//处理拷贝节点的 random 指针：
//对于每一个拷贝节点 A'，如果原节点 A 的 random 指向某个节点 X，那么 A' 的 random 指向 X 后面的节点（即 X'）。
//如果 A 的 random 是 null，则 A' 的 random 也应该是 null。
//拆分并重建链表：
//从交错的链表中分离出拷贝节点链表。
//在这个过程中同时恢复原链表到原始状态。
struct Node* copyRandomList(struct Node* head) {
    //1. 插入拷贝节点在原节点的后面
    struct Node* cur = head;

    while (cur)
    {
        //插入
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        struct Node* next = cur->next;

        //cur copy next
        cur->next = copy;
        copy->next = next;

        cur = next;
    }

    //处理拷贝的节点的random
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;

        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }

        cur = cur->next->next;
    }
    //拷贝节点解下来，链接成新链表，并且恢复原链表
    struct Node* copyhead = NULL, * copytail = NULL;
    cur = head;

    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;

        //copy尾插
        if (copyhead == NULL)
        {
            copyhead = copytail = copy;
        }
        else
        {
            copytail->next = copy;
            copytail = copytail->next;
        }
        //恢复原链表
        cur->next = next;

        cur = next;
    }

    return copyhead;
}





//具体的步骤说明：

//步骤 1: 插入拷贝节点
//初始化一个指针 cur 指向原链表的头节点。
//当 cur 不为空时，创建一个拷贝节点 copy 并插入到 cur 和 cur->next 之间。
//更新 cur 以遍历整个链表。
//步骤 2 : 设置随机指针
//再次初始化 cur 指向原链表的头节点。
//当 cur 不为空时，设置 cur 的拷贝节点 cur->next 的 random 指针。
//更新 cur 以遍历整个链表。
//步骤 3 : 拆分链表
//初始化两个指针 copyhead 和 copytail 用于构建拷贝链表。
//再次初始化 cur 指向原链表的头节点。
//当 cur 不为空时，将拷贝节点从交错链表中分离出来，并连接到 copytail 的后面。
//更新 cur 的 next 指针，使其指向拷贝节点的下一个节点，从而恢复原链表。
//更新 cur 以遍历整个链表。
//返回 copyhead 作为拷贝链表的头节点。
//这种方法的时间复杂度是 O(N)，空间复杂度也是 O(N) 因为需要额外的空间来存储拷贝节点。这种解决方案不需要额外的数据结构，直接在原链表上操作，最后通过拆分得到新的链表。




struct Node* copyRandomList(struct Node* head) {
    //1. 插入拷贝节点在原节点的后面
    struct Node* cur = head;

    while (cur) {
        //插入
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        copy->random = NULL; // 初始化 random 指针
        struct Node* next = cur->next;

        //cur copy next
        cur->next = copy;
        copy->next = next;

        cur = next;
    }

    //2. 设置新节点的 random 指针
    cur = head;
    while (cur) {
        struct Node* copy = cur->next;

        if (cur->random == NULL) {
            copy->random = NULL;
        }
        else {
            copy->random = cur->random->next;
        }

        cur = cur->next->next;
    }

    //3. 拷贝节点解下来，链接成新链表，并且恢复原链表
    struct Node* copyhead = NULL, * copytail = NULL;
    cur = head;

    while (cur) {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;

        //copy尾插
        if (copyhead == NULL) {
            copyhead = copytail = copy;
        }
        else {
            copytail->next = copy;
            copytail = copytail->next;
        }
        //恢复原链表
        cur->next = next;

        cur = next;
    }

    //确保新链表的尾部节点的 next 指针为 NULL
    if (copytail != NULL) {
        copytail->next = NULL;
    }

    return copyhead;
}