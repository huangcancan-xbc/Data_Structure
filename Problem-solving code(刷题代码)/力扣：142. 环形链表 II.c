#define _CRT_SECURE_NO_WARNINGS 1

//力扣：142. 环形链表 II
//https://leetcode.cn/problems/linked-list-cycle-ii/description/

#include <stdio.h>

//思路：用快慢指针，看似编程题，实际是逻辑推导题，
//2*（起始点到入口点的距离+入口点到相遇点的距离）= 起始点到入口点的距离 + n * 环的长度+入口点到相遇点的距离 => 结论：一个指针从相遇点走，一个指针从起始点走，最终一定会在环的入口点相遇
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast, * slow;
    fast = slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            struct ListNode* meet = slow;
            struct ListNode* start = head;

            while (meet != start)
            {
                meet = meet->next;
                start = start->next;
            }

            return meet;
        }
    }

    return NULL;
}



//思路2：将相遇点的下一个节点断开，这样问题就转换成了找相交链表的交点
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* tailA = headA, * tailB = headB;
    int lengA = 1, lengB = 1;

    while (tailA->next)
    {
        tailA = tailA->next;
        lengA++;
    }

    while (tailB->next)
    {
        tailB = tailB->next;
        lengB++;
    }

    if (tailA != tailB)
    {
        return NULL;
    }

    int gap = abs(lengA - lengB);
    struct ListNode* longlist = headA, * shortlist = headB;

    if (lengA < lengB)
    {
        longlist = headB;
        shortlist = headA;
    }

    while (gap--)
    {
        longlist = longlist->next;
    }

    while (longlist != shortlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }

    return longlist;
}
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast, * slow;
    fast = slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            struct ListNode* meet = slow;
            struct ListNode* n1 = meet->next;
            struct ListNode* n2 = head;

            meet->next = NULL;
            return getIntersectionNode(n1, n2);
        }
    }

    return NULL;
}