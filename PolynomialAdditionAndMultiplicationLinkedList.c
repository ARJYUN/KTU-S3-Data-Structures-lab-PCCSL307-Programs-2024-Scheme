// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

int n1,n2;

struct node{
    int coef;
    int exp;
    struct node *link;
}*poly1,*poly2,*tail1,*tail2,*sum,*mul;

struct node* createNode(int coef,int exp){
    struct node *newN=(struct node*)malloc(sizeof(struct node));
    newN->coef=coef;
    newN->exp=exp;
    newN->link=NULL;
    return newN;
}

void display(struct node *poly){
    while (poly)
    {
        printf(" %dx^%d ", poly->coef, poly->exp);
        if (poly->link!=NULL && poly->link->coef > 0)
        {
            printf("+");
        }
        poly = poly->link;
    }
}

void add(struct node *poly1,struct node *poly2){
    struct node *newN,*i=poly1,*j=poly2,*k=sum;
    while(i!=NULL && j!=NULL){
        //case 1
        if(i->exp>j->exp){
            newN=createNode(i->coef,i->exp);
            i=i->link;
        }
        
        //case 2
        else if(i->exp<j->exp){
            newN=createNode(j->coef,j->exp);
            j=j->link;
        }
        
        //case 3
        else if(i->exp==j->exp){
            if(i->coef+j->coef==0){
                i=i->link;
                j=j->link;
                continue;
            }
            newN=createNode(i->coef+j->coef,i->exp);
            i=i->link;
            j=j->link;
        }
        
        if(sum==NULL){
            sum=k=newN;
        
        }
        else{
            k->link=newN;
            k=newN;
        }
    }
    
    while(i!=NULL){
        struct node *newN=createNode(i->coef,i->exp);
        i=i->link;
        if(sum==NULL){
            sum=k=newN;
        }
        else{
            k->link=newN;
            k=newN;
        }
    }
    
    while(j!=NULL){
        struct node *newN=createNode(j->coef,j->exp);
        j=j->link;
        if(sum==NULL){
            sum=k=newN;
        }
        else{
            k->link=newN;
            k=newN;
        }
    }
}

void multiply(struct node *poly1,struct node *poly2){
    struct node *newN,*i=poly1,*j=poly2,*k,*prev;
    while(i!=NULL){
        j=poly2;
        while(j!=NULL){
            int coef=i->coef*j->coef;
            int exp=i->exp+j->exp;
            
            k=mul;
            prev=NULL;
            while(k!=NULL && k->exp>exp){
                prev=k;
                k=k->link;
            }
            if(k!=NULL && k->exp==exp) {
                k->coef=k->coef+coef;
            }else{
                newN=createNode(coef,exp);
                if(prev==NULL){
                    newN->link = mul;
                    mul=newN;
                }
                else{
                    newN->link=prev->link;
                    prev->link=newN;
                }
            }
            j=j->link;
        }
        i=i->link;
    }
}

void main(){
    int coef,exp;
    printf("Enter the no.of terms in polynomial 1 and Polynomial 2: ");
    scanf("%d %d",&n1,&n2);
    printf("Enter the terms of polynomial 1 - coef,exp in proper order :\n");
    for(int i=0;i<n1;i++){
        scanf("%d %d",&coef,&exp);
        struct node *newN=createNode(coef,exp);
        if(poly1==NULL){
            poly1=tail1=newN;
        }
        else{
            tail1->link=newN;
            tail1=newN;
        }
        
    }
    
    printf("Enter the terms of polynomial 2 - coef,exp in proper order :\n");
    for(int i=0;i<n2;i++){
        scanf("%d %d",&coef,&exp);
         struct node *newN=createNode(coef,exp);
        if(poly2==NULL){
            poly2=tail2=newN;
        }
        else{
            tail2->link=newN;
            tail2=newN;
        }
        
    }
    
    printf("\nPolynomial 1: ");
    display(poly1);
     printf("\nPolynomial 2: ");
    display(poly2);
    
    printf("\nPolynomial 1 + Polynomial 2 = ");
    add(poly1,poly2);
    display(sum);
    
    printf("\nPolynomial 1 x Polynomial 2 = ");
    multiply(poly1,poly2);
    display(mul);
}
