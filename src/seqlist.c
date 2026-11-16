#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
typedef int Elemtype;
typedef struct{
	Elemtype data[100];
	int length;
}Seqlist;//定义了顺序表的存储结构
void initlist(Seqlist* L){
	L->length = 0;
}//初始化步骤
int main(){
	Seqlist list1;
	initlist(&list1);
	printf("初始化成功，目前长度%d\n",list1.length);
	printf("目前占用内存%zu字节\n",sizeof(list1.data));
	return 0;
}
