# Introduction  
## 顺序表 
### 基本操作
> void InitList(SqList *&L);//初始化  
void DestoryList(SqList *&L);//销毁 
int ListLength(SqList *L);//返回长度  
void DispList(SqList *L);//输出顺序表  
bool GetElem(SqList *L,int i,ElemType &e);//取第i号元素  
int LocateElem(SqList *L,ElemType e);//定位元素e的位置  
bool ListInsert(SqList *&L,int i,ElemType e);//在i位置插入e  
bool ListDelete(SqList *&L,int i,ElemType &e);//删除第i号位置的元素并保留在e里面  
void CreateList(SqList *&L,ElemType a[],int n);//根据已有数组转换为顺序表
## 链表  
### 基本操作
#### 单链表
>void CreateListF(LinkNode *&L,ElemType a[],int n); //头插法  
void CreateListR(LinkNode *&L,ElemType a[],int n); //尾插法  
void InitList(LinkNode *&L);//初始化单列表  
bool ListEmpty(LinkNode *L);//为空返回1  
int ListLength(LinkNode *L);//求链表长度  
void DispList(LinkNode *L);//输出链表  
bool GetElem(LinkNode *L,int i,ElemType &e); //得到第i个数，返回到e  
bool ListInsert(LinkNode *L,int i,ElemType e); //在i位置上插入结点  
bool ListDelete(LinkNode *&L,int i,ElemType &e);//删除第i个数并赋予e  

#### 双链表
>void DCreateListF(DLinkNode *&L,ElemType a[],int n);//双链表的头插法  
void DCreateListR(DLinkNode *&L,ElemType a[],int n);//双链表头插法  
bool DListInsert(DLinkNode *&L,int i,ElemType e);//双链表插入  
bool DListDelete(DLinkNode *&L,int i,ElemType &e);//双链表删除  
void DispDList(DLinkNode *L);//输出双链表



