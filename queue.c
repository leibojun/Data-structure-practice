#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define MAXSIZE2 7
//存储结构（静态）
typedef int Elemtype;
typedef struct{
    Elemtype data[MAXSIZE];
    int front;//存储队头元素下标
    int rear;//存储队尾元素下标
}queue;
//初始化（静态）
void initqueue(queue* Q){//需要传入建立的队列的地址，然后对它初始化
    Q->front = 0;
    Q->rear = 0;
}
//储存结构（动态内存分配）
typedef struct{
    Elemtype* data;
    int front;
    int rear;
}Queue;
//初始化（动态）
Queue* initQueue(){//无需传参，最后返回一个队列的指针
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->data = (Elemtype*)malloc(sizeof(Elemtype)*MAXSIZE);
    q->front = 0;
    q->rear = 0;
    return q;
}
//判空
int isempty(queue* Q){
    if(Q->front==Q->rear){
        printf("empty");
        return 1;
    }
    else{
        printf("真的满了");
        return 0;
    }
}
//判满
int queueFull(queue* Q){
    if(Q->front>0){
        int step = Q->front;
        for(int i = Q->front;i<=Q->rear;++i){
            Q->data[i-step] = Q->data[i];
        }
        Q->front = 0;
        Q->rear = Q->rear-step;
        return 1;
    }
    else{
        printf("真的满了");
    }
}
//入队操作
int equeue(queue* Q,Elemtype e){
    if(Q->rear>=MAXSIZE){
        if(!queueFull(Q)){
            return 0;
        }
    }
    Q->data[Q->rear] = e;
    Q->rear+=1;
    return 1;
}
//出队
int dequeue(queue* Q,Elemtype* e){
    if(Q->rear == Q->front){
        printf("empty");
    }
    else{
        *e = Q->data[Q->front];
        Q->front++;
    }
}
//获取队头元素
int gethead(queue* Q,Elemtype* e){
    if(Q->front==Q->rear){
        printf("empty");
        return 0;
    }
    *e = Q->data[Q->front];
    return 1;
}
//循环队列（解决假溢出情况）
//循环入队
int equeue2(Queue* Q,Elemtype e){
    if((Q->rear+1)%MAXSIZE2==Q->front){//循环队列判满操作
        printf("full");
        return 0;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1)%MAXSIZE2;//队尾指针移动操作
    return 1; 
}
//循环出队
int dequeue2(Queue* Q,Elemtype* e){
    if(Q->front==Q->rear){//队列判空
        printf("empty");
        return 0;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE2;//队头指针移动操作
    return 1;
}
//获取队头元素
int gethead2(Queue* Q,Elemtype* e){
     if(Q->rear==Q->front){
        printf("empty");
        return 0;
     }
     printf("队头元素是%d",Q->data[Q->front]);
     return 1;
}
//测试主函数
int main(){
    queue q;
    int a;
    int b;
    int c;
    int d;
    int e;
    initqueue(&q);
    equeue(&q,1);
    equeue(&q,2);
    equeue(&q,3);
    equeue(&q,4);
    dequeue(&q,&a);
    printf("%d",a);//输出1，先进先出
    Queue* Q = initQueue();//动态内存开辟队列
    equeue2(Q,1);
    equeue2(Q,2);
    equeue2(Q,3);
    equeue2(Q,4);
    equeue2(Q,5);
    equeue2(Q,6);
    dequeue2(Q,&b);
    dequeue2(Q,&c);
    dequeue2(Q,&d);
    gethead2(Q,&e);
    return 0;
}