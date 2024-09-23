#define _CRT_SECURE_NO_WARNINGS 1

//力扣：21. 合并两个有序链表
//https://leetcode.cn/problems/merge-two-sorted-lists/description/

#include <stdio.h>

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (list1 == NULL)
	{
		return list2;
	}

	if (list2 == NULL)
	{
		return list1;
	}

	struct ListNode* n1 = list1, * n2 = list2;
	struct ListNode* head = NULL, * tail = NULL;

	while (n1 && n2)
	{
		if (n1->val < n2->val)
		{
			if (head == NULL)
			{
				head = tail = n1;
			}
			else
			{
				tail->next = n1;
				tail = tail->next;
			}

			n1 = n1->next;
		}
		else
		{
			if (head == NULL)
			{
				head = tail = n2;
			}
			else
			{
				tail->next = n2;
				tail = tail->next;
			}

			n2 = n2->next;
		}
	}

	if (n1)
	{
		tail->next = n1;
	}

	if (n2)
	{
		tail->next = n2;
	}

	return head;
}






//哨兵指针：
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//	struct ListNode* n1 = list1, * n2 = list2;
//	struct ListNode* guard = NULL, * tail = NULL;
//
//	guard = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	tail->next = NULL;
//
//	while (n1 && n2)
//	{
//		if (n1->val < n2->val)
//		{
//			tail->next = n1;
//			tail = tail->next;
//			n1 = n1->next;
//		}
//		else
//		{
//			tail->next = n2;
//			tail = tail->next;
//			n2 = n2->next;
//		}
//	}
//
//	if (n1)
//	{
//		tail->next = n1;
//	}
//
//	if (n2)
//	{
//		tail->next = n2;
//	}
//
//	struct ListNode* head = guard->next;
//	free(guard);
//	return head;
//}