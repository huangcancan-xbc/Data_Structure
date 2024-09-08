#define _CRT_SECURE_NO_WARNINGS 1

//力扣：94. 二叉树的中序遍历
//https://leetcode.cn/problems/binary-tree-inorder-traversal/description/

int size(struct TreeNode* root)
{
    return root == NULL ? 0 : size(root->left) + size(root->right) + 1;
}

void inorder(struct TreeNode* root, int* a, int* i)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, a, i);
    a[(*i)++] = root->val;
    inorder(root->right, a, i);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    (*returnSize) = size(root);
    int* a = (int*)malloc(sizeof(int) * (*returnSize));

    int i = 0;
    inorder(root, a, &i);
    return a;
}