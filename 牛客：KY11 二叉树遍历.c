#define _CRT_SECURE_NO_WARNINGS 1

//牛客：KY11 二叉树遍历
//https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking

#include <stdio.h>

struct TreeNode
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* node(char* a, int* p)
{
    if (a[(*p)] == '#')
    {
        (*p)++;
        return NULL;
    }

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = a[(*p)++];
    root->left = node(a, p);
    root->right = node(a, p);

    return root;
}

void inorder(struct TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%c ", root->val);
    inorder(root->right);
}

int main() {
    char a[100];
    scanf("%s", a);
    int i = 0;

    struct TreeNode* root = node(a, &i);
    inorder(root);
    return 0;
}