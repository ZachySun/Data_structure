//α����
/*
DeleteList(V, n, i){
    if(i<1)or(i>n) then {
        ����i����return
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
//��ʼ��
typedef struct list{
    int array[maxsize];
    int flag;
}list;
//����ɾ������
void Delete(list L, int x){
    int i,j;
    if(x<=0||x>L.flag+1)
        printf("ɾ����λ������\n");
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
   
//����������
int main(){
	list L;
	char st;
	int i;
	int x;
	printf("������һ�������ö��Ÿ�����\n");
	for(i=0;st!='\n';i++){
		scanf("%d",&L.array[i]);
		L.flag=i;
		st=getchar();
	}
	printf("������Ҫɾ���ڼ�������\n");
	scanf("%d",&x);
	Delete(L,x);	
}