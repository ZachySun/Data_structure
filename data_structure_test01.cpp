

#include "stdio.h"

// 使用结构体定义线性表
#define maxsize 15	          		// 最大值
typedef struct list{   
	int array[maxsize];       		// 添加最大值
	int flag;				        // 添加顺序结构线性表中的元素个数
}list;

// 函数声明
void LSort();                  		// 声明“排序”函数
void LOut();                   		// 声明“结果输出”函数
void LInsert();				        // 声明“插入”函数
void LDelete();                     // 声明“删除”函数

// 定义结构体L
list L;   

// 定义主函数
int main(){
	// 以下代码功能：使用键盘输入一组无序数据，并添加到线性表中        
	char st;
	int  i;
	int  x,y;
	printf("请输入一组数（用英文逗号隔开!!!,线性表的最大值为15）\n");
	for(i=0;st!='\n';i++){
		scanf("%d",&L.array[i]);
		L.flag=i;
		st=getchar();
	}

	// 以下代码功能：调用“排序”函数和“结果输出”函数
	printf("排序结果如下： \n");
	LSort();
	LOut();

	LInsert();									    // 调用“插入”函数
	LDelete();									    // 调用“删除”函数

}

// 定义“排序”函数
// 以下方法为冒泡排序法
void LSort(){
	int len = L.flag+1;                             // 获取线性表的长度
	int i, j, t;                             
	for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (L.array[j] > L.array[j+1]) {        // 相邻元素两两对比
                t = L.array[j+1];                   // 元素交换操作
                L.array[j+1] = L.array[j];
                L.array[j] = t;
            }
        }
    }
    
}

// 定义“结果输出”函数
void LOut(){
	int j;
	for(j=0;j<L.flag+1;j++)
		printf("%d ",L.array[j]);
	printf("\n当前线性表的长度为%d\n",L.flag+1);
}

// 定义“插入”函数
void LInsert(){
	int x, i=0;
	printf("\n请输入你要插入的数： \n");
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

// 定义“删除”函数
void LDelete(){
	int x, i=0, flag;
	printf("\n请输入你要删除的数： \n");
	scanf("%d",&x);
	while(x!=L.array[i]){
		i++;
	}
	flag = i+1;
	for(i=i+1; i<L.flag+1; i++){
        L.array[i-1] = L.array[i];
    }
	L.flag--;
	printf("你要删除的数是第%d个(若有多个重复的数，取第一个删除)\n",flag);
	LOut();
}
