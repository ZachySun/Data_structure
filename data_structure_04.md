## 栈
### 栈的定义
	-插入和删除操作只能在表尾进行的线性表
	-栈顶,栈底
![栈01](E:\AAA\vsproject\Cpp\栈01.png)
	-栈顶指示器(top):栈顶的标识符，空栈时top=0(也有的书是top=-1)
		-top = 0表示栈空；
		-top = maxsize表示栈满；
	-栈的大小(maxsize):标识栈中的元素个数
	-元素个数为空的栈为空栈
	-插入也称为压栈，删除也称为退栈
	-遵循的规则：后进先出
	-存储形式：
		-链式存储：栈的大小不可以预计
		-顺序存储：栈的大小可以预计
	-栈溢出：
		-上溢
		-下溢

#### 顺序栈：
栈的定义、压栈、退栈代码如下：
```cpp
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
    if(S->top == maxsize - 1){      /*如果栈满；在此代码中，top=-1为空栈，top==maxsize-1为满栈*/
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

```
以上代码参考《大话数据结构》

#### 链式栈：
	-当栈的最大容量预先不可估计时，使用链式存储方式的线性表来实现栈
	-如果 top = Nil，则表示栈空，不能进行出栈操作（否则产生下溢）
	-因为链式存储是动态分配空间的，所以链式栈一般不会出现上溢（除非内存已无可用空间）

**课程关于链式栈介绍到此，后续会更新**

#### 栈的应用： 
	-表达式求值：
		-(NS)操作数栈：存放参与运算的数值或变量
		-(OS)运算符栈：存放参与运算的运算符
	-表达式求值伪代码(例：A/B**C+D)：
		OS.Push(";")  //在运算符栈压入";"
		x = getNextSymbol  //扫描表达式
		while x != NULL    //只要x不为空
			if x是操作数 then     //如果x是数
				NS.Push(x); x = getNextSymbol; /*把x压入操作数栈，然后在扫描表达式*/
			else if x是运算符 then   //如果x是运算符
				if priority(x) > priority(OS的栈顶运算符) then 
					OS.Push(x); x = getNextSymbol; continue /*x运算符的优先级大于运算符栈顶运算符，则把x压入运算符栈*/
				else if x = ";" && OS的栈顶运算符=';' then
					表达式处理结束
					NS.Pop(r); return(r)
				else if priotity(x) <= priotity(OS的栈顶运算符) then
					NS.Pop(y);NS.Pop(x);OS.Pop()
					





