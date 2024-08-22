#define _CRT_SECURE_NO_WARNINGS 1

//力扣：141. 环形链表
//https://leetcode.cn/problems/linked-list-cycle/description/

#include <stdio.h>

//思路：快慢指针，转换为追击问题，快指针走两步，慢指针走一步，有环一定追得上
bool hasCycle(struct ListNode* head) {
    struct ListNode* fast, * slow;
    fast = slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}
