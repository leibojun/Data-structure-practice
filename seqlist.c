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
        printf("%d",L->data[i]);//*L.data[i]与L->data[i]等价，指针可用箭头，或用*解引用后使用L.data的方式访问结构体中的元素
        printf(" ");
    }
}
//顺序表插入元素（需要移动大量元素）
int insertElem(Seqlist* L,int pos,Elemtype e){
    if(pos<1||pos>L->length){
        printf("插入位置错误\n");
        return 0;
    }

    if (pos<=L->length){
         for(int i=L->length-1;i>=pos-1;i--){
             L->data[i+1]=L->data[i];
    }
    L->data[pos-1]=e;
    L->length++;
    return 1;
  }
}
//删除特定位置元素
int deleteElme(Seqlist* L,int pos,Elemtype* e){
    *e=L->data[pos-1];//接收取出的元素，通过访问地址赋值
    printf("被删除的元素为%d\n",*e);
    if(pos>L->length||pos<1){printf("位置错误\n");return 0;}
    if(pos<=L->length){
        for(int i=pos;i<L->length;i++){
           L->data[i-1]=L->data[i];
        }
        L->length--;
        return 1;
    }
}


int main(){//主测试函数
	Seqlist list1;
    int a;//用于后面接收delete的元素
	initlist(&list1);
	printf("初始化成功，目前长度%d\n",list1.length);
	printf("目前占用内存%zu字节\n",sizeof(list1.data));
    appendElem(&list1,12);
    appendElem(&list1,5);
    appendElem(&list1,4);
    appendElem(&list1,6);
    insertElem(&list1,1,36);
    deleteElme(&list1,3,&a);//a此前定义了，用于储存deleteElme函数删除的元素
    printf("添加元素后list的长度为 %d \n",list1.length);
    listElem(&list1);//遍历顺序表
	return 0;
}
