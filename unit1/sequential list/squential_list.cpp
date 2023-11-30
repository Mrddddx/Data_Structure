#include "linear.h" //基本操作在这里
void CreateList(SqList *&L,ElemType a[],int n)
{
	int i=0,k=0;
	L=(SqList *)malloc(sizeof(SqList));  //分配内存空间
	while(i<n)
	{
		L->data[k]=a[i];
		k++;
		i++;
	}
	L->length = k;
}

void InitList(SqList *&L)
{
	L=(SqList *) malloc(sizeof(SqList));
	L->length = 0;
}

void DestoryList(SqList *&L)
{
	free(L);
}

int ListLength(SqList *L)
{
	return (L ->length);
}

void DispList(SqList *L)//在函数内输出
{
	for(int i=0;i<L->length;i++)
	{
		printf("%d ",L->data[i]);
	}
	printf("\n");
}

bool GetElem(SqList *L,int i,ElemType &e)//判断真假
{
	if(i<1||i>L->length)
		return false;
		e=L->data[i-1];//i表示的是第i个，下同
		return true;
}

int LocateElem(SqList *L,ElemType e)
{
	int i=0;
	while(i<L->length&&L->data[i]!=e)
		i++;
	if(i>=L->length)
		return 0;
	else 
		return i+1;
}

bool ListInsert(SqList *&L,int i,ElemType e)
{
	int j=0;
	if(i<1 || i>L->length+1 ||L->length == MaxSize)//注意！！！这里要防止爆空间,也要考虑length的变化
		return false;
	i--;
	for(j=L->length;j>i;j--)
		L->data[j]=L->data[j-1];
	L->data[i]=e;
	L->length++;
	return true;
}

bool ListDelete(SqList *&L,int i,ElemType &e)
{
	int j=0;
	if(i<1 || i>L->length+1 ||L->length == MaxSize)//注意！！！这里要防止爆空间,也要考虑length的变化
		return false;
	i--;
	e=L->data[i];
	for(j=i;j<L->length-1;j++)
		L->data[j]=L->data[j+1];
	L->length--;
	return true;
}