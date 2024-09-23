#define _CRT_SECURE_NO_WARNINGS 1

//牛客：CM11 链表分割
//https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking

#include <stdio.h>

//思想：用两个哨兵头节点，比x小的放入一个新链表，大的放入另外一个链表，最后将两个链表链接起来
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        struct ListNode* gguard, * gtail, * lguard, * ltail;
        gguard = gtail = (struct ListNode*)malloc(sizeof(struct ListNode));
        lguard = ltail = (struct ListNode*)malloc(sizeof(struct ListNode));

        gtail->next = ltail->next = NULL;

        struct ListNode* temp = pHead;

        while (temp)
        {
            if (temp->val < x)
            {
                ltail->next = temp;
                ltail = ltail->next;
            }
            else
            {
                gtail->next = temp;
                gtail = gtail->next;
            }

            temp = temp->next;
        }

        ltail->next = gguard->next;
        gtail->next = NULL;

        pHead = lguard->next;

        free(gguard);
        free(lguard);

        return pHead;
    }
};