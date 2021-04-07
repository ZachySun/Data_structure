#include <stdio.h>
#include <stdlib.h>
//建立单链表储存结构
typedef struct list{
    int data;                     //数据域
    struct list *next;            //指针域
}list;
typedef struct list *LinkList;    //定义一个结构体指针
//单链表的删除函数
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