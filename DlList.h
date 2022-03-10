#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct Node
{
	ElemType data;                  //���Ԫ��ֵ
	struct Node* prior;				//ָ��ǰ�����
	struct Node* next;				//ָ���̽��
} DLinkNode;						//˫����Ľڵ�����

void InitList(DLinkNode*& DL);                        //��ʼ��˫����
void DestroyList(DLinkNode*& DL);                     //����˫����
bool ListEmpty(DLinkNode* DL);					     //�ж��Ƿ�Ϊ�ձ�
int ListLength(DLinkNode* DL);                        //��˫����ĳ���
void DispList(DLinkNode* DL);                         //���˫����
bool GetElem(DLinkNode* DL, int i, ElemType& e);      //�õ���i��Ԫ��
int LocateElem(DLinkNode* DL, ElemType e);            //��e�ڱ��е����
bool ListInsert(DLinkNode*& DL, int i, ElemType e);   //��e������е�i��λ��
bool ListDelete(DLinkNode*& DL, int i, ElemType& e);  //ɾ�����е�i��Ԫ��
void CreateListF(DLinkNode*& DL, ElemType a[], int n);//ͷ�巨
void CreateListR(DLinkNode*& DL, ElemType a[], int n);//β�巨

void InitList(DLinkNode*& DL)                        //��ʼ��˫����
{
	DL = (DLinkNode*)malloc(sizeof(DLinkNode));
	DL->next = NULL;
	DL->prior = NULL;
}

void DestroyList(DLinkNode*& DL)                     //����˫����
{
	DLinkNode* p = DL->next, * pre = DL;        //preָ����p��ǰ�����
	while (p != NULL)						  //ɨ��˫����DL
	{
		free(pre);							  //�ͷ�pre���
		pre = p;							  //pre,pͬ������һ�����
		p = pre->next;
	}
	free(pre);								  //ѭ������ʱ��pΪNULL��preָ��β��㣬�ͷ���
}

bool ListEmpty(DLinkNode* DL)					     //�ж��Ƿ�Ϊ�ձ�
{
	return(DL->next == NULL);
}

int ListLength(DLinkNode* DL)                        //��˫����ĳ���
{
	int n = 0;
	DLinkNode* p = DL;                       //pָ��ͷ��㣬n��Ϊ0(��ͷ�������Ϊ0)
	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

void DispList(DLinkNode* DL)                         //���˫����
{
	DLinkNode* p = DL->next;                 //pָ���׽��
	while (p != NULL)						 //p��ΪNULLʱ�����p����data��
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

bool GetElem(DLinkNode* DL, int i, ElemType& e)      //�õ���i��Ԫ��
{
	int j = 0;
	DLinkNode* p = DL;                       //pָ��ͷ��㣬j��Ϊ0(��ͷ�������Ϊ1)
	if (i <= 0)								 //iֵ����ȷ������false
		return false;
	while (j < i && p != NULL)				 //�ҵ���i�����
	{
		j++;
		p = p->next;
	}
	if (p == NULL)                           //�����ڵ�i����㣬����false
		return false;
	else									 //���ڵ�i����㣬����true
	{
		e = p->data;
		return true;
	}
}

int LocateElem(DLinkNode* DL, ElemType e)            //��e�ڱ��е����
{
	int i = 1;
	DLinkNode* p = DL->next;                 //pָ���׽�㣬i��Ϊ1(���׽������Ϊ1)
	while (p != NULL && p->data != e)        //����dataֵΪe�Ľ�㣬�����Ϊi
	{
		i++;
		p = p->next;
	}
	if (p == NULL)							 //������ֵΪe�Ľ�㣬����0
		return 0;
	else									 //����ֵΪ1�Ľ�㣬����i
		return i;
}

bool ListInsert(DLinkNode*& DL, int i, ElemType e)   //��e������е�i��λ��
{
	int j = 0;
	DLinkNode* p = DL, * s;					 //pָ��ͷ��㣬j����Ϊ0
	if (i <= 0)								 //iֵ����ȷ������false
		return false;
	while (j < i - 1 && p != NULL)			 //���ҵ�i-1�����
	{
		j++;
		p = p->next;
	}
	if (p == NULL)							 //�����ڵ�i-1����㣬����false
		return false;
	else									 //�ҵ���i-1�����p
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = e;						 //�����½��s
		s->next = p->next;					 //��p���֮�����s���
		if (p->next != NULL)					 //��p�����ں�̽�㣬�޸���ǰ��ָ��
			p->next->prior = s;
		s->prior = p;
		p->next = s;
		return true;
	}
}

bool ListDelete(DLinkNode*& DL, int i, ElemType& e)  //ɾ�����е�i��Ԫ��
{
	int j = 0;
	DLinkNode* p = DL, * s;					 //pָ��ͷ��㣬j����Ϊ0
	if (i <= 0)								 //iֵ���󣬷���false
		return false;
	while (p != NULL && j < i - 1)			 //���ҵ�i-1�����
	{
		j++;
		p = p->next;
	}
	if (p == NULL)							 //�����ڵ�i-1����㣬����false
		return false;
	else									 //�ҵ���i-1�����
	{
		s = p->next;                         //sָ���i�����
		if (s == NULL)						 //�������ڵ�i����㣬����false
			return false;
		e = s->data;						 //����ɾ����data����
		p->next = s->next;					 //��˫������ɾ�����s
		if (s->next != NULL)			     //��s�����ں�̽��,�޸�ǰ��ָ��
			s->next->prior = p;
		free(s);							 //�ͷ�s���
		return true;
	}
}

void CreateListF(DLinkNode*& DL, ElemType a[], int n)//ͷ�巨
//�ɺ���n��Ԫ�ص�����a������ͷ����˫����L
{
	DLinkNode* s;
	DL = (DLinkNode*)malloc(sizeof(DLinkNode));   //����ͷ���
	DL->prior = DL->next = NULL;				  //ǰ��ָ������ΪNULL
	for (int i = 0; i < n; i++)					  //ѭ���������ݽ��
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];							  //�������ݽ��s
		s->next = DL->next;						  //��s�����뵽ͷ���֮��
		if (DL->next != NULL)					  //��DL�������ݽ�㣬�޸�DL->next��ǰ��ָ��
			DL->next->prior = s;
		DL->next = s;
		s->prior = DL;
	}
}

void CreateListR(DLinkNode*& DL, ElemType a[], int n)//β�巨
//�к���n��Ԫ�ص�����a������ͷ����˫����DL
{
	DLinkNode* s, * r;
	DL = (DLinkNode*)malloc(sizeof(DLinkNode));   //����ͷ���
	r = DL;										  //rʼ��ָ��β��㣬��ʼʱָ��ͷ���
	for (int i = 0; i < n; i++)					  //ѭ��������������
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];							  //�������ݽ��s
		r->next = s;
		s->prior = r;							  //��s��������r���֮��
		r = s;									  //rָ��β���
	}
	r->next = NULL;								  //β����next����ΪNULL
}