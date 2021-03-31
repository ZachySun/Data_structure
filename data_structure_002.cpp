//伪代码
/*
InsertList(V, n, i, X){
    if(n >= maxsize){
        表满,return
    }
    if(i<1) or (i>n+1) then{
        参数i错误,return
    }
    else {
        for j = n to i step-1
            V[j+1]=V[j]
        end(j)
        V[i] = X
        n = n+1
        return
    }
}
*/
#include "stdio.h"
#define maxsize 10

//初始化
typedef struct list{
    int array[maxsize];
    int flag;
}list;

//定义插入函数
void InsertList(list L, int x, int y){
    int i,j;
    if(y<=0||y>L.flag+1)     //判断插入的位置是否正确，也可以定义一个函数
        printf("插入的位置有误\n");
    else{
    for(i=L.flag;i>y-2;i--){
        L.array[i+1] = L.array[i];
    }
    L.array[y-1]=x;
    L.flag++;
    for(j=0;j<L.flag+1;j++)
		printf("%d ",L.array[j]);
    }
    
}

//定义主函数
int main(){
	list L;
	char st;
	int i;
	int x,y;
	printf("请输入一组数（用逗号隔开）\n");
	for(i=0;st!='\n';i++){
		scanf("%d",&L.array[i]);
		L.flag=i;
		st=getchar();
	}
	printf("请输入要插入的数：\n");
	scanf("%d",&x);
	printf("请输入插入的位置：\n");
	scanf("%d",&y);
	InsertList(L,x,y);	
}