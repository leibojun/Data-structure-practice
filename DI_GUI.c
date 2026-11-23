#include<stdio.h>
//递归求和函数
//调用递归函数时需要用到栈内存，因为先调用的函数最后才会作用，一层层传下去然后再返回上来
int fun(int n){
    if(n==1){
        return 1;
    }
    else{
        return fun(n-1)+n;
    }
}
int main(){
    printf("%d",fun(9));
return 0;
}
//斐波那契数列递归  求第n项//递归调用会用到栈内存
int fibonacci(int n){
    if(n==1||n==2){
        return 1;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
