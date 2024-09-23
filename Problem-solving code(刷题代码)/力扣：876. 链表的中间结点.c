#define _CRT_SECURE_NO_WARNINGS 1

//力扣：876. 链表的中间结点
//https://leetcode.cn/problems/middle-of-the-linked-list/description/

//思路：slow 一次走一个节点，fast 一次走两个节点

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow, * fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}