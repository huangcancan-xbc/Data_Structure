#define _CRT_SECURE_NO_WARNINGS 1

//牛客：链表中倒数第k个结点
//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking

#include <stdio.h>

struct Listnode* FindkthTotail(struct Listnode* phead, int k)
{
    if (phead == NULL)
    {
        return NULL;
    }
    struct Listnode* slow, * fast;
    slow = fast = phead;

    while (k--)
    {
        if (fast == NULL)
        {
            return NULL;
        }

        fast = fast->next;
    }

    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}