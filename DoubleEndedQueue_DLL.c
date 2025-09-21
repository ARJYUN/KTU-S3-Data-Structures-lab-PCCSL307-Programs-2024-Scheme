#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *front=NULL, *rear=NULL;

//enqueue at front
void insert_front(){
    int item;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the item : ");
    scanf("%d",&item);
    new->data=item;
    new->prev=NULL;
    new->next=NULL;
    if(front==NULL && rear==NULL){
        front=new;
        rear=new;
    }
    else{
        new->next=front;
        front->prev=new;
        front=new;
    }
}

//enqueue at rear
void insert_rear(){
    int item;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the item : ");
    scanf("%d",&item);
    new->data=item;
    new->prev=NULL;
    new->next=NULL;
    if(front==NULL && rear==NULL){
        front=new;
        rear=new;
    }
    else{
        new->prev=rear;
        rear->next=new;
        rear=new;
    }
}

//dequeue at front
void delete_front(){
    if(front==NULL && rear==NULL){
        printf("\nEmpty Queue !!");
        return;
    }
    else if(front==rear){
        printf("\n%d Deleted Successfully",front->data);
        front=NULL;
        rear=NULL;
    }
    else{
        printf("\n%d Deleted Successfully",front->data);
        front=front->next;
        free(front->prev);
        front->prev=NULL;
    }
}

//dequeue at rear
void delete_rear(){
    if(front==NULL && rear==NULL){
        printf("\nEmpty Queue !!");
        return;
    }
    else if(front==rear){
        printf("\n%d Deleted Successfully",rear->data);
        front=NULL;
        rear=NULL;
    }
    else{
        printf("\n%d Deleted Successfully",rear->data);
        rear=rear->prev;
        free(rear->next);
        rear->next=NULL;
    }
}

//displaying elements in deque
void display(){
    if(front==NULL && rear==NULL){
        printf("\nEmpty Queue !!");
        return;
    }
    struct node *ptr=front;
    while(ptr!=NULL){
        if(ptr->next!=NULL)
            printf("%d<=>",ptr->data);
        else
            printf("%d",ptr->data);
        ptr=ptr->next;
    }
    
}

//main function
void main(){
    int c;
    printf("Double Ended Queue using Doubly Linked List");
    printf("\n1.Insert at front\n2.Insert at rear\n3.Delete at front\n4.Delete at rear\n5.Display\n4.Exit");
    do{
        printf("\nEnter the operation : ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            insert_front();
            break;
        case 2:
            insert_rear();
            break;
        case 3:
            delete_front();
            break;
        case 4:
            delete_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting......");
            return;
        
        default:
            printf("\nInvalid Choice ");
            break;
        }    
    }while(c!=6);
}