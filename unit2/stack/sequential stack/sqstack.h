#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MaxSize 5000
typedef int ElemType;
typedef struct Node
{
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack *&s); //初始化

void DestroyStack(SqStack *&s);//销毁栈

bool Push(SqStack *&s,ElemType e);// 入栈

bool Pop(SqStack *&s,ElemType &e);//出栈

bool GetTop(SqStack *&s,ElemType &e); //取栈顶元素