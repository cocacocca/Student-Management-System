#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;//定义一个int型的ElemType

typedef struct node//定义一个node型结构体
{
    ElemType data;//int型的data，数据域
    struct node * prior;//指向前一个节点的指针
    struct node * next;//指向后一个节点的指针
}dlink;//为node型结构体起别名dlink

//建立双向循环链表
dlink * createlink(int n)//定义createlink函数，参数为int型的n
{
    dlink * head,*p,*s;//定义三个dlink型的指针
    int i;//定义一个int型的变量
    if(n<1)//如果n小于1,返回NULL
        return NULL;
    p=head=(dlink*)malloc(sizeof(dlink));//创建一个头结点，p指向head
    for(i=1;i<=n;i++)//循环创建
    {
        s==(dlink*)malloc(sizeof(dlink));//创建一个接续节点
        scanf("%d",&s->data);//输入数据
        s->prior=p;//接续节点的前驱指向p,表示将p的地址赋给s的前驱
        p->next=s;//p的后继指向s,表示将s的地址赋给p的后继
        p=s;//p指向s,表示将s的地址赋给p,p的位置向后移动
    }
    p->next=head;//p的后继指向head,表示将head的地址赋给p的后继
    head->prior=p;//head的前驱指向p,表示将p的地址赋给head的前驱
    return head;//返回头结点
}

//删除带头结点双向循环链表head中的第i个节点
int delete(dlink *head,int i,ElemType *e)//定义delete函数，参数为dlink型的指针head，int型的i，ElemType型的指针e
{
    dlink *p,*q;//定义两个dlink型的指针
    int j;//定义一个int型的变量
    if(i<1)//如果i小于1，返回0
        return 0;
    p=head;//p指向head,表示将head的地址赋给p
    j=0;//j赋值为0
    while(p->next!=head&&j<i-1)
    {
        p=p->next;//表示将p的后继的地址赋给p
        j++;//j自加1
    }
    if(p->next==head)//如果p的后继指向head
        return 0;//返回0
    q=p->next;//p的后继的地址赋给q
    p->next=q->next;//p的后继指向q的后继,表示将q的后继的地址赋给p的后继
    q->next->prior=p;//q的后继的前驱指向p,表示将p的地址赋给q的后继的前驱
    *e=q->data;//将q的数据赋给e
    free(q);//释放q
    return 1;//返回1
}

//在带头节点双向循环链表head中的第i个节点之前插入一个值为x的结点
int insert(dlink *head,int i,ElemType x)//定义insert函数，参数为dlink型的指针head，int型的i，ElemType型的x
{
    dlink *p,*q;//定义两个dlink型的指针
    int j;//定义一个int型的变量j
    if(i<1)//如果i小于1，返回0
        return 0;
    p=head;//p指向head,表示将head的地址赋给p
    j=0;//j赋值为0
    while(p->next!=head&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if((p->next!=head)||p->next==head&&j==i-1)
    {
        q=(dlink*)malloc(sizeof(dlink));
        q->data=x;
        q->next=p->next;
        q->prior=p;
        p->next->prior=q;
        p->next=q;
        return 1;
    }
    else
        return 0;
}

//输出双向循环链表
void list(dlink * head)
{
    dlink * p;
    p=head->next;
    while(p!=head)
    {
        printf("%4d ",p->data);
        p=p->next;
    }
    printf("\n");
    p=head->prior;
    while(p!=head)
    {
        printf("%4d ",p->data);
        p=p->prior;
    }
    printf("\n");
}