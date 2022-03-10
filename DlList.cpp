#include <iostream>
#include "DlList.h"
using namespace std;

int main()
{
	DLinkNode *DL;
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	//头插法建立双链表
	CreateListF(DL, a, 10);
	//遍历双链表
	DispList(DL);

	//查找元素
	int x;
	GetElem(DL, 4, x);
	cout << "表中第4个元素是：" << x << endl;

	//查找元素位置
	int y = 8;
	cout << y << "在表中的位置是：" << LocateElem(DL, y) << endl;

	//删除元素
	int z = 5;
	int e;
	ListDelete(DL, z, e);
	cout << "删除的元素是：" << e << endl;

	//遍历元素
	DispList(DL);

	//插入元素
	int i = 10;
	ListInsert(DL, 4, i);
	cout << "在表的第4位插入" << i << endl;

	//遍历元素
	DispList(DL);

	//逆向遍历
	DLinkNode* p = DL;
	while (p->next != NULL)
	{
		p = p->next;
	}
	while (p->prior != NULL)
	{
		cout << p->data << " ";
		p = p->prior;
	}

	//销毁双链表
	DestroyList(DL);

	return 0;
}