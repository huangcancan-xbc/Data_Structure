#define _CRT_SECURE_NO_WARNINGS 1

//力扣：203. 移除链表元素
//https://leetcode.cn/problems/remove-linked-list-elements/description/

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* p = NULL;
    struct ListNode* tail = head;
    while (tail)
    {
        if (tail->val != val)
        {
            p = tail;
            tail = tail->next;
        }
        else
        {
            if (p == NULL)
            {
                head = tail->next;
                free(tail);
                tail = head;
            }
            else
            {
                p->next = tail->next;
                free(tail);
                tail = p->next;//错误写法：tail=tail->next,上一步已经释放了空间，无法访问，会内存泄露
            }
        }
    }

    return head;
}

//法二（不是 val 的值，尾插到新链表）：
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* newHead = NULL, * tail = NULL;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        if (cur->val != val)
//        {
//            // 尾插
//            if (tail == NULL)
//            {
//                newHead = tail = cur;
//            }
//            else
//            {
//                tail->next = cur;
//                tail = tail->next;
//            }
//
//            cur = cur->next;
//        }
//        else
//        {
//            struct ListNode* next = cur->next;
//            free(cur);
//            cur = next;
//        }
//    }
//
//    if (tail)
//    {
//        tail->next = NULL;
//    }
//
//    return newHead;
//}




//快速手搓链表，快速调试分析：
//int main()
//{
//    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    n1->val = 7;
//    n2->val = 7;
//    n3->val = 7;
//    n4->val = 7;
//
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = NULL;
//
//    removeElements(n1, 7);
//
//    return 0;
//}