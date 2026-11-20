#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int Elemtype;
//存储结构
typedef struct{
    Elemtype data[MAXSIZE];
    int top;
}stack;
//初始化栈
void initstack(stack* s){
    s->top = -1;
}//主函数中需要静态分配的栈时则需要stack st; initstack(&st),然后其他函数中需要传指针时均需要取地址&st;
//动态内存分配储存结构和初始化（本质区别：用指针操作）
typedef struct{
    Elemtype* data;//data[i] 等价于 *(data + i)，所以后面的函数都能正常用
    int top;
}Stack;
//初始化栈（动态内存分配）
Stack* initStack(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (Elemtype*)malloc(sizeof(Elemtype)*MAXSIZE);
    s->top = -1;
    return s;//返回的是一个Stack类型的指针，指向开辟的栈
}
//判断栈空 若top==-1，则栈空
int isEmpty(Stack* s){//传入一个栈类型的指针用于指向栈中数据，作用类似于Linklist（Node *）
    if(s->top==-1){
        printf("empty\n");
        return 1;
    }
    else{
        return 0;
    }
}
//进栈操作
int push(Stack* s,Elemtype e){
    if(s->top==MAXSIZE-1){
     printf("full\n");
     return 0 ;//先判断满没满
    }
    else{//不满就进栈
        s->top++;
        s->data[s->top] = e;
        return 1;
    }
}
//出栈操作       需要接收元素时要注意 可能需要传入地址指针
int pop(Stack* s,Elemtype* e){//这里传入一个Elemtype类型指针用于接收出栈的元素,所以应用时对应位置可以是&a（示例）
    if(s->top==-1){
        printf("empty\n");
        return 0;
    }
    else{
        *e = s->data[s->top];
        return 1;
    }
}
//测试主函数
int main(){
    Stack* s=initStack();//用指针类型变量接收init函数返回的指针类型
    isEmpty(s);
    push(s,10);//这里不是&s，因为s本身就是地址指针（由动态内存函数开辟），如果是静态开辟的s，则需要取地址&s
    push(s,20);
    push(s,30);
    push(s,40);
    printf("%d",s->data[s->top]);
    return 0;
}