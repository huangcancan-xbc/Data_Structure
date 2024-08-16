#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
struct student
{
	char name[15];
	int age;
	struct student* next;
};

typedef struct student stu;

int main()
{
	stu* p = NULL, * head = NULL, * tail = NULL;
	p = (stu*)malloc(sizeof(struct student));
	head = p;
	tail = p;
	head->next = NULL;

	int n = 3;

	for (int i = 0; i < n; i++)
	{
		p = (stu*)malloc(sizeof(struct student));
		printf("请输入学生姓名：");
		scanf("%s", &p->name);
		printf("请输入学生年龄：");
		scanf("%d", &p->age);
		tail->next = p;
		tail = p;
		tail->next = NULL;
	}

	p = head->next;

	while (p != NULL)
	{
		printf("姓名：%s\t年龄：%d\n", p->name, p->age);
		p = p->next;
	}

	return 0;
}





//#include <stdio.h>
//#include <stdlib.h>
//
//// 结构体定义
//struct student {
//    char name[15];
//    int age;
//    struct student* next;
//};
//
//// 别名定义
//typedef struct student stu;
//
//// 函数声明
//void printList(stu* head);
//
//int main() {
//    stu* p = NULL;
//    stu* head = NULL;
//    stu* tail = NULL;
//
//    // 输入学生数量
//    int n;
//    printf("请输入学生数量：");
//    if (scanf("%d", &n) != 1) {
//        fprintf(stderr, "输入错误，请输入一个整数。\n");
//        return EXIT_FAILURE;
//    }
//
//    for (int i = 0; i < n; i++) {
//        p = (stu*)malloc(sizeof(stu));
//        if (p == NULL) {
//            fprintf(stderr, "内存分配失败。\n");
//            return EXIT_FAILURE;
//        }
//
//        printf("请输入第 %d 位学生的姓名：", i + 1);
//        if (scanf("%14s", p->name) != 1) {
//            fprintf(stderr, "姓名输入错误。\n");
//            free(p);
//            return EXIT_FAILURE;
//        }
//
//        printf("请输入第 %d 位学生的年龄：", i + 1);
//        if (scanf("%d", &p->age) != 1) {
//            fprintf(stderr, "年龄输入错误。\n");
//            free(p);
//            return EXIT_FAILURE;
//        }
//
//        // 如果链表为空，这是第一个节点
//        if (head == NULL) {
//            head = tail = p;
//        }
//        else {
//            // 否则，将新节点添加到链表的末尾
//            tail->next = p;
//            tail = p;
//        }
//        tail->next = NULL;
//    }
//
//    // 输出链表
//    printList(head);
//
//    // 释放内存
//    while (head != NULL) {
//        stu* temp = head;
//        head = head->next;
//        free(temp);
//    }
//
//    return 0;
//}
//
//// 打印链表中的所有学生信息
//void printList(stu* head) {
//    stu* p = head;
//    while (p != NULL) {
//        printf("姓名：%s\t年龄：%d\n", p->name, p->age);
//        p = p->next;
//    }
//}