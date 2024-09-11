#define _CRT_SECURE_NO_WARNINGS 1

//力扣：144. 二叉树的前序遍历
//https://leetcode.cn/problems/binary-tree-preorder-traversal/description/

//思路：（1）先算给定二叉树的节点个数，
//（2）根据节点个数给数组a开辟动态空间，
//（3）指针i 指向 i 的地址，i 的值作为数组a的下标。

int size(struct TreeNode* root)
{
    return root == NULL ? 0 : size(root->left) + size(root->right) + 1;
}

void preorder(struct TreeNode* root, int* a, int* i)
{
    if (root == NULL)
    {
        return;
    }

    a[(*i)++] = root->val;
    preorder(root->left, a, i);
    preorder(root->right, a, i);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    (*returnSize) = size(root);
    int* a = (int*)malloc(sizeof(int) * (*returnSize));

    int i = 0;
    preorder(root, a, &i);
    return a;
}