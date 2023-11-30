#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
} LinkNode;
void CreateListF(LinkNode *&L,ElemType a[],int n); //头插法
void CreateListR(LinkNode *&L,ElemType a[],int n); //尾插法
void InitList(LinkNode *&L);//初始化单列表
bool ListEmpty(LinkNode *L);//为空返回1
int ListLength(LinkNode *L);//求链表长度
void DispList(LinkNode *L);//输出链表
bool GetElem(LinkNode *L,int i,ElemType &e); //得到第i个数，返回到e
bool ListInsert(LinkNode *L,int i,ElemType e); //在i位置上插入结点
bool ListDelete(LinkNode *&L,int i,ElemType &e);//删除第i个数并赋予e



void delmaxnode(LinkNode *&L);//删除最大元素
void sort(LinkNode *&L);//排序
/*-------------------------------------------------------------------------------------------*/
typedef struct DNode//双链表
{
	ElemType data;
	struct DNode *prior;
	struct DNode *next;
} DLinkNode;
void DCreateListF(DLinkNode *&L,ElemType a[],int n);//双链表的头插法
void DCreateListR(DLinkNode *&L,ElemType a[],int n);//双链表头插法
bool DListInsert(DLinkNode *&L,int i,ElemType e);//双链表插入
bool DListDelete(DLinkNode *&L,int i,ElemType &e);//双链表删除
void DispDList(DLinkNode *L);//输出双链表


void reverse(DLinkNode *&L);//转置
