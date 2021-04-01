//伪代码
/*
DeleteList(V, n, i){
    if(i<1)or(i>n) then {
        参数i错误，return
    }
    else{
        for j = i to n-1
            V[j] = V[j+1]
        end(j)
        n = n-1
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
//定义删除函数
void Delete(list L, int x){
    int i,j;
    if(x<=0||x>L.flag+1)
        printf("删除的位置有误\n");
    else{ 
        for(i=x; i<L.flag+1; i++){
        L.array[i-1] = L.array[i];
    }
    L.flag--;
    for(j=0; j<L.flag+1; j++){
        printf("%d ",L.array[j]);
    }
    }
}
   
//定义主函数
int main(){
	list L;
	char st;
	int i;
	int x;
	printf("请输入一组数（用逗号隔开）\n");
	for(i=0;st!='\n';i++){
		scanf("%d",&L.array[i]);
		L.flag=i;
		st=getchar();
	}
	printf("请输入要删除第几个数：\n");
	scanf("%d",&x);
	Delete(L,x);	
}