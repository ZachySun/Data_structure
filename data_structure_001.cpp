//α����
/*
AppendList (V, n, x)
{
    V[n+1] = x
    n = n + 1
}
*/

//����������
#include "stdio.h"
#define maxsize 10
typedef struct list{
    int array[maxsize];
    int flag;
}list;

//������뺯��

void Insert(list L, int x){
    L.array[L.flag+1] = x ;
    for(int k=0; k<=L.flag+1; k++){
        printf("%d ",L.array[k]);
    }
}


//����������
int main(){
    list L;
    int x;
    char st;
    int i;
    printf("������һ����(�ö��Ÿ�������󳤶�Ϊ9)\n");
    for(i = 0; st!='\n'; i++){
        scanf("%d", &L.array[i]);
        L.flag = i;
        st = getchar();
    }
    printf("������Ҫ�������\n");
	scanf("%d", &x);
    Insert(L, x);	
}

