//找到链表倒数第k个节点 快慢双指针法
//具体思想，快指针先走k步，然后快慢指针同时走，快指针走到头时慢指针指向所需节点
#include <stdio.h>
#include <stdlib.h>
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
//尾插插节点的函数
Linklist rearinsertNode(Linklist head,Linklist node){
    Linklist tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = node;
    node->next = NULL;
    return node;//返回新的尾指针
}

//实现找倒数第k个阶段元素的函数
int findNodeFS(Linklist head,int k){
    Linklist fast = head;
    Linklist slow = head;
    for(int i=0;i<k;i++){
        fast = fast->next;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow->data;
}
//找两个字符串共同后缀的应用
Linklist findcoommon(Linklist head1,Linklist head2){
    Linklist p1 = head1;
    Linklist p2 = head2;
    int len1 = 0;
    int len2 = 0;
    int diff = 0;
    while(p1!=NULL){
        len1++;
        p1 = p1->next;
    }
    while(p2!=NULL){
        len2++;
        p2 = p2->next;
    }
    if(len1>len2){
        diff = len1-len2;
        p1 = head1;
        p2 = head2;
        for(int i = 0;i<diff;i++){//先把长度差异的部分走掉
            p1 = p1->next;
        }
        while(p1!=NULL&&p2!=NULL){//两个指针一起走直至指向相同地址
            if(p1==p2){
                printf("共同后缀的第一个节点的值为%d\n",p1->data);
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1==NULL||p2==NULL){
            printf("没有共同后缀\n");//无共同后缀情况
            return NULL;
        }
    }
    else{
        diff = len2-len1;
        p1 = head1;
        p2 = head2;
        for(int i = 0;i<diff;i++){//先把长度差异的部分走掉
            p2 = p2->next;
        }
        while(p1!=NULL&&p2!=NULL){//两个指针一起走直至相同
            if(p1==p2){
                printf("共同后缀的第一个节点的值为%d\n",p1->data);
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }    

}
//单链表应用之删去链表中绝对值相同的节点（只保留绝对值相同节点中的第一个）
void deleteAbsSame(Linklist head,int n){
      int index;//作为标志数组的下标
      int* q=(int*)malloc(sizeof(int)*(n+1));
      for(int i=0;i<n+1;i++){
        *(q+i) = 0;//先把标志数组全部置为0
      }
      Linklist p = head;
      while(p->next!=NULL){//p->next表示要删除的节点，p表示要删除节点的前驱节点
        index = abs(p->next->data);
        if(*(q+index)==0){//元素第一次出现，标志数组对应位置改为1
            *(q+index)=1;
            p=p->next;
        }
        else{
            Linklist Delete=p->next;//用p->next指向要删除的节点,这样表示便于找到前驱节点p
            p->next=Delete->next;
            free(Delete);//删除操作
        }
      }
      free(q);//释放标志数组的内存
}
//反转链表_三指针法
Linklist reverlist_1(Linklist head){
     Linklist first = NULL;
     Linklist second = head->next;
     Linklist third;
     while(second!=NULL){
        third = second->next;//先保存第二个节点的下一个节点，用于移动指针
        second->next = first;
        first = second;
        second = third;
     }
     Linklist newhead = (Linklist)malloc(sizeof(Node));
     newhead->next = first;
     return newhead;
}
//判断链表是否有环（快慢指针法）
int hasCycle(Linklist head){
    Linklist fast = head;
    Linklist slow = head;
    while(fast!=NULL&&fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow){//它俩能走到一块，说明有环
            return 1;//有环
        }
    }
    return 0;//无环
}
//找环的入口点，快慢指针，先求环节点数n，快指针先走n步，然后快慢一块走
Linklist findcyclespot(Linklist head){
    Linklist fast = head, slow = head;

    // ① 只负责找相遇点
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) break;
    }
    if(fast == NULL || fast->next == NULL) return NULL;   // 无环

    // ② 数环长（在循环外）
    int count = 1;
    Linklist p = fast->next;
    while(p != fast){
        p = p->next;
        count++;
    }

    // ③ 找入口（在循环外）
    fast = head;
    slow = head;
    for(int i = 0; i < count; i++){
        fast = fast->next;
    }
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
    int a;
    Linklist list2 = initList();
    rearinsertElem(list2,1);
    rearinsertElem(list2,2);
    rearinsertElem(list2,3);
    rearinsertElem(list2,4);
    rearinsertElem(list2,5);
    rearinsertElem(list2,6);
    a = findNodeFS(list2,3);
    printf("链表倒数第3个节点的值为%d\n",a);
    //共同后缀测试部分
    Linklist tail1 = initList();
    Linklist tail2 = initList();
    Linklist common1 = initList();
    Linklist common2 = initList();
    Linklist common3 = initList();
    common1->data = 7;
    common2->data = 8;
    common3->data = 9;
    common1->next = NULL;
    common2->next = NULL;
    common3->next = NULL;

    rearinsertElem(tail1,1);
    rearinsertElem(tail1,2);
    rearinsertElem(tail1,3);
    rearinsertNode(tail1,common1);
    rearinsertNode(tail1,common2);
    rearinsertNode(tail1,common3);
    rearinsertElem(tail2,4);
    rearinsertElem(tail2,5);
    rearinsertElem(tail2,6);
    rearinsertNode(tail2,common1);
    rearinsertNode(tail2,common2);
    rearinsertNode(tail2,common3);
    findcoommon(tail1,tail2);
    //删去链表中绝对值相同的节点测试部分
    Linklist list3 = initList();
    rearinsertElem(list3,1);
    rearinsertElem(list3,-1);
    rearinsertElem(list3,2);
    rearinsertElem(list3,4);
    rearinsertElem(list3,5);
    rearinsertElem(list3,-2);
    rearinsertElem(list3,6);
    listElem(list3);
    deleteAbsSame(list3,6);
    listElem(list3);
    Linklist newhead = reverlist_1(list3);//注意要接收返回的头节点
    listElem(newhead);
    //判断链表是否有环测试部分
    Linklist list4 = initList();
    rearinsertElem(list4,1);
    rearinsertElem(list4,2);
    rearinsertElem(list4,3);
    rearinsertElem(list4,4);
    rearinsertElem(list4,5);
    rearinsertElem(list4,6);
    rearinsertElem(list4,7);
    Linklist spot = list4->next->next->next;//让spot指向链表的第3个节点
    Linklist tail = list4;
    while(tail->next!=NULL){
        tail = tail->next;//找到尾节点
    }
    tail->next = spot;//让尾指针指向第三个节点，形成环
    if(hasCycle(list4)){
        printf("链表有环\n");
    }
    else{
        printf("链表无环\n");
    }
    Linklist v = findcyclespot(list4);
    printf("环的入口点的值为%d\n", v->data);
    return 0;
}
