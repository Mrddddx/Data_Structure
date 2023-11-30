#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int KeyType; //关键字类型
typedef int InfoType;
typedef struct node //记录类型
{
    KeyType key;  //关键字项
    int bf;  //平衡因子
    InfoType data; //其他数据域
    struct node *lchild,*rchild; //左右儿子 
} BSTNode;

void LeftProcess(BSTNode *&p,int &taller) //左平衡旋转处理
{
    BSTNode *p1,*p2;
    if(p->bf==0) //左右子树等高，现在因为左子树增高而增高
    {
        p->bf=1;
        taller=1;
    }
    else if(p->bf==-1)//右子树高，现在等高
    {
        p->bf=0;
        taller=0;
    }
    else //左子树高，平衡处理
    {
        p1=p->lchild;
        if(p1->bf==1)
        {
            p->lchild=p1->rchild;
            p1->rchild=p;
            p->bf=0;
            p1->bf=0;
            p=p1;
        }
        else if(p1->bf==-1)
        {
            p2=p1->rchild;
            p1->rchild=p2->lchild;
            p2->lchild=p1;
            p->lchild=p2->rchild;
            p2->rchild=p;
            if(p2->bf==1)   
            {
                p->bf=p1->bf=0;
            }
            else if(p2->bf==1)   
            {
                p1->bf=0;
                p->bf=-1;
            }
            else 
            {
                p1->bf=1;
                p->bf=0;
            }
            p=p2;
            p->bf=0;
        }
        taller=0;
    }
}

void RightProcess(BSTNode *&p,int &taller)
{
    BSTNode *p1,*p2;
    if(p->bf==0)
    {
        p->bf=-1;
        taller=1;
    }
    else if(p->bf==1)
    {
        p->bf=0;
        taller=0;
    }
    else 
    {
        p1=p->rchild;
        if(p1->bf==-1)
        {
            p->rchild=p1->lchild;
            p1->lchild=p;
            p->bf=0;
            p1->bf=0;
            p=p1;
        }
        else if(p1->bf==1)
        {
            p2=p1->lchild;
            p1->lchild=p2->rchild;
            p2->rchild=p1;
            p->rchild=p2->lchild;
            p2->lchild=p;
            if(p2->bf==-1)
            {
                p->bf=p1->bf=0;
            }
            else if(p2->bf==-1)
            {
                p1->bf=0;
                p->bf=1;
            }
            else 
            {
                p1->bf=-1;
                p->bf=0;
            }
        }
        taller=0;
    }
}

int InsertAVL(BSTNode *&b,KeyType e,int &taller)
{
    if(b==NULL) //原为空树则加入节点
    {
        b=(BSTNode *)malloc(sizeof(BSTNode));
        b->key=e;
        b->lchild=b->rchild=NULL;
        b->bf=0;
        taller=1;
    }
    else 
    {
        if(e==b->key) //存在相同关键字,不再插入
        {
            taller=0;
            return  0;
        }
        if (e<b->key)
        {
            if(InsertAVL(b->lchild,e,taller)==0)
            return 0;
            if(taller==1)
            {
                LeftProcess(b,taller);
            }
        }
        else
        {
            if(InsertAVL(b->rchild,e,taller)==0)
            return 0;
            if(taller==1)
            {
                RightProcess(b,taller);
            }
        }
    }
    return 1;
}

void DispBTree(BSTNode *b)
{
    if(b!=NULL)
    {
        printf("%d",b->key);
        if(b->lchild!=NULL || b->rchild!=NULL)
        {
            printf("(");
            DispBTree(b->lchild);
            if(b->rchild!=NULL) printf(",");
            DispBTree(b->rchild);
            printf(")");
        }
    }
}
void LeftProcess1(BSTNode *&p,int &taller)  //在删除结点时进行左处理
{
    BSTNode *p1,*p2;
    if (p->bf==1)
    {
        p->bf=0;
        taller=1;
    }
    else if (p->bf==0)
    {
        p->bf=-1;
        taller=0;
    }
    else        //p->bf=-1
    {
        p1=p->rchild;
        if (p1->bf==0)          //需作RR调整
        {
            p->rchild=p1->lchild;
            p1->lchild=p;
            p1->bf=1;
            p->bf=-1;
            p=p1;
            taller=0;
        }
        else if (p1->bf==-1)    //需作RR调整
        {
            p->rchild=p1->lchild;
            p1->lchild=p;
            p->bf=p1->bf=0;
            p=p1;
            taller=1;
        }
        else                    //需作RL调整
        {
            p2=p1->lchild;
            p1->lchild=p2->rchild;
            p2->rchild=p1;
            p->rchild=p2->lchild;
            p2->lchild=p;
            if (p2->bf==0)
            {
                p->bf=0;
                p1->bf=0;
            }
            else if (p2->bf==-1)
            {
                p->bf=1;
                p1->bf=0;
            }
            else
            {
                p->bf=0;
                p1->bf=-1;
            }
            p2->bf=0;
            p=p2;
            taller=1;
        }
    }
}
void RightProcess1(BSTNode *&p,int &taller) //在删除结点时进行右处理
{
    BSTNode *p1,*p2;
    if (p->bf==-1)
    {
        p->bf=0;
        taller=-1;
    }
    else if (p->bf==0)
    {
        p->bf=1;
        taller=0;
    }
    else        //p->bf=1
    {
        p1=p->lchild;
        if (p1->bf==0)          //需作LL调整
        {
            p->lchild=p1->rchild;
            p1->rchild=p;
            p1->bf=-1;
            p->bf=1;
            p=p1;
            taller=0;
        }
        else if (p1->bf==1)     //需作LL调整
        {
            p->lchild=p1->rchild;
            p1->rchild=p;
            p->bf=p1->bf=0;
            p=p1;
            taller=1;
        }
        else                    //需作LR调整
        {
            p2=p1->rchild;
            p1->rchild=p2->lchild;
            p2->lchild=p1;
            p->lchild=p2->rchild;
            p2->rchild=p;
            if (p2->bf==0)
            {
                p->bf=0;
                p1->bf=0;
            }
            else if (p2->bf==1)
            {
                p->bf=-1;
                p1->bf=0;
            }
            else
            {
                p->bf=0;
                p1->bf=1;
            }
            p2->bf=0;
            p=p2;
            taller=1;
        }
    }
}

void Delete2(BSTNode *q,BSTNode *&r,int &taller)
//由DeleteAVL()调用,用于处理被删结点左右子树均不空的情况
{
    if (r->rchild==NULL)
    {
        q->key=r->key;
        q=r;
        r=r->lchild;
        free(q);
        taller=1;
    }
    else
    {
        Delete2(q,r->rchild,taller);
        if (taller==1)
            RightProcess1(r,taller);
    }
}int DeleteAVL(BSTNode *&p,KeyType x,int &taller) //在AVL树p中删除关键字为x的结点
{
    int k;
    BSTNode *q;
    if (p==NULL)
        return 0;
    else if (x<p->key)
    {
        k=DeleteAVL(p->lchild,x,taller);
        if (taller==1)
            LeftProcess1(p,taller);
        return k;
    }
    else if (x>p->key)
    {
        k=DeleteAVL(p->rchild,x,taller);
        if (taller==1)
            RightProcess1(p,taller);
        return k;
    }
    else            //找到了关键字为x的结点,由p指向它
    {
        q=p;
        if (p->rchild==NULL)        //被删结点右子树为空
        {
            p=p->lchild;
            free(q);
            taller=1;
        }
        else if (p->lchild==NULL)   //被删结点左子树为空
        {
            p=p->rchild;
            free(q);
            taller=1;
        }
        else                        //被删结点左右子树均不空
        {
            Delete2(q,q->lchild,taller);
            if (taller==1)
                LeftProcess1(q,taller);
            p=q;
        }
        return 1;
    }
}
int main()
{
    BSTNode *b=NULL;
    int a[10]={0,16,3,7,11,9,26,18,14,15};
    int d[4]={0,11,9,15};
    printf(" 创建一棵AVL树:\n");
    for(int i=i;i<10;i++)
    {
        printf("   第%d步,插入%d元素:",i,a[i]);
        InsertAVL(b,a[i],1);
        DispBTree(b);
        printf("\n");
    }
    printf("   AVL:");
    DispBTree(b);
    printf(" 删除结点:\n");
    for(int i=0;i<4;i++)
    {
        printf("   第%d步,删除%d元素:",i,d[i]);
        DeleteAVL(b,d[i],1);
        DispBTree(b);
        printf("\n");
    }
    printf("   AVL:");
    DispBTree(b);
    return 0;
}
