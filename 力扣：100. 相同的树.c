#define _CRT_SECURE_NO_WARNINGS 1

//力扣：100. 相同的树
//https://leetcode.cn/problems/same-tree/description/

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
    {
        return true;
    }

    if (q == NULL || p == NULL)
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}