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
//栈还可以链式存储，进栈操作本质是头插法，出栈删掉head节点后的节点就可以了
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
//枚举类型 示例
typedef enum{
    mon,tue,wed,thu,fri,sat,sun//默认值为0123456，若想从1开始，则写作mon=1，tue,wed....
}weekday;
//表达式求值————中缀后缀表达式
char expr[]="82/2+56*-";//全局可使用的字符串，用于后续运算
typedef enum{//先定义一个运算符枚举类型便于后续使用
    LEFT_PARE,RIGHT_PARE,ADD,SUB,MUL,DIV,MOD,EOS,NUM
}contentType;
contentType getToken(char* symbol,int* index){//这里用指针型变量目的是实时修改外部symbol和index的值，否则每次传参symbol和index都是空
    *symbol = expr[*index];//下面eval函数定义了symbol，这一步给symbol赋值了
    *index+=1;
    swich(*symbol){
        case'(': return LEFT_PARE;
        case')': return RIGHT_PARE;
        case'+': return ADD;
        case'-': return SUB;
        case'*': return MUL;
        case'/': return DIV;
        case'%': return MOD;
        case'\0': return EOS;
        default: return NUM;
    }
}
int eval(Stack* s){
    char symbol;//用于储存两个数字间的运算符
    int op1,op2;//用于储存一会出栈的两个顶部数字
    int index = 0;
    contentType token;//用于存储字符类型便于后面判断
    Elemtype result;//用于储存结果
    token = getToken(&symbol,&index);
    while(token!=EOS){
        if(token==NUM){
            push(s,symbol-'0');//字符转数字
        }
        else{//是运算符的话
          pop(s,&op2);
          pop(s,&op1);
        }
    }
}
//测试主函数(由动态内存分配，s为结构体指针)
int main(){
    Stack* s=initStack();//用指针类型变量接收init函数返回的指针类型
    isEmpty(s);
    push(s,10);//这里不是&s，因为s本身就是地址指针（由动态内存函数开辟），如果是静态开辟的s，则需要取地址&s
    push(s,20);
    push(s,30);
    push(s,40);
    printf("%d\n",s->data[s->top]);
    printf("枚举类型的元素为%d",mon);
    return 0;
}