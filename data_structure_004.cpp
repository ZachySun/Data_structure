//链式结构线性表的插入操作
/*伪代码
//把b插入到a的前面
InsertLinkedList(head, a, b){
    GetNode(p)     //获取新节点p
    data(p) = b    //新节点的数据域为b

    if (head = Nil) then {     //如果是空表
        head = p;        //让p节点成为表头
        next(p) = Nil;   //让p的指针域指向空集
        return
    }

    if (data(head)==a){  //如果头节点的数据域就是a
        next(p) = head;  //此时p应该是新的头节点,让p的指针域指向原来的头节点
        head = p;        //p成为新的头节点
    }

    else{                 //先找a的前继节点的指针q
        lookFor(head, a, q)
        next(p)=next(q)
        next(q)=p
    }
   return
}
LookFor(head, a, q){     //q是指向a的前继节点的指针
    q = head;
    while(next(q)!=Nil) and (data(next(q))!=a)do
        q = next(q)
    return
}
*/
#include <stdio.h>
#include <stdlib.h>

//下面的内容有参考《大话数据结构》

//建立单链表储存结构
typedef struct list{
    int data;                     //数据域
    struct list *next;            //指针域
}list;
typedef struct list *LinkList;    //定义一个结构体指针

//获取链表的第i个数据
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

//单链表的插入
//标准语句： s->next = p->next; p->next = s;
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







