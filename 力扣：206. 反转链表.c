#define _CRT_SECURE_NO_WARNINGS 1

//力扣：206. 反转链表
//https://leetcode.cn/problems/reverse-linked-list/description/

#include <stdio.h>

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
    {
        return NULL;
    }

    struct ListNode* n1, * n2, * n3;
    n1 = NULL;
    n2 = head;
    n3 = n2->next;

    while (n2)
    {
        n2->next = n1;

        n1 = n2;
        n2 = n3;
        if (n3)
        {
            n3 = n3->next;
        }
    }

    return n1;
}



//取原节点头插到新链表：
//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* temp = head, * newhead = NULL;
//    while (temp)
//    {
//        struct ListNode* next = temp->next;
//
//        //头插
//        temp->next = newhead;
//        newhead = temp;
//
//        temp = next;
//    }
//
//    return newhead;
//}