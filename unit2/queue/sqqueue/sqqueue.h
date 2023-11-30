#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MaxSize 5000
typedef int ElemType;
typedef struct 
{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue *&q);//初始化队

void DestroyQueue(SqQueue *&q);//销毁队

bool QueueEmpty(SqQueue *&q);//判断对空

bool enQueue(SqQueue *&q,ElemType e);//入队

bool deQueue(SqQueue *&q,ElemType &e);//出队