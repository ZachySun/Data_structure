//伪代码
/*
AppendList (V, n, x)
{
    V[n+1] = x
    n = n + 1
}
*/

//声明、定义
#include "stdio.h"
#define maxsize 10
typedef struct list{
    int array[maxsize];
    int flag;
}list;

//定义插入函数

void Insert(list L, int x){
    L.array[L.flag+1] = x ;
    for(int k=0; k<=L.flag+1; k++){
        printf("%d ",L.array[k]);
    }
}


//定义主函数
int main(){
    list L;
    int x;
    char st;
    int i;
    printf("请输入一组数(用逗号隔开，最大长度为9)\n");
    for(i = 0; st!='\n'; i++){
        scanf("%d", &L.array[i]);
        L.flag = i;
        st = getchar();
    }
    printf("请输入要插入的数\n");
	scanf("%d", &x);
    Insert(L, x);	
}

