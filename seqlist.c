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
}//初始化函数
//尾插元素法 利用length获取最后一个元素的下标
int appendElem(Seqlist* L,Elemtype e){
    if(L->length>=MAXSIZE){
        printf("顺序表已满\n");
        return 0;
    }
    L->data[L->length]=e;
    L->length++;
    return 1;
}
//顺序表遍历
void listElem(Seqlist* L){
    for(int i = 0;i<L->length;i++){
        printf("%d",*L.data[i]);
        printf(" ");
    }
}
//顺序表插入元素（需要移动大量元素）




int main(){//主测试函数
	Seqlist list1;
	initlist(&list1);
	printf("初始化成功，目前长度%d\n",list1.length);
	printf("目前占用内存%zu字节\n",sizeof(list1.data));
    appendElem(&list1,12);
    appendElem(&list1,5);
    appendElem(&list1,4);
    appendElem(&list1,3);
    printf("添加元素后list的长度为 %d  ",list1.length);
    listElem(&list1);
	return 0;
}
