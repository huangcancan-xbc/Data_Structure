#define _CRT_SECURE_NO_WARNINGS 1
//list:列表
//text:测试

#include "SList.h"

//第一次测试：
void text1()
{
	//此处错误对应 SList.c 文件 51 到 119 行，两处错误需同时取消注释，并将正确部分注释掉，可查看错误效果！
	/*SLLN* plist = NULL;
	SList_tplug(plist, 1);
	SList_tplug(plist, 2);
	SList_tplug(plist, 3);
	SList_tplug(plist, 4);
	SList_tplug(plist, 5);*/

	//不改变实参直接传，要改变传地址！
	
	//正确写法（要传地址！）：
	SLLN* plist = NULL;
	SList_tplug(&plist, 1);
	SList_tplug(&plist, 2);
	SList_tplug(&plist, 3);
	SList_tplug(&plist, 4);
	SList_tplug(&plist, 5);

	SList_print(plist);//不改变实参直接传，要改变传地址！

}

//第二次测试：
void text2()
{
	SLLN* plist = NULL;
	SList_header(&plist, 1);
	SList_header(&plist, 2);
	SList_header(&plist, 3);
	SList_header(&plist, 4);
	SList_header(&plist, 5);

	SList_print(plist);

	SList_tdel(&plist);
	SList_print(plist);

	SList_tdel(&plist);
	SList_print(plist);

	SList_tdel(&plist);
	SList_print(plist);
}

//第三次测试：
void text3()
{
	SLLN* plist = NULL;
	SList_tplug(&plist, 1);
	SList_tplug(&plist, 2);
	SList_tplug(&plist, 3);
	SList_tplug(&plist, 4);
	SList_tplug(&plist, 5);

	SList_print(plist);

	SList_hdel(&plist);
	SList_print(plist);

	SList_hdel(&plist);
	SList_print(plist);

	SList_hdel(&plist);
	SList_print(plist);

	SList_hdel(&plist);
	SList_print(plist);
}

//第四次测试：
void text4()
{
	SLLN* plist = NULL;
	SList_tplug(&plist, 1);
	SList_tplug(&plist, 2);
	SList_tplug(&plist, 3);
	SList_tplug(&plist, 4);
	SList_tplug(&plist, 5);

	SList_print(plist);

	//值为2的那个节点 *2
	SLLN* temp = SList_find(plist, 2);
	temp->data *= 2;
	SList_print(plist);

}

//第五次测试：
void text5()
{
	SLLN* plist = NULL;
	SList_tplug(&plist, 1);

	SList_tplug(&plist, 1);
	SList_tplug(&plist, 2);
	SList_tplug(&plist, 3);
	SList_tplug(&plist, 4);
	SList_tplug(&plist, 5);

	SList_print(plist);
	// 值为2那个节点  *2
	SLLN* temp = SList_find(plist, 2);
	SList_before(&plist, temp, 20);
	SList_print(plist);

}

//第六次测试：
void text6()
{
	SLLN* plist = NULL;
	SList_tplug(&plist, 1);

	SList_tplug(&plist, 1);
	SList_tplug(&plist, 2);
	SList_tplug(&plist, 3);
	SList_tplug(&plist, 4);
	SList_tplug(&plist, 5);

	SList_print(plist);
	// 值为2那个节点  *2
	SLLN* temp = SList_find(plist, 2);
	SList_del(&plist, temp);
	temp = NULL;//此处置空，或者别用即可

	SList_print(plist);

	Destroyed(plist);
	plist = NULL;
	//或者（ 用于void Destroyed(SLLN** pphead); 生效时 ！！）：
	//Destroyed(&plist);
	//plist = NULL;
}

int main()
{
	//每次开一个测试，也可自行写测试内容！
	//text1();
	//text2();
	text3();
	//text4();
	//text5();
	//text6();
	return 0;
}