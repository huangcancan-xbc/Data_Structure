#define _CRT_SECURE_NO_WARNINGS 1


//力扣：965. 单值二叉树
//https://leetcode.cn/problems/univalued-binary-tree/description/

//思路：各自的根值与其左右字数相比较，相同则true,不同则false,以此循环
bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }

    if (root->left && root->left->val != root->val)
    {
        return false;
    }

    if (root->right && root->right->val != root->val)
    {
        return false;
    }

    return isUnivalTree(root->left) && isUnivalTree(root->right);
}