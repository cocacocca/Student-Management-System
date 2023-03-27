#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node * next;
}slink;

//创建链表
slink * CreateList(int n);

//链表转置
int inverse(slink * head);

//输出链表
void PrintList(slink * head , int InverseSuccess);

int main()
{
    slink * head;
    int InverseSuccess=0 ,InverseResult=0;//InverseSuccess用于传入转置值，InverseResult用于判断是否转置成功

    int n;
    printf("请输入链表长度:");
    scanf("%d",&n);
    printf("请输入链表元素并用空格隔开:");
    head=CreateList(n);

    PrintList(head,InverseSuccess);

    InverseResult=inverse(head);
    if(InverseResult==1)
    {
        printf("转置成功!\n");
        InverseSuccess=1;
    }
    else
    {
        printf("Inverse failed!\n");
        InverseSuccess=0;
    }

    PrintList(head,InverseSuccess);
    return 0;
}

// 定义三个指针，p指针用作移动指针，s指针用作创建新节点，head指针用作头指针
slink *CreateList(int n)
{
    slink *head, *p, *s;
    int i;
    if (n < 1)
    {
        return NULL;
    }
    p = head = (slink *)malloc(sizeof(slink));
    for (i = 0; i < n; i++)
    {
        s = (slink *)malloc(sizeof(slink));
        scanf("%d", &s->data);
        p->next = s;
        p = s;
    }
    p->next = NULL;
    return head;
}

int inverse(slink *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 0;
    }
    // 定义三个指针，cur(current)指向当前节点，pre(previous)指向当前节点的前一个节点，LatCur(latter node of current)指向当前节点的后一个节点
    slink *Cur, *Pre, *LatCur;
    Cur = NULL;
    Pre = NULL;
    LatCur = head->next; // LatCur指向头结点的下一个节点
    while (LatCur != NULL)
    {
        Pre = LatCur;          // Pre指向LatCur
        LatCur = LatCur->next; // LatCur指向下一个节点地址
        Pre->next = Cur;       // Pre的下一个节点地址指向Cur
        Cur = Pre;             // Cur指向Pre
    }
    head->next = Pre; // 头结点的下一个节点地址指向Pre

    return 1; // 转置成,返回值给InverseResult
}

// 添加转置条件，判断是否转置成功，转置成功则输出转置后语句，否则输出转置前语句
void PrintList(slink *head, int InverseSuccess)
{
    slink *p;
    p = head->next;
    if (InverseSuccess == 0)
    {
        printf("输出原链表:");
    }
    else
    {
        printf("输出转置后链表:");
    }
    // 遍历链表
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next; // 指针后移
    }
    printf("\n");
}
