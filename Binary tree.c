#define _CRT_SECURE_NO_WARNINGS 1
// Binary tree：二叉树
// Create a tree: 创建树/链接树
#include <stdio.h> // 标准输入输出头文件
#include <assert.h> // 断言头文件
#include <stdlib.h> // 标准库头文件，包含内存分配函数如 malloc

// 定义数据类型为整型
typedef int datatype;
// 定义二叉树节点结构体
typedef struct Binarytree
{
    datatype data; // 节点存储的数据
    struct Binarytree* left; // 左子树指针
    struct Binarytree* right; // 右子树指针
} BT,*c;

// 创建一个新节点并初始化
BT* node(datatype x)
{
    BT* newNode = (BT*)malloc(sizeof(BT)); // 分配内存
    if (newNode == NULL) // 检查内存分配是否成功
    {
        perror("malloc fail"); // 如果失败，打印错误信息
        return NULL; // 返回空指针
    }

    newNode->data = x; // 初始化节点数据
    newNode->left = NULL; // 初始化左子树为空
    newNode->right = NULL; // 初始化右子树为空

    return newNode; // 返回新创建的节点
}

// 构建一棵二叉树
c create()
{
    BT* node1 = node(1); // 创建根节点
    BT* node2 = node(2); // 创建左子节点
    BT* node3 = node(3); // 创建左子节点的左子节点
    BT* node4 = node(4); // 创建右子节点
    BT* node5 = node(5); // 创建右子节点的左子节点
    BT* node6 = node(6); // 创建右子节点的右子节点
    BT* node7 = node(7); // 创建左子节点的左子节点的左子节点

    node1->left = node2; // 设置根节点的左子节点
    node1->right = node4; // 设置根节点的右子节点
    node2->left = node3; // 设置左子节点的左子节点
    node4->left = node5; // 设置右子节点的左子节点
    node4->right = node6; // 设置右子节点的右子节点
    node3->left = node7; // 设置左子节点的左子节点的左子节点

    return node1; // 返回根节点
}

// 前序遍历
void preorder(BT* root)
{
    if (root == NULL) // 如果节点为空，打印 NULL
    {
        printf("NULL "); // 原有注释
        return;
    }

    printf("%d ", root->data); // 访问根节点
    preorder(root->left); // 遍历左子树
    preorder(root->right); // 遍历右子树
}

// 中序遍历
void inorder(BT* root)
{
    if (root == NULL) // 如果节点为空，打印 NULL
    {
        printf("NULL "); // 原有注释
        return;
    }

    inorder(root->left); // 遍历左子树
    printf("%d ", root->data); // 访问根节点
    inorder(root->right); // 遍历右子树
}

// 后序遍历
void postorder(BT* root)
{
    if (root == NULL) // 如果节点为空，打印 NULL
    {
        printf("NULL "); // 原有注释
        return;
    }

    postorder(root->left); // 遍历左子树
    postorder(root->right); // 遍历右子树
    printf("%d ", root->data); // 访问根节点
}



//int size = 0;
//void TreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return;
//
//	++size;
//	TreeSize(root->left);
//	TreeSize(root->right);
//}
//缺点:
//这个函数是基于全局变量 size 的。这意味着它不是纯函数，每次调用的结果依赖于外部状态，这可能导致难以预料的行为和调试困难。
//每次调用该函数之前都需要重置 size 的值为 0，否则会累加之前的计数结果。
//如果有多个树需要计算大小，这个函数无法同时处理，因为全局变量 size 只有一个实例。

//void TreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//		return;
//
//	++(*psize);
//	TreeSize(root->left, psize);
//	TreeSize(root->right, psize);
//}
//缺点:
//虽然避免了使用全局变量，但是仍然不是一个纯函数，因为它修改了传入的参数 psize。
//和第一个版本一样，如果需要计算多棵树的大小，则需要在每次调用前重置 psize。
//传递指针增加了代码的复杂性，并且可能引入空指针错误的风险。

// 计算二叉树的节点个数
int size(BT* root)
{
    return root == NULL ? 0 : (size(root->left) + size(root->right) + 1); // 递归计算左右子树的节点个数，并加上根节点
}
//优点：
//易于理解：这个函数非常直观，直接用数学方式表达出树的大小计算逻辑。
//无副作用：这个函数不改变任何外部变量，只依赖传入的参数。
//独立性：你可以多次调用这个函数来计算不同的树的大小，每次调用之间不会互相干扰。
//安全可靠：不需要担心忘记重置变量或传递错误的指针等问题。
//简洁高效：代码简洁，递归调用自然地符合树的结构，易于实现和维护。


// 计算二叉树的高度
int high(BT* root)
{
    if (root == NULL)
    {
        return 0; // 空树高度为 0
    }

    int lefthigh = high(root->left); // 计算左子树的高度
    int righthigh = high(root->right); // 计算右子树的高度

    return lefthigh > righthigh ? lefthigh + 1 : righthigh + 1; // 返回较高的一边的高度加一
}

// 计算给定层级上的节点数      tier:层
int tier(BT* root, int k)
{
    assert(k > 0); // 断言层级必须大于零

    if (root == NULL)
    {
        return 0; // 空树的层级节点数为 0
    }

    if (k == 1)
    {
        return 1; // 当层级为 1 时，返回根节点
    }

    return tier(root->left, k - 1) + tier(root->right, k - 1); // 递归计算左右子树上指定层级的节点数
}


// 查找给定数据值 x 在二叉树中的节点
BT* find(BT* root, datatype x)
{
    // 如果当前节点为空，说明没有找到目标值，返回 NULL
    if (root == NULL)
    {
        return NULL;
    }

    // 如果当前节点的数据等于目标值 x，那么返回当前节点
    if (root->data == x)
    {
        return root;
    }

    // 递归地在左子树中查找目标值 x
    BT* lret = find(root->left, x);
    // 如果在左子树中找到了目标值 x，返回找到的节点
    if (lret)
    {
        return lret;
    }

    // 递归地在右子树中查找目标值 x
    BT* rret = find(root->right, x);
    // 如果在右子树中找到了目标值 x，返回找到的节点
    if (rret)
    {
        return rret;
    }

    // 如果在当前节点、左子树以及右子树中都没有找到目标值 x，则返回 NULL
    return NULL;
}

int main()
{
    BT* root = create(); // 创建二叉树

    preorder(root); // 前序遍历
    printf("\n");

    inorder(root); // 中序遍历
    printf("\n");

    postorder(root); // 后序遍历
    printf("\n");

    printf("%d\n", size(root)); // 输出树的节点数

    printf("%d\n", tier(root, 1)); // 输出第一层的节点数
    printf("%d\n", tier(root, 2)); // 输出第二层的节点数

    printf("%d\n", high(root)); // 输出树的高度

    printf("%p\n", find(root, 5));//查找5的地址

    return 0; // 主函数返回
}