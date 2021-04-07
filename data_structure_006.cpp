//涉及单链表的一系列操作，建立、获取、插入、删除

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//建立单链表储存结构
typedef struct list{
    int data;                     //数据域
    struct list *next;            //指针域
}list;
typedef struct list *LinkList;    //定义一个结构体指针

//单链表的整表创建（头插法）
void HeadCreateList(LinkList *L, int n){
    LinkList p;        //定义一个结构体指针
    int i;             //定义计数变量i
    srand(time(0));
    *L = (LinkList)malloc(sizeof(list)); //初始化空链表
    (*L)->next = NULL;         //让L的头结点指针指向NULL
    for (i = 0; i<n;i++){
        p = (LinkList)malloc(sizeof(list)); //生成一个新结点
        p->data = rand()%100+1;  //随机生成100以内的数字
        p->next = (*L)->next;    //让p指向L指向的结点
        (*L)->next = p;          //让L指向p结点
    }
}

//单链表的整表创建（尾插法）
void TailCreateList(LinkList *L, int n) 
{
	LinkList p,r;                //定义结构体指针p、r,也即定义了两个结点
	int i;                       //定义了计数变量
	srand(time(0));                      
	*L = (LinkList)malloc(sizeof(list));  //初始化空链表
	r=*L;                                
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(list)); 
		p->data = rand()%100+1;           
		r->next=p;                       //让r指向p结点
		r = p;                           //让p结点成为新的p结点
	}
	r->next = NULL;                      //链表的最后，令指针指向空
}


//操作1：获取链表的第i个数据
int GetElem(LinkList L, int i, int *e)
{
    int j;
    LinkList p;   //声明一个p结点
    p = L->next;  //让p指向L的第一个结点,p存储的是第一个结点的地址
    j = 1;
    while (p&&j<i){   //*p不为空，或者j<i
    p = p->next;      //让p指向下一个结点
    ++j;
    }

    if(!p || j>i){
        return 0;
    }
    *e = p->data;
    return 1;
}

//操作2：在第i个位置插入链表，数据为e
int ListInsert(LinkList *L,int i,int e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     //p不为空且j<i
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i)       //没有第i个元素
		return 0;   
	s = (LinkList)malloc(sizeof(list));  //该语句用于生成一个新的节点
	s->data = e; 

	s->next = p->next;     //标准语法
	p->next = s;      

	return 1;
}

//操作3：删除单链表的第i个元素，获取该结点的数据e
int LDelete(LinkList *L, int i, int *e){
    int j;
    LinkList p,q;    //定义p,q两个结构体指针
    p = *L;          
    j = 1;
    while(p->next && j<i){  //寻找要删除的第i个元素：1.p结点的指针域不为空;2.j<i
        p = p->next;
        ++j;
    }
    if (!(p->next) || j>i){
        return 0;
    }

    q = p->next;         //核心的两行代码
    p->next = q->next;

    *e = q->data;
    free(q);    //回收q结点
    return 1;
}

//单链表的整表删除
int ClearList(LinkList *L){
    LinkList p,q;
    p = (*L)->next;   //使p指向第一个结点，p存储第一个结点的地址
    while(p){         //没到表尾则继续运行
        q = p->next;  //让q成为第二个结点（第一轮）
        free(p);      //释放p
        p = q;        //让q成为新的p
    }
    (*L)->next=NULL;
    return 1;
}  