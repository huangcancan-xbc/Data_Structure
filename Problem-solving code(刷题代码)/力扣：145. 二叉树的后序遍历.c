#define _CRT_SECURE_NO_WARNINGS 1

//力扣：145. 二叉树的后序遍历
//https://leetcode.cn/problems/binary-tree-postorder-traversal/description/

int size(struct TreeNode* root)
{
    return root == NULL ? 0 : size(root->left) + size(root->right) + 1;
}

void postorder(struct TreeNode* root, int* a, int* i)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left, a, i);
    postorder(root->right, a, i);
    a[(*i)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    (*returnSize) = size(root);
    int* a = (int*)malloc(sizeof(int) * (*returnSize));

    int i = 0;
    postorder(root, a, &i);

    return a;
}