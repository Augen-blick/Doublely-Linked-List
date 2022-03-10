#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct Node
{
	ElemType data;                  //存放元素值
	struct Node* prior;				//指向前驱结点
	struct Node* next;				//指向后继结点
} DLinkNode;						//双链表的节点类型

void InitList(DLinkNode*& DL);                        //初始化双链表
void DestroyList(DLinkNode*& DL);                     //销毁双链表
bool ListEmpty(DLinkNode* DL);					     //判断是否为空表
int ListLength(DLinkNode* DL);                        //求双链表的长度
void DispList(DLinkNode* DL);                         //输出双链表
bool GetElem(DLinkNode* DL, int i, ElemType& e);      //得到第i个元素
int LocateElem(DLinkNode* DL, ElemType e);            //求e在表中的序号
bool ListInsert(DLinkNode*& DL, int i, ElemType e);   //将e插入表中第i个位置
bool ListDelete(DLinkNode*& DL, int i, ElemType& e);  //删除表中第i个元素
void CreateListF(DLinkNode*& DL, ElemType a[], int n);//头插法
void CreateListR(DLinkNode*& DL, ElemType a[], int n);//尾插法

void InitList(DLinkNode*& DL)                        //初始化双链表
{
	DL = (DLinkNode*)malloc(sizeof(DLinkNode));
	DL->next = NULL;
	DL->prior = NULL;
}

void DestroyList(DLinkNode*& DL)                     //销毁双链表
{
	DLinkNode* p = DL->next, * pre = DL;        //pre指向结点p的前驱结点
	while (p != NULL)						  //扫描双链表DL
	{
		free(pre);							  //释放pre结点
		pre = p;							  //pre,p同步后移一个结点
		p = pre->next;
	}
	free(pre);								  //循环结束时，p为NULL，pre指向尾结点，释放它
}

bool ListEmpty(DLinkNode* DL)					     //判断是否为空表
{
	return(DL->next == NULL);
}

int ListLength(DLinkNode* DL)                        //求双链表的长度
{
	int n = 0;
	DLinkNode* p = DL;                       //p指向头结点，n置为0(即头结点的序号为0)
	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

void DispList(DLinkNode* DL)                         //输出双链表
{
	DLinkNode* p = DL->next;                 //p指向首结点
	while (p != NULL)						 //p不为NULL时，输出p结点的data域
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

bool GetElem(DLinkNode* DL, int i, ElemType& e)      //得到第i个元素
{
	int j = 0;
	DLinkNode* p = DL;                       //p指向头结点，j置为0(即头结点的序号为1)
	if (i <= 0)								 //i值不正确，返回false
		return false;
	while (j < i && p != NULL)				 //找到第i个结点
	{
		j++;
		p = p->next;
	}
	if (p == NULL)                           //不存在第i个结点，返回false
		return false;
	else									 //存在第i个结点，返回true
	{
		e = p->data;
		return true;
	}
}

int LocateElem(DLinkNode* DL, ElemType e)            //求e在表中的序号
{
	int i = 1;
	DLinkNode* p = DL->next;                 //p指向首结点，i置为1(即首结点的序号为1)
	while (p != NULL && p->data != e)        //查找data值为e的结点，其序号为i
	{
		i++;
		p = p->next;
	}
	if (p == NULL)							 //不存在值为e的结点，返回0
		return 0;
	else									 //存在值为1的结点，返回i
		return i;
}

bool ListInsert(DLinkNode*& DL, int i, ElemType e)   //将e插入表中第i个位置
{
	int j = 0;
	DLinkNode* p = DL, * s;					 //p指向头结点，j设置为0
	if (i <= 0)								 //i值不正确，返回false
		return false;
	while (j < i - 1 && p != NULL)			 //查找第i-1个结点
	{
		j++;
		p = p->next;
	}
	if (p == NULL)							 //不存在第i-1个结点，返回false
		return false;
	else									 //找到第i-1个结点p
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = e;						 //创建新结点s
		s->next = p->next;					 //在p结点之后插入s结点
		if (p->next != NULL)					 //若p结点存在后继结点，修改其前驱指针
			p->next->prior = s;
		s->prior = p;
		p->next = s;
		return true;
	}
}

bool ListDelete(DLinkNode*& DL, int i, ElemType& e)  //删除表中第i个元素
{
	int j = 0;
	DLinkNode* p = DL, * s;					 //p指向头结点，j设置为0
	if (i <= 0)								 //i值错误，返回false
		return false;
	while (p != NULL && j < i - 1)			 //查找第i-1个结点
	{
		j++;
		p = p->next;
	}
	if (p == NULL)							 //不存在第i-1个结点，返回false
		return false;
	else									 //找到第i-1个结点
	{
		s = p->next;                         //s指向第i个结点
		if (s == NULL)						 //当不存在第i个结点，返回false
			return false;
		e = s->data;						 //记下删除的data数据
		p->next = s->next;					 //从双链表中删除结点s
		if (s->next != NULL)			     //若s结点存在后继结点,修改前驱指针
			s->next->prior = p;
		free(s);							 //释放s结点
		return true;
	}
}

void CreateListF(DLinkNode*& DL, ElemType a[], int n)//头插法
//由含有n个元素的数组a创建带头结点的双链表L
{
	DLinkNode* s;
	DL = (DLinkNode*)malloc(sizeof(DLinkNode));   //创建头结点
	DL->prior = DL->next = NULL;				  //前后指针域置为NULL
	for (int i = 0; i < n; i++)					  //循环建立数据结点
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];							  //创建数据结点s
		s->next = DL->next;						  //将s结点插入到头结点之后
		if (DL->next != NULL)					  //若DL存在数据结点，修改DL->next的前驱指针
			DL->next->prior = s;
		DL->next = s;
		s->prior = DL;
	}
}

void CreateListR(DLinkNode*& DL, ElemType a[], int n)//尾插法
//有含有n个元素的数组a创建带头结点的双链表DL
{
	DLinkNode* s, * r;
	DL = (DLinkNode*)malloc(sizeof(DLinkNode));   //创建头结点
	r = DL;										  //r始终指向尾结点，开始时指向头结点
	for (int i = 0; i < n; i++)					  //循环建立数据链表
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];							  //创建数据结点s
		r->next = s;
		s->prior = r;							  //将s结点插入在r结点之后
		r = s;									  //r指向尾结点
	}
	r->next = NULL;								  //尾结点的next域置为NULL
}