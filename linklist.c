#include<stdio.h>
#include<stdlib.h>
//定义链表的结构体
typedef struct Node{
    int data;//数据域
    struct Node* next;//指针域
}Node,*Linklist;//*Linklist 的实际意思是「Linklist 是 struct Node * 的别名」
//初始化链表
Linklist initList(){//Linklist与Node*等价，都是指向结构体的指针类型，是别名
    Linklist head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}
//单链表遍历
void listElem(Linklist head){
    Linklist p = head->next;
    while(p!=NULL){
        printf("%d  ",p->data);
        p = p->next;
    }
    printf("\n");
}
//头插法
Linklist insertElem(Linklist head,int e){
    Linklist p = (Linklist)malloc(sizeof(Node));//创建新节点存e
    p->data = e;
    p->next = head->next;
    head->next = p;
}
//尾插法
Linklist rearinsertElem(Linklist head,int e){
    Linklist rear;
    Linklist p = (Linklist)malloc(sizeof(Node));//创建新节点存e
    p->data = e;
    p->next = NULL;
    Linklist q = head;
    while(q->next!=NULL){
        q=q->next;//让q指向链表的尾指针
    }
    q->next = p;//q此时是尾指针，让尾指针的next指向新节点p
    rear = p;//rear指向尾指针
    return rear;//返回尾指针
}
//在指定位置插入数据
Linklist insertElemPos(Linklist head,int e,int pos){
    Linklist p =(Linklist)malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;
    Linklist q = head;
    for(int i=0;i<pos-1;i++){
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
    return head;
}
//删除指定位置元素
Linklist deleteElemPos(Linklist head,int pos){
    Linklist p = head;
    Linklist deleteNode;//创建一个指针指向要删除的节点
    for(int i=0;i<pos-1;i++){
        p = p->next;//让p指向要删除节点的前一个节点
    }
    deleteNode = p->next;
    p->next = p->next->next;//删除的基本操作，让前驱指向后继
    free(deleteNode);//释放内存
    return head;
}
//释放链表(保留头结点)
void freeList(Linklist head){
    Linklist p =head->next;
    while(p!=NULL){
        Linklist q = p->next;
        free(p);
        p = q;
    }
}
//测试主函数
int main(){
    Linklist list1 = initList();
    insertElem(list1,1);
    insertElem(list1,2);
    insertElem(list1,3);
    rearinsertElem(list1,4);
    listElem(list1);
    insertElemPos(list1,6,2);
    listElem(list1);
    deleteElemPos(list1,4);
    listElem(list1);
    return 0;
}