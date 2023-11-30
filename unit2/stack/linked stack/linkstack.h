#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkSNode;

void InitStack(LinkSNode *&s) ;//初始化

void DestroyStack(LinkSNode *&s) ;//销毁栈

bool StackEmpty(LinkSNode *s);//判空

bool Push(LinkSNode *&s,ElemType x);//入栈

bool Pop(LinkSNode *&s,ElemType &x);//出栈

bool GetTop(LinkSNode *&s,ElemType &e);//取栈顶