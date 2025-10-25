#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char data;
    struct node *lc, *rc;
}node;

node *stack[100];
int top = -1;

void push(node *n) {
    stack[++top]=n;
}

node* pop() {
    return stack[top--];
}

node* create(char data){
    node *n=(node*)malloc(sizeof(node));
    n->data=data;
    n->lc=n->rc=NULL;
    return n;
}

node* buildTree(char postfix[]) {
    for (int i=0;postfix[i]!='\0';i++) {
        char c=postfix[i];
        if(isalnum(c)) { 
            push(create(c));
        }else{
            node *n=create(c);
            n->rc=pop();
            n->lc=pop();
            push(n);
        }
    }
    return pop();
}

void inorder(node *p) {
    if (p!=NULL){
    if (p->lc) 
        printf("(");
    inorder(p->lc);
    printf("%c", p->data);
    inorder(p->rc);
    if (p->rc) 
        printf(")");
    }
    return;
}

void preorder(node* p) {
    if (p!=NULL){
    printf("%c", p->data);
    preorder(p->lc);
    preorder(p->rc);
    }
    return;
}

void postorder(node* p) {
    if (p!=NULL){
    postorder(p->lc);
    postorder(p->rc);
    printf("%c", p->data);
    }
    return;
}


void main() {
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    node* root = buildTree(postfix);
    printf("\nInorder   : ");
    inorder(root);
    printf("\nPreorder  : ");
    preorder(root);
    printf("\nPostorder : ");
    postorder(root);
}
