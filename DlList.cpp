#include <iostream>
#include "DlList.h"
using namespace std;

int main()
{
	DLinkNode *DL;
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	//ͷ�巨����˫����
	CreateListF(DL, a, 10);
	//����˫����
	DispList(DL);

	//����Ԫ��
	int x;
	GetElem(DL, 4, x);
	cout << "���е�4��Ԫ���ǣ�" << x << endl;

	//����Ԫ��λ��
	int y = 8;
	cout << y << "�ڱ��е�λ���ǣ�" << LocateElem(DL, y) << endl;

	//ɾ��Ԫ��
	int z = 5;
	int e;
	ListDelete(DL, z, e);
	cout << "ɾ����Ԫ���ǣ�" << e << endl;

	//����Ԫ��
	DispList(DL);

	//����Ԫ��
	int i = 10;
	ListInsert(DL, 4, i);
	cout << "�ڱ�ĵ�4λ����" << i << endl;

	//����Ԫ��
	DispList(DL);

	//�������
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

	//����˫����
	DestroyList(DL);

	return 0;
}