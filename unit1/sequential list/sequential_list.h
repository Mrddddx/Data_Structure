//
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50

typedef int  ElemType;//这里默认数据元素为int
typedef struct
{
	ElemType data[50];//数据元素
	int length;//长度
} SqList; //顺序表类型

//以下为基本操作
void InitList(SqList *&L);//初始化
void DestoryList(SqList *&L);//销毁
int ListLength(SqList *L);//返回长度
void DispList(SqList *L);//输出顺序表
bool GetElem(SqList *L,int i,ElemType &e);//取第i号元素
int LocateElem(SqList *L,ElemType e);//定位元素e的位置
bool ListInsert(SqList *&L,int i,ElemType e);//在i位置插入e
bool ListDelete(SqList *&L,int i,ElemType &e);//删除第i号位置的元素并保留在e里面
void CreateList(SqList *&L,ElemType a[],int n);//根据已有数组转换为顺序表

//以下为附加操作
