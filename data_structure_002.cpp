//α����
/*
InsertList(V, n, i, X){
    if(n >= maxsize){
        ����,return
    }
    if(i<1) or (i>n+1) then{
        ����i����,return
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

//��ʼ��
typedef struct list{
    int array[maxsize];
    int flag;
}list;

//������뺯��
void InsertList(list L, int x, int y){
    int i,j;
    if(y<=0||y>L.flag+1)     //�жϲ����λ���Ƿ���ȷ��Ҳ���Զ���һ������
        printf("�����λ������\n");
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

//����������
int main(){
	list L;
	char st;
	int i;
	int x,y;
	printf("������һ�������ö��Ÿ�����\n");
	for(i=0;st!='\n';i++){
		scanf("%d",&L.array[i]);
		L.flag=i;
		st=getchar();
	}
	printf("������Ҫ���������\n");
	scanf("%d",&x);
	printf("����������λ�ã�\n");
	scanf("%d",&y);
	InsertList(L,x,y);	
}