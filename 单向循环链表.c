#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;//定义一个int型的ElemType

typedef struct node//定义一个node型结构体
{
    ElemType data;//int型的data，数据域
    struct node * next;//指向下一个结点的指针
}slink;//给node型结构体起别名slink

//建立单向循环表
slink * createlink(int n)//使用slink结构体创建createlink函数，参数为int型的n
{
    slink * head,*p,*s;//定义slink型的结点head,p,s
    int i;//定义int型的i
    if(n<1)//如果n小于1，返回空值
        return NULL;
    p=head=(slink*)malloc(sizeof(slink));//申请内存空间，将head指向p，作为存储头结点的位置
    for(i=1;i<=n;i++)//循环n次
    {
        s==(slink*)malloc(sizeof(slink));//为s申请内存空间，作为接续结点
        scanf("%d",&s->data);//输入数据
        p->next=s;//将p的next指针指向s，指针指向表示将s的地址赋给p的next
        p=s;//将p指向s，表示将s的地址赋给p
    }
    p->next=head;//将p的next指针指向head，表示将head的地址赋给p的next
    return head;//返回head,接续结点
}

//删除带头结点单向循环链表head中的第i个节点
int delete(slink *head,int i,ElemType *e)//使用slink结构体创建delete函数，参数为slink型的head，int型的i，ElemType型的e
{
    slink *p,*q;//定义slink型的结点p,q
    int j;//定义int型的j
    if(i<1)//如果i小于1，返回0
        return 0;
    p=head;//将head的地址赋给p
    j=0;//将j赋值为0
    while(p->next!=head&&j<i-1)//当p的next指针不指向head，且j小于i-1时，循环,减1因为要删除第i个节点，所以要找到第i-1个节点
    {
        p=p->next;//将p的next指针指向的地址赋给p
        j++;//j自增1
    }
    if(p->next==head)//如果p的next指针指向head
        return 0;//返回0
    q=p->next;//将p的next指针指向的地址赋给q
    p->next=q->next;//将q的next指针指向的地址赋给p的next
    *e=q->data;//将q的data赋给e
    free(q);//释放q的内存空间
    return 1;//返回1
}

//在带头节点单向循环链表head中的第i个节点之前插入一个值为x的结点
int insert(slink *head,int i,ElemType x)//使用slink结构体创建insert函数，参数为slink型的head，int型的i，ElemType型的x
{
    slink *p,*q;//定义slink型的结点p,q
    int j;//定义int型的j
    if(i<1)//如果i小于1，返回0
        return 0;
    p=head;//将head的地址赋给p
    j=0;//将j赋值为0
    while(p->next!=head&&j<i-1)//当p的next指针不指向head，且j小于i-1时，循环,减1因为要插入第i个节点，所以要找到第i-1个节点
    {
        p=p->next;//将p的next指针指向的地址赋给p
        j++;//j自增1
    }
    if((p->next!=head)||p->next==head&&j==i-1)//如果p的next指针指向head，或者p的next指针不指向head，且j等于i-1时
    {
        q=(slink*)malloc(sizeof(slink));//为q申请内存空间
        q->data=x;//将x赋给q的data
        q->next=p->next;//将p的next指针指向的地址赋给q的next
        p->next=q;//将q的地址赋给p的next
        return 1;//返回1
    }
    else
        return 0;//否则返回0
}

