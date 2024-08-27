#define _CRT_SECURE_NO_WARNINGS 1

//牛客：OR36 链表的回文结构
//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking


#include <stdio.h>

//思路：用快慢指针找到中间节点，从中间开始，对后半段逆置，前后半段进行比较。
class PalindromeList {
public:
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

    struct ListNode* reverseList(struct ListNode* head) {
        struct ListNode* temp = head, * newhead = NULL;
        while (temp)
        {
            struct ListNode* next = temp->next;

            //头插
            temp->next = newhead;
            newhead = temp;

            temp = next;
        }

        return newhead;
    }
    bool chkPalindrome(ListNode* A) {
        struct ListNode* mid = middleNode(A);
        struct ListNode* rhead = reverseList(mid);

        while (A && rhead)
        {
            if (A->val != rhead->val)
            {
                return false;
            }

            A = A->next;
            rhead = rhead->next;
        }

        return true;
    }
};