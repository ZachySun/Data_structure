

#include "stdio.h"

// ʹ�ýṹ�嶨�����Ա�
#define maxsize 15	          		// ���ֵ
typedef struct list{   
	int array[maxsize];       		// ������ֵ
	int flag;				        // ���˳��ṹ���Ա��е�Ԫ�ظ���
}list;

// ��������
void LSort();                  		// ���������򡱺���
void LOut();                   		// ������������������
void LInsert();				        // ���������롱����
void LDelete();                     // ������ɾ��������

// ����ṹ��L
list L;   

// ����������
int main(){
	// ���´��빦�ܣ�ʹ�ü�������һ���������ݣ�����ӵ����Ա���        
	char st;
	int  i;
	int  x,y;
	printf("������һ��������Ӣ�Ķ��Ÿ���!!!,���Ա�����ֵΪ15��\n");
	for(i=0;st!='\n';i++){
		scanf("%d",&L.array[i]);
		L.flag=i;
		st=getchar();
	}

	// ���´��빦�ܣ����á����򡱺����͡�������������
	printf("���������£� \n");
	LSort();
	LOut();

	LInsert();									    // ���á����롱����
	LDelete();									    // ���á�ɾ��������

}

// ���塰���򡱺���
// ���·���Ϊð������
void LSort(){
	int len = L.flag+1;                             // ��ȡ���Ա�ĳ���
	int i, j, t;                             
	for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (L.array[j] > L.array[j+1]) {        // ����Ԫ�������Ա�
                t = L.array[j+1];                   // Ԫ�ؽ�������
                L.array[j+1] = L.array[j];
                L.array[j] = t;
            }
        }
    }
    
}

// ���塰������������
void LOut(){
	int j;
	for(j=0;j<L.flag+1;j++)
		printf("%d ",L.array[j]);
	printf("\n��ǰ���Ա�ĳ���Ϊ%d\n",L.flag+1);
}

// ���塰���롱����
void LInsert(){
	int x, i=0;
	printf("\n��������Ҫ��������� \n");
	scanf("%d",&x);
	while(x>L.array[i]&&i<=L.flag){                  
		i++;
	}
	for(int j=L.flag+1; j>i; j--){
		L.array[j] = L.array[j-1];
	}
	L.array[i] = x;
	L.flag++;
	LOut();

}

// ���塰ɾ��������
void LDelete(){
	int x, i=0, flag;
	printf("\n��������Ҫɾ�������� \n");
	scanf("%d",&x);
	while(x!=L.array[i]){
		i++;
	}
	flag = i+1;
	for(i=i+1; i<L.flag+1; i++){
        L.array[i-1] = L.array[i];
    }
	L.flag--;
	printf("��Ҫɾ�������ǵ�%d��(���ж���ظ�������ȡ��һ��ɾ��)\n",flag);
	LOut();
}
