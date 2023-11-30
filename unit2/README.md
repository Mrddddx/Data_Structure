# 栈和队列  
## 栈

>void InitStack(SqStack *&s); //初始化  
void DestroyStack(SqStack *&s);//销毁栈  
bool Push(SqStack *&s,ElemType e);// 入栈  
bool Pop(SqStack *&s,ElemType &e);//出栈  
bool GetTop(SqStack *&s,ElemType &e); //取栈顶元素  

## 队列
>void InitQueue(SqQueue *&q);//初始化队  
void DestroyQueue(SqQueue *&q);//销毁队  
bool QueueEmpty(SqQueue *&q);//判断对空    
bool enQueue(SqQueue *&q,ElemType e);//入队    
bool deQueue(SqQueue *&q,ElemType &e);//出队
