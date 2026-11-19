//双向链表，便于找前驱和后继

#include<stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct Node{
    Elemtype data;
    struct Node* next;
    struct Node* prev;
}Node,*dLinklist;
//初始化
dLinklist initLinklist(){
    dLinklist head = (dLinklist)malloc(sizeof(Node));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;
    return head;
}
//遍历双向链表
void dLinklistElem(dLinklist L){
    dLinklist p = L->next;
    while(p!=NULL){
      printf("%d ",p->data);
      p = p->next;
    }
}
//双向链表头插法
dLinklist InsertHead(dLinklist L, Elemtype e){
    if(L == NULL){
        return NULL;
    }
    dLinklist p = (dLinklist)malloc(sizeof(Node));
    if(p == NULL) return L;     // 分配失败

    p->data = e;
    p->prev = L;
    p->next = L->next;//先把p接好

    if(L->next != NULL){
        L->next->prev = p;  // 把p节点的前驱后继接好
    }
    L->next = p;

    return L;
}
//双向链表尾插法
dLinklist rearinsertelem(dLinklist L,Elemtype e){
    dLinklist tail = L;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    dLinklist p =(dLinklist)malloc(sizeof(Node));
    p->next = NULL;
    p->data = e;
    p->prev = tail;
    tail->next = p;
    return L;
}
//双链表指定位置插入
dLinklist posinsert(dLinklist L,int pos,Elemtype e){
    dLinklist p =(dLinklist)malloc(sizeof(Node));//基本操作，给新元素开辟空间
    p->data = e;
    dLinklist q = L;
    for(int i=0;i<pos-1;i++){
        q = q->next;
    }
    p->prev = q;
    p->next = q->next;
    if(q->next!=NULL){
        q->next->prev = p;
    }
    q->next = p;
    return L;
}
//测试主函数
int main(){
    dLinklist list1 = initLinklist();
    InsertHead(list1,1);
    printf("list1的第1个元素是%d\n",list1->next->data);
    rearinsertelem(list1,2);
    printf("list1尾插的第二个元素是%d\n",list1->next->next->data);
    rearinsertelem(list1,3);
    rearinsertelem(list1,4);
    rearinsertelem(list1,6);
    posinsert(list1,5,5);
    dLinklistElem(list1);
    return 0;
}