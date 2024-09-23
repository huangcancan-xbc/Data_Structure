#define _CRT_SECURE_NO_WARNINGS 1

//力扣：160. 相交链表
//https://leetcode.cn/problems/intersection-of-two-linked-lists/description/

#include <stdio.h>

//思路：分别求两个链表的长度，长的链表先走差距步，然后同时走，第一个相同的地址就是交点
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
