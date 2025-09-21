#include<stdio.h>
#include<ctype.h>
#define MAX 100


char postfix[MAX];
char stack[MAX];
int top=-1;

//push operation on stack
void push(char c){
    stack[++top]=c;
}

//checking the character is an operator or not
int isOperator(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/');
}

//pop operation on stack
char pop(){
        return stack[top--];
}

//return the result of the corresponding operation between the operands
int calc(int a,int b,char c){
    switch(c){
        case '+':
                return a+b;
                break;
        case '-':
                return a-b;
                break;
        case '*':
                return a*b;
                break;
        case '/':
                return a/b;
                break;
    }
}

//evaluation of postfix expression
void eval(){
    char c;
    for(int i=0;postfix[i]!='\0';i++){
        c=postfix[i];
        if(isdigit(c)){
            int a = c-'0'; //to convert character to integer
            push(a);
        }
        else if(isOperator(c)){
            int b=pop();
            int a=pop();
            int ans=calc(a,b,c);
            push(ans);
        }
    }
}

//main function
void main(){
    printf("Enter the postfix expression: ");
    scanf("%s",postfix);
    eval();
    printf("\n Answer = %d",stack[top]);
}