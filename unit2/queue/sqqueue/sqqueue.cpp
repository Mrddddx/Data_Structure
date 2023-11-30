#include "sqqueue.h"
void InitQueue(SqQueue *&q)
{
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=q->rear=-1;
}

void DestroyQueue(SqQueue *&q)
{
    free(q);
}

bool QueueEmpty(SqQueue *&q)
{
    return q->rear==q->front; //判断首位是否相等
}

bool enQueue(SqQueue *&q,ElemType e)
{
    if(q->rear == MaxSize -1)
        return false;
    q->rear++;
    q->data[q->rear]=e;
    return true;
}

bool deQueue(SqQueue *&q,ElemType &e)
{
    if(q->rear==q->front) 
        return false;
    q->front++;
    e=q->data[q->front];
    return true;
}