//顺序栈
# define maxsize 10

typedef int SElemType;   //可以快速更改数据类型
typedef int Status;

//栈的结构定义
typedef struct{
    SElemType data[maxsize];
    int top;
}SqStack;

//栈的插入操作
Status Push(SqStack *S, SElemType e){     //e为整形变量
    if(S->top == maxsize - 1){      //如果栈满
        return 0;
    }
    S->top++;                       //top+1
    S->data[S->top] = e;            //将新元素的值赋给栈顶
    return 1;
}

//栈的删除操作
Status Pop(SqStack *S, SElemType *e){    //e为整形指针
    if (S->top == -1){
        return 0;
    }
    *e = S->data[S->top];
    S->top--;
    return 1;
}

//栈的删除操作（小改）
Status Pop(SqStack *S, SElemType q){    //q为整形变量
    if (S->top == -1){
        return 0;
    }
    q = S->data[S->top];
    S->top--;
    return 1;
}



