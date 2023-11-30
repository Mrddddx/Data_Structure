#include "sqstack.h"
void InitStack(SqStack *&s) //初始化
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}

void DestroyStack(SqStack *&s)
{
	free(s);
}

bool Push(SqStack *&s,ElemType e)// 入栈
{
	if(s->top==MaxSize -1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}

bool Pop(SqStack *&s,ElemType &e)//出栈
{
	if(s->top == -1)
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(SqStack *&s,ElemType &e) //取栈顶元素
{
	if(s->top ==-1) //不可能爆满但是可能栈空
		return false;
	e=s->data[s->top];
	return true;
}
