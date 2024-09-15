#define _CRT_SECURE_NO_WARNINGS 1

//https://www.nowcoder.com/practice/f23604257af94d939848729b1a5cda08?tpId=295&tqId=1008897&ru=/exam/intelligent&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Fintelligent
//思路：使用了 "快慢指针" 方法来找到链表的中间节点，然后递归地对两边的链表进行排序，最后合并两个排序好的链表。

// 合并两个已排序的链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummyNode = { 0, NULL };
    struct ListNode* tail = &dummyNode;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) {
        tail->next = l1;
    }
    else {
        tail->next = l2;
    }

    return dummyNode.next;
}
struct ListNode* sortInList(struct ListNode* head) {
    // write code here
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // 寻找中间节点
    struct ListNode* slow = head, * fast = head, * prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // 断开链表
    prev->next = NULL;

    // 对左右两部分分别递归排序
    struct ListNode* left = sortInList(head);
    struct ListNode* right = sortInList(slow);

    // 合并两部分
    return mergeTwoLists(left, right);
}