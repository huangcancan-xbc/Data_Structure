#define _CRT_SECURE_NO_WARNINGS 1

//牛客：BM24 二叉树的中序遍历
//https://www.nowcoder.com/practice/0bf071c135e64ee2a027783b80bf781d?tpId=295&tqId=1512964&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

//思路：（1）先算给定二叉树的节点个数，
//（2）根据节点个数给数组a开辟动态空间，
//（3）指针i 指向 i 的地址，i 的值作为数组a的下标。

int size(struct TreeNode* root)
{
    return root == NULL ? 0 : size(root->left) + size(root->right) + 1;
    // 如果节点为空，则返回0
}

void inorder(struct TreeNode* root, int* a, int* i)
{
    // 如果节点为空，则直接返回
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, a, i);// 递归遍历左子树
    a[(*i)++] = root->val;// 将当前节点的值存入数组的当前索引位置，并使索引自增

    inorder(root->right, a, i);// 递归遍历右子树
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // write code here
    (*returnSize) = size(root);// 获取树的大小
    int* a = (int*)malloc(sizeof(int) * (*returnSize));// 动态分配数组以保存遍历结果

    int i = 0;// 初始化数组索引
    inorder(root, a, &i);// 开始先序遍历并将结果存储到数组中

    return a;// 返回结果数组
}