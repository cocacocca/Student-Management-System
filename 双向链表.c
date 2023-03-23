#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node * prior;
    struct node * next;
}dlink;

//建立双向链表
dlink * initlist(int n)
{
    dlink * head,*p,*s;
    int i;
    if(n<1)
        return NULL;
    p=head=(dlink*)malloc(sizeof(dlink));
    for(i=1;i<=n;i++)
    {
        s=(dlink*)malloc(sizeof(dlink));
        scanf("%d",&s->data);
        s->next=NULL;
        s->prior=p;
        p->next=s;
        p=s;
    }
    p->next=NULL;
    return head;
}

//删除双链表head中的第i个节点
int delete(dlink *head,int i,ElemType *e)
{
    dlink *p,*q;
    int j;
    if(i<1)
        return 0;
    p=head;
    j=0;
    while(p->next!=NULL&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(p->next==NULL)
        return 0;
    q=p->next;
    p->next=q->next;
    if(q->next!=NULL)
        q->next->prior=p;
    *e=q->data;
    free(q);
    return 1;
}

//在双链表head中的第i个节点之前插入一个值为x的结点
int insert(dlink * head,int i,ElemType x)
{
    dlink *p,*q;
    int j;
    if(i<1)
        return 0;
    p=head;
    j=0;
    while(p!=NULL&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(p==NULL)
        return 0;
    q=(dlink*)malloc(sizeof(dlink));
    q->data=x;
    q->next=p->next;
    q->prior=p;
    if(p->next!=NULL)
        p->next->prior=q;
    p->next=q;
    return 1;
}

//从两个方向输出双链表head中各结点的值
void list(dlink *head)
{
    dlink *p;
    p=head;
    while(p->next!=NULL)
    {
        printf("%4d ",p->next->data);
        p=p->next;
    }
    printf("\n");
    while(p!=NULL)
    {
        printf("%4d ",p->data);
        p=p->prior;
    }
    printf("\n");
}