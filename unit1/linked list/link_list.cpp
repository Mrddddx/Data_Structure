#include "link_list.h"
void CreateListF(LinkNode *&L,ElemType a[],int n) //头插法
{
	LinkNode *s;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->next=NULL;
	for(int i=0;i<n;i++)
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=a[i];
		s->next=L->next;
		L->next=s;		
	}
}

void CreateListR(LinkNode *&L,ElemType a[],int n) //尾插法
{
	LinkNode *s , *r;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	r=L;
	for(int i=0;i<n;i++)
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
}

void InitList(LinkNode *&L) //初始化单列表
{
	L=(LinkNode *)malloc (sizeof(LinkNode));
	L->next=NULL;
}

bool ListEmpty(LinkNode *L) //为空返回1
{
	return (L->next==NULL);
}

int ListLength(LinkNode *L)//求链表长度
{
	int ans=0;
	LinkNode *p=L;
	while(p->next != NULL)
	{
		ans++;
		p=p->next;
	}
	return ans;
}

void DispList(LinkNode *L) //输出链表
{
	LinkNode *p=L;
	while(p->next != NULL)
	{
		printf("%d ",p->next->data);
		p=p->next;
	}
	printf("\n");
}

bool GetElem(LinkNode *L,int i,ElemType &e) //得到第i个数，返回到e
{
	int j=0;
	LinkNode *p=L;
	if(i<1) return false;
	while(j<i && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p == NULL) return false;
	e=p->data;
	return true;
}

int LocateElem(LinkNode *L,ElemType e) //查找位置
{
	int j=0;
	LinkNode *p=L;
	while(p!=NULL && p->data != e)
	{j++; p=p->next;}
	if(p == NULL ) return 0; //没找到返回第一个位置
	return j;
}

bool ListInsert(LinkNode *L,int i,ElemType e) //在i位置上插入结点
{
	int j=0;
	LinkNode *s,*p=L;
	while(j<i-1 && p != NULL)//注意j<1-1
	{
		j++;
		p=p->next;
	}
	if (p == NULL) return false;
	s=(LinkNode *)malloc (sizeof(LinkNode));
	s->data = e;
	s->next = p->next;
	p->next =s;
	return true;
}

bool ListDelete(LinkNode *&L,int i,ElemType &e) //删除第i个数并赋予e
{
	int j=0;
	LinkNode *p=L,*s;
	while(j < i-1&& p!=NULL)//注意j<1-1
	{
		p=p->next;
		j++;
	}
	if (p==NULL) return false;
	s=p->next;
	if(s==NULL)
		return false;//不存在第i个
	e=s->data;
	p->next=s->next;
	free(s);
	return true;
}
//addition*********************************************************************
void delmaxnode(LinkNode *&L)//删除最大元素
{
	LinkNode *p=L->next,*pre=L,*maxp=p,*maxpre=pre;
	while(p != NULL)
	{
		if(maxp->data < p->data)
		{
			maxp=p;
			maxpre=pre;
		}
		pre=p;
		p=p->next;
	
	}
	maxpre->next = maxp ->next;
	free(maxp);
}

void sort(LinkNode *&L)//排序
{
	LinkNode *p,*pre,*q;
	p=L->next->next;
	L->next->next=NULL;
	while(p != NULL)
	{
		q=p -> next;
		pre = L;
		while(pre -> next != NULL && pre->next->data<p->data) //从小到大
			pre=pre->next;
		p->next=pre->next;
		pre ->next=p;
		p=q;
	}
}




/*－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－双列表－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－*/
void DCreateListF(DLinkNode *&L,ElemType a[],int n) //双链表的头插法
{
	DLinkNode *s;
	L=(DLinkNode *)malloc (sizeof(DLinkNode ));
	L->prior=L->prior=NULL;
	for(int i=0;i<n;i++)
	{
		s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=a[i];
		s->next=L->next;
		if(L->next !=NULL)
			L->next->prior=s;
		s->prior=L;
		L->next=s;
	}
}
void DCreateListR(DLinkNode *&L,ElemType a[],int n)//双链表的尾插法
{
	DLinkNode *s,*r;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));
	L->next=L->prior=NULL;
	r=L;
	for(int i=0;i<n;i++)
	{
		s=(DLinkNode*)malloc(sizeof(DLinkNode));
		s->data=a[i];
		s->prior=r;
		r->next=s;
		r=s;
	}
	r->next=NULL;
}

bool DListInsert(DLinkNode *&L,int i,ElemType e)//双链表插入
{
	int j=0;
	DLinkNode *s,*p=L;
	if(i<=0) return false;
	while(j<i-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL) return false;
	s=(DLinkNode *)malloc(sizeof(DLinkNode));
	s->data=e;
	s->next=p->next;
	if (p->next != NULL)
		p->next->prior=s;
	p->next=s;
	s->prior=p;
	return true;	
}

bool DListDelete(DLinkNode *&L,int i,ElemType &e)//双链表删除
{
	int j=0;
	DLinkNode *s,*p=L;
	if(i<=0) return false;
	while(j<i-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL) return false;
	s=p->next;
	if(s==NULL) return false;
	e=s->data;
	p->next=s->next;
	if (s->next != NULL)
		s->next->prior=p;
		free(s);
	return true;
}
void DispDList(DLinkNode *L)//输出双链表
{
	DLinkNode *p=L;
	while(p->next!= NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

//addition *******************************
void reverse(DLinkNode *&L)//转置
{
	DLinkNode * p=L->next,*q;
	L->next = NULL;
	while(p!=NULL)
	{
		q=p->next;
		p->next = L->next;
		if (p ->next !=NULL)
			L->next->prior=p;
		L->next=p;
		p->prior=L;
		p=q;
	}
}

/*－－－－－－－－－－－－－循环列表－－－－－－－－－－－－－－－－－－－*/
//尾结点->next=L