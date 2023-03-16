#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<errno.h>
#include<conio.h>

//定义宏常量
#define MAX_ID 30
#define MAX_PWD 30
#define MAIL 30

//创建用户的结构体
typedef struct Users
{
    char id[MAX_ID];
    char pwd[MAX_PWD];
    char mail[MAIL];
} Users;

//创建学生成绩的结构体
struct score
{
    int Total;
};

//创建学生生日的结构体
struct date
{
    int year;
    int month;
    int day;
};

//创建学生信息的结构体
struct student
{
    int Student_ID;
    char name[30];
    int age;
    char sex;
    int class;
    struct date birthday;
    struct score score;
};
typedef struct student Stu;

//定义结点结构体
typedef struct Node
{
    Stu data;
    struct Node *next;
} Node;


//声明函数

//欢迎界面
void welcome();

//打印菜单
void menu();

//用户注册
void Register();

//登录
void Login();

//找回密码
void Reback();

//密码输入（含掩盖功能）
void Getpwd(char *pwd);

//添加学生信息
void inputStudent(Stu * stu);

//删除学生信息
void deleteStudent(Node * head);

//修改学生信息
void modifyStudent(Node * head);

//查询学生信息
void searchStudent(Node * head);

//统计学生人数
void countStudent(Node * head);

//保存学生数据
void saveStudent(Node * head);

//打印学生数据
void printStudent(Node * head);


int main()
{
    char input;
    do
    {
        menu();
        setbuf(stdin, NULL);
        input = getchar();
        switch(input)
        {
        case '1':
            Register();
            break;
        case '2':
            Login();
            break;
        case '3':
            Reback();
            break;
        case '0':
            printf("退出系统\n");
            break;
        default:
            printf("输入错误，请重新输入\n");
            break;
        }
    }while(input != '2'&&'3'&&'0');

    //创建链表头结点
    Node *head = malloc(sizeof(Node));
    head->next = NULL;

    while(1)
    {
        welcome();
        int temp = 0;
        scanf("%d", &temp);
        switch (temp)
        {
        case 1:
            printf("选择添加学生信息\n");
            inputStudent(head);
            break;
        case 2:
            printf("选择删除学生信息\n");
            deleteStudent(head);
            break;
        case 3:
            printf("选择修改学生信息\n");
            modifyStudent(head);
            break;
        case 4:
            printf("选择查询学生信息\n");
            searchStudent(head);
            break;
        case 5:
            printf("显示所有学生信息\n");
            printStudent(head);
            break;
        case 6:
            printf("统计学生人数\n");
            countStudent(head);
            break;
        case 7:
            printf("退出系统\n");
            system("cls");
            printf("Bye Bye!\n");
            exit(0);
            break;
        }
    }
}

//打印菜单
void menu()
{
    printf("************************************************************\n");
    printf("\n");
    printf("\n");
    printf("                    欢迎来到学生管理系统                \n");
    printf("\n");
    printf("\n");
    printf("************************************************************\n");
    printf("\n");
    printf("\n");
    printf("1、用户注册\n");
    printf("2、用户登录\n");
    printf("3、找回密码\n");
    printf("0、退出系统\n");
    printf("请输入你的选择：");
}

//注册函数
void Register()
{
    Users i,o;//创建用户结构体临时变量，i用于用户输入，o用于文件读取输出，与i比较

    char tmp[20] = "";

    printf("欢迎来到注册界面\n");

    FILE *pf = fopen("C:/Users/91591/Desktop/C/Student Management System/user.dat", "wb+"); // 打开文件，文件不存在则创建
    fread(&o,sizeof(Users),1,pf);//读取文件中的数据
    if(!pf)//先验证行不行
    {
        printf("文件打开失败\n");
        printf("失败原因：%s\n",strerror(errno));//errno返回错误码
        return ;
    }
    Sleep(800);

    printf("请输入你的用户名>>");
    scanf("%s",i.id);
    while(1)
    {
        if(strcmp(i.id,o.id))//判断存储用户名是否重复
        {
            if(!feof(pf))//判断是否到文件末尾
            {
                fread(&o,sizeof(Users),1,pf);//读取文件中的数据
            }
            else//确认没有重复
            {
                break;
            }
        }
        else
        {
            printf("用户名重复，请重新输入\n");
            Sleep(800);
            fclose(pf);
            pf=NULL;//野指置空
            return;
        }
    }
    printf("请输入你的邮箱>>");
    scanf("%s",i.mail);
    printf("请输入你的密码>>");
    Getpwd(i.pwd);
    printf("请再次输入你的密码>>");
    Getpwd(tmp);
    do
    {
        if(!strcmp(i.pwd,tmp))//判断两次输入的密码是否一致
        {
            pf = fopen("C:/Users/91591/Desktop/C/Student Management System/user.dat", "ab");
            fwrite(&i, sizeof(Users), 1, pf);
            printf("\n账号注册成功,请登录!\n");
            Sleep(500);
            fclose(pf);
            pf = NULL;
            return;
        }
        else
        {
            printf("\n两次密码不匹配!请重新输入>>");
            Getpwd(i.pwd);
            printf("\n请再次确认>>");
            Getpwd(tmp);
        }
    }while(1);
}

//登录函数
void Login()
{
    Users i,o;//创建用户结构体临时变量，i用于用户输入，o用于文件读取输出，与i比较

    FILE *pf = fopen("C:/Users/91591/Desktop/C/Student Management System/user.dat", "rb+"); // 打开文件
    if(!pf)//先验证行不行
    {
        printf("文件打开失败\n");
        printf("失败原因：%s\n",strerror(errno));//errno返回错误码
        return ;
    }
    printf("欢迎来到登录界面\n");
    Sleep(1000);

    fread(&o,sizeof(Users),1,pf);//读取文件中的数据,预备比较

    printf("请输入你的用户名>>");
    scanf("%s",i.id);

    while(1)
    {
        if(!strcmp(i.id,o.id))
        {
            break;
        }
        else
        {
            if(!feof(pf))//判断是否到文件末尾
            {
                fread(&o,sizeof(Users),1,pf);//读取文件中的数据
            }
            else
            {
                printf("用户名不存在，请重新输入\n");
                Sleep(800);
                fclose(pf);
                pf=NULL;//野指置空
                return;
            }
        }
    }
    do
    {
        printf("请输入你的密码>>");
        Getpwd(i.pwd);
        if(!strcmp(i.pwd,o.pwd))
        {
            printf("登录成功\n");
            Sleep(800);
            fclose(pf);
            pf=NULL;//野指置空
            return;
        }
        else
        {
            printf("密码错误，请重新输入\n");
            Sleep(800);
        }
    }while(strcmp(i.pwd,o.pwd));

}

//找回密码函数
void Reback()
{
    char tmp[20] = "";
    Users i,o;//创建用户结构体临时变量，i用于用户输入，o用于文件读取输出，与i比较

    FILE *pf = fopen("C:/Users/91591/Desktop/C/Student Management System/user.dat", "rb+"); // 打开文件

    if(pf == NULL)//先验证行不行
    {
        printf("文件打开失败\n");
        printf("失败原因：%s\n",strerror(errno));//errno返回错误码
        return ;
    }

    fread(&o,sizeof(Users),1,pf);//读取文件中的数据,预备比较

    printf("欢迎来到找回密码界面\n");
    printf("请输入你的用户名>>");
    Sleep(800);
    scanf("%s",i.id);

    while(1)
    {
        if(!strcmp(i.id,o.id))
        {
            break;
        }
        else
        {
            if(!feof(pf))//判断是否到文件末尾
            {
                fread(&o,sizeof(Users),1,pf);//读取文件中的数据
            }
            else
            {
                printf("用户名不存在，请重新输入\n");
                Sleep(800);
                fclose(pf);
                pf=NULL;//野指置空
                return;
            }
        }
    }

    do
    {
        printf("请输入你的邮箱>>");
        scanf("%s",i.mail);
        if(!strcmp(i.mail,o.mail))
        {
            printf("请输入你的新密码>>");
            Getpwd(i.pwd);
            printf("请再次输入你的新密码>>");
            Getpwd(tmp);
            do
            {
                if(strcmp(i.pwd,tmp))//判断两次输入的密码是否一致
                {
                    fseek(pf, -((int)(sizeof(Users) - MAX_ID)),SEEK_CUR);//将文件指针移动到上一次读取的位置
                    fwrite(&i, sizeof(Users), 1, pf);//将新密码写入文件
                    printf("\n密码修改成功,请登录!\n");
                    Sleep(500);
                    fclose(pf);
                    pf = NULL;
                    return;
                }
                else
                {
                    printf("\n两次密码不匹配!请重新输入>>");
                    Getpwd(i.pwd);
                    printf("\n请再次确认>>");
                    Getpwd(tmp);
                }
            }while(1);
        }
        else
        {
            printf("邮箱错误，请重新输入\n");
            Sleep(800);
        }
    }while(1);
}

//输入密码函数
void Getpwd(char * pwd)
{
    char ch;
    int i = 0;
    while(1)
    {
        ch = getch();
        if (ch == 13) 
        /*如果用户按下了回车键（ch == 13），
        则将字符数组中的第i个元素设置为字符串结束符\0，
        并退出循环*/
        {
            pwd[i] = '\0';
            break;
        }
        else if(ch == 8)
        /*如果用户按下了退格键（ch == 8），则将i减1，
        并在控制台上输出退格符和空格符，
        以便删除前一个输入的字符*/
        {
            if(i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pwd[i] = ch;
            i++;
            printf("*");
            /*如果用户输入了其他字符，则将该字符存储在字符数组中的第i个元素中，
            并将i加1。在控制台上输出一个星号符号*，以表示输入的字符是密码中的一个字符。*/
        }
    }
}

//欢迎界面
void welcome()
{
    printf("************************************************************\n");
    printf("\n");
    printf("\n");
    printf("                    欢迎来到学生管理系统                \n");
    printf("\n");
    printf("\n");
    printf("************************************************************\n");
    printf("\n");
    printf("请选择你要进行的操作：\n");
    printf("1、添加学生信息               2、删除学生信息\n");
    printf("3、修改学生信息               4、查询学生信息\n");
    printf("5、显示所有学生信息             6、退出系统\n");
    printf("请输入你的选择>>");
}

//添加学生信息函数
void inputStudent(Stu* head)
{
    //创建移动指针
    Node * move = head;
    
    //移动到链表尾部
    while(move->next != NULL)
    {
        move = move->next;
    }
    
    //创建新节点
    Node * new = (Node *)malloc(sizeof(Node));
    new->next = NULL;
    
    //输入学生信息
    printf("请输入学生的学号>>");
    scanf("%d",&new->data.Student_ID);
    printf("请输入学生的姓名>>");
    scanf("%s",new->data.name);
    printf("请输入学生的年龄>>");
    scanf("%d",&new->data.age);
    printf("请输入学生的性别>>");
    scanf("%s",&new->data.sex);
    printf("请输入学生的班级>>");
    scanf("%d",new->data.class);
    printf("请输入学生的成绩>>");
    scanf("%d",&new->data.score);

    //将新节点插入链表
    move->next = new;

}

//显示学生信息函数
void printStudent(Node * head)
{
    //创建移动指针
    Node * move = head->next;
    
    while(move != NULL)
    {
        printf("学号:%d\t姓名:%s\t年龄:%d\t性别:%s\t班级:%d\t成绩:%d\n",
               move->data.Student_ID, move->data.name, move->data.age, move->data.sex, move->data.class, move->data.score);
    move = move->next;
    }
    system("pause");
    system("cls");
}

//删除学生信息函数
void deleteStudent(Node * head)
{
    printf("请输入你要删除的学生的学号>>");
    int STUid = 0;
    scanf("%d",&STUid);

    //创建移动指针
    Node * move = head;
    while(move->next != NULL)
    {
        if(move->next->data.Student_ID == STUid)
        {
            Node * temp = move->next;
            move->next = temp->next;
            free(temp);
            printf("删除成功!\n");
            saveStudent(head);
            break;
        }
        move = move->next;
    }
    if(move->next == NULL)
    {
        printf("未找到学生信息!\n");
    }
    system("pause");
    system("cls");
}

//修改学生信息函数
void modifyStudent(Node * head)
{
    printf("请输入你要修改的学生的学号>>");
    int STUid = 0;
    scanf("%d",&STUid);
    Node * move = head;
    while(move != NULL)
    {
        if(move->data.Student_ID == STUid)
        {
            printf("请输入学生的姓名>>");
            scanf("%s",move->data.name);
            printf("请输入学生的年龄>>");
            scanf("%d",&move->data.age);
            printf("请输入学生的性别>>");
            scanf("%s",move->data.sex);
            printf("请输入学生的班级>>");
            scanf("%d",&move->data.class);
            printf("请输入学生的成绩>>");
            scanf("%d",&move->data.score);
            printf("修改成功!\n");
            break;//修改成功后退出循环
        }
        move = move->next;
    }
    if(move == NULL)
    {
        printf("未找到学生信息!\n");
    }
    saveStudent(head);
    system("pause");
    system("cls");
}

//查询学生信息函数
void searchStudent(Node * head)
{
    FILE *file = fopen("C:/Users/91591/Desktop/C/Student Management System/stu.info", "r");
    if(file == NULL)
    {
        printf("文件打开失败!\n");
        return;
    }

    Node * new = malloc(sizeof(Node));
    new->next = NULL;
    Node * move = new;
    while(fread(&move->data, sizeof(Stu), 1, file) == 1)
    {
        move->next = new;
        move = new;
        new = malloc(sizeof(Node));
        new->next = NULL;
    }
    free(new);
    fclose(file);
    printf("读取成功!\n");
    printStudent(move);//打印链表
}

//保存学生信息函数
void saveStudent(Node * head)
{
    FILE * file = fopen("C:/Users/91591/Desktop/C/Student Management System/stu.info", "w");
    if(file == NULL)
    {
        printf("文件打开失败!\n");
        return;
    }
    Node * move = head->next;
    while(move != NULL)
    {
        fwrite(&move->data, sizeof(Stu), 1, file);
        move = move->next;
    }
    fclose(file);
    printf("保存成功!\n");
}

//统计学生人数函数
void countStudent(Node * head)
{
    int count = 0;
    Node * move = head->next;
    while(move != NULL)
    {
        count++;
        move = move->next;
    }
    printf("学生人数为:%d\n",count);
    system("pause");
    system("cls");
}

