#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int ElemType;
typedef struct qnode
{
    ElemType data;
    struct qnode * next;
}DataNode;

typedef struct 
{
    DataNode *front;
    DataNode *rear;
}LinkQuNode;

void InitQueue(LinkQuNode *&q);//初始化

void DestroyQueue(LinkQuNode *&q);//销毁

bool QueueEmpty(LinkQuNode *q);//判断队空

bool enQueue(LinkQuNode *&q,ElemType e);//入队

bool deQueue(LinkQuNode *&q,ElemType &e);//出队