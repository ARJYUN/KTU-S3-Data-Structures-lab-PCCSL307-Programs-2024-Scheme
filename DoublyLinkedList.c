#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;

//insertion at front
void insert_front(){
    int item;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the item : ");
    scanf("%d",&item);
    new->data=item;
    new->prev=NULL;
    new->next=NULL;
    if(head==NULL){
        head=new;
    }
    else{
        new->next=head;
        head->prev=new;
        head=new;
    }
}

//insertion at end
void insert_end(){
    int item;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the item : ");
    scanf("%d",&item);
    new->data=item;
    new->prev=NULL;
    new->next=NULL;
    if(head==NULL){
        head=new;
    }
    else{
        struct node *ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=new;
        new->prev=ptr;
    }
}

//insertion in between
void insert_key(){
    int item,key;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the item : ");
    scanf("%d",&item);
    new->data=item;
    printf("\nEnter the key : ");
    scanf("%d",&key);
    new->prev=NULL;
    new->next=NULL;
    struct node *ptr=head;
    while(ptr->data!=key && ptr!=NULL){
        ptr=ptr->next;
    }
    if(ptr->data==key){
        new->prev=ptr;
        new->next=ptr->next;
        (ptr->next)->prev=new;
        ptr->next=new;
    }
    else{
        printf("\nKey not found !! ");
    }
}

//delete at beginning
void delete_front(){
    if(head==NULL){
        printf("\nEmpty list !!");
        return;
    }
    else if(head->next==NULL){
        free(head);
    }
    else{
        struct node *ptr=head;
        head=head->next;
        head->prev=NULL;
        free(ptr);
    }
}

//delete at end
void delete_end(){
    if(head==NULL){
        printf("\nEmpty list !!");
        return;
    }
    else if(head->next==NULL){
        printf("\n%d Deleted Successfully.",head->data);
        free(head);
    }
    else{
        struct node *ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        (ptr->prev)->next=NULL;
        free(ptr);
    }
}

//delete in between
void delete_key(){
    int key;
    if(head==NULL){
        printf("\nEmpty list !!");
        return;
    }
    printf("\nEnter the key : ");
    scanf("%d",&key);
    struct node *ptr=head;
    while(ptr->data!=key && ptr!=NULL){
        ptr=ptr->next;
    }
    if(ptr->data==key && ptr->next!=NULL){
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        free(ptr);
    }
    else if(ptr->data==key && ptr->next==NULL){
        (ptr->prev)->next=NULL;
        free(ptr);
    }
    else if(ptr->data==key && ptr->prev==NULL){
        head=head->next;
        head->prev=NULL;
        free(ptr);
    }
}

//display elements in dll
void display(){
    if(head==NULL){
        printf("\nEmpty List !!");
        return;
    }
    struct node *ptr=head;
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
    int c1,c2,c3;
    printf("Doubly Linked List");
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
    do{
        printf("\nEnter the operation : ");
        scanf("%d",&c1);
        switch (c1)
        {
        case 1:{
            printf("\n1.Insert at front\n2.Insert at end\n3.Insert at key");
            printf("\nEnter your choice : ");
            scanf("%d",&c2);
            if(c2==1)
                insert_front();
            else if(c2==2)
                insert_end();
            else if(c2==3)
                insert_key();
            else
                printf("\n Invalid Choice !! ");
            break;}
        case 2:{
            printf("\n1.Delete at front\n2.Delete at end\n3.Delete at key");
            printf("\nEnter your choice : ");
            scanf("%d",&c3);
            if(c3==1)
                delete_front();
            else if(c3==2)
                delete_end();
            else if(c3==3)
                delete_key();
            else
                printf("\n Invalid Choice !! ");
            break;}
        case 3:
            display();
            break;
        case 4:
        printf("Exiting..........");
            return;
        
        default:
            printf("\nInvalid Choice ");
            break;
        }    
    }while(c1!=4);
}