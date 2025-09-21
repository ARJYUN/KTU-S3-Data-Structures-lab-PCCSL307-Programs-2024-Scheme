#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

//declaration of stack
char stack[MAX];
int top=-1;

//declaration of infix and postfix expression character arrays
char infix[MAX];
char postfix[MAX];

//push operation on stack
void push(char c){
    stack[++top]=c;
}

//pop operation on stack
char pop(){
    if (stack[top]!='(')
        return stack[top--];
    else
        top--;
}

//to check the character is an operator or not 
int isOperator(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/');
}

//to return the precedence of the corresponding operator
int precendence(char c){
    switch(c){
        case '+':case '-':return 1;
        case '*':case '/':return 2;
        default:return 0;
    }
}

//function to convert infix to postfix
void infixToPostFix(){
    char c;
    int j=0;
    for(int i=0;infix[i]!='\0';i++){
        c=infix[i];
        if(c=='('){
            push(c);
        }
        else if(c==')'){
            while(top!=-1 && stack[top]!='('){
                postfix[j++]=pop();
            }
            pop();
        }
        else if(isOperator(c)){
            while(precendence(c)<=precendence(stack[top])){
                postfix[j++]=pop();
            }
            push(c);
        }
        else{
            postfix[j++]=c;
        }
    }
    while(top!=-1){
        postfix[++j]=pop();
    }
    postfix[j]='\0';
}

//menu driven main function
void main(){
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    push('(');
    infixToPostFix();
    printf("PostFix Expression : %s",postfix);
    
}