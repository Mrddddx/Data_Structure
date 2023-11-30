#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkSNode;

void InitStack(LinkSNode *&s) {
    s=(LinkSNode *)malloc(sizeof(LinkSNode));
    s ->next= NULL;
}

void DestroyStack(LinkSNode *&s) {
    LinkSNode *pre=s,*p=s->next;
    while (p != NULL) 
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

bool StackEmpty(LinkSNode *s) {
    return s->next == NULL;
}

bool Push(LinkSNode *&s,ElemType x) {
    LinkSNode *p=(LinkSNode *)malloc(sizeof(LinkSNode));
    p->data = x;
    p->next = s->next;
    s->next = p;
    return true;
}

bool Pop(LinkSNode *&s,ElemType &x) {
    if (StackEmpty(s)) {
        return false;
    }
    LinkSNode *p = s->next;
    x = p->data;
    s->next = p->next;
    free(p);
    return true;
}

bool GetTop(LinkSNode *&s,ElemType &e)
{
    if(s->next == NULL)
        return false;
    e=s->next->data;
    return true;
}