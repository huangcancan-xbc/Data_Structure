#define _CRT_SECURE_NO_WARNINGS 1
#include "Double linked list.h"

//Double linked list：双链表

int main() {
    // 初始化链表
    DLL* list = init_list();

    // 测试空链表检查
    printf("列表是空的吗？ %s\n", empty(list) ? "Yes" : "No");

    // 测试头插
    header(list, 10);
    header(list, 20);
    header(list, 30);

    // 打印链表内容
    printf("头部插入后的列表：\n");
    print(list);

    // 测试尾插
    tail_plug(list, 40);
    tail_plug(list, 50);
    tail_plug(list, 60);

    // 打印链表内容
    printf("尾部插入后的列表：\n");
    print(list);

    // 测试插入到指定位置
    insert(list->next->next, 25); // 在第二个节点之后插入25
    printf("在第二个元素后插入 25 后的列表：\n");
    print(list);

    // 再次检查链表是否为空
    printf("列表是空的吗？ %s\n", empty(list) ? "Yes" : "No");

    // 销毁链表（注意：实际代码中应实现销毁函数）
    // destroy_list(list); // 假设实现了这个函数

    return 0;
}