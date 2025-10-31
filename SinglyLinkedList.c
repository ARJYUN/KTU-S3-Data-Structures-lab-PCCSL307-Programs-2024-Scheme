#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* head=NULL;
struct node* temp=NULL;

//insertion at beginning of sll(singly linked list)
void insert_beg()
{   int value;
    printf("Enter the value:");
    scanf("%d",&value);
    struct node* new= (struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->link=head;
    head=new;
}

//insertion at the end of sll
void insert_end()
{   int value;
    printf("Enter the value:");
    scanf("%d",&value);
    struct node* new= (struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->link=NULL;
    if (head==NULL)
       {head=new;}
    else
       {struct node* temp=head;
        while(temp->link!=NULL)
            temp=temp->link;
        temp->link=new;
        }
}

//insertion in between of sll
void insert_btw()
{   int value;
    printf("Enter the value:");
    scanf("%d",&value);
    int pos;
    printf("Enter the position:");
    scanf("%d",&pos);
    struct node* new= (struct node*)malloc(sizeof(struct node));
    new->data=value;
    struct node* temp=head;
    while((temp->data!=pos)&&(temp->link!=NULL))
       {temp=temp->link;}
    if(temp->link!=NULL)
        {new->link=temp->link;
         temp->link=new;
        }
    else
        {printf("Element not found\n");}
}

//deletion at the beginning of sll
void deletion_begin()
{   if(head==NULL)
        {printf("Empty list\n");
         exit(0);}
    else  
        {temp=head;
         printf("Deleted element is:%d\n",temp->data);
         head=head->link;
         free(temp);}
}

//deletion at the end of sll
void deletion_end()
{   struct node* prev=NULL;
    if(head==NULL)
       {printf("Empty list");}
    else 
       {prev=NULL;
        temp=head;
        while(temp->link!=NULL)
            {prev=temp;
            temp=temp->link;}
        printf("Deleted item is:%d\n",temp->data);
        prev->link=NULL;
        free(temp);
        }
}

//deletion in between of sll
void deletion_btw()
{   int pos;
    struct node* prev=NULL;
    printf("Enter the position:");
    scanf("%d",&pos);
    prev=NULL;
    temp=head;
    while((temp->data!=pos)&&(temp->link!=NULL))
       {prev=temp;
        temp=temp->link;}
    if(temp->link!=NULL)
       {printf("Deleted element is:%d\n",temp->data);
        prev->link=temp->link;
        free(temp);}
    else  
       {printf("Key not found\n");}
} 

//displaying sll
void display_ll()
{   if(head==NULL)
        {printf("Empty list");
         exit(0);}
    else
        {temp=head;
         while(temp!=NULL)
            { printf("  %d",temp->data);
              temp=temp->link;
            }
        }
}


//main function
void main()
{ int op;
  int op1,op2;
  printf("\nEnter the operation\n0.Exit\n1.insert\n2.Delete\n3.Display\n");
  printf("Enter your choice:");
  scanf("%d",&op);
  while(op)
    {if (op==1)
       {printf("1.Instert front\n2.Insert rear\n3.Insert in between\n");
        printf("Enter your choice:");
        scanf("%d",&op1);
        switch(op1)
           {case 1:
              insert_beg();
              break;
            case 2:
              insert_end();
              break;
            case 3:
              insert_btw();
              break;
            default: 
              printf("invalid operation\n");
            }
        }
    else if (op==2)
       {
        printf("1.Delete from front\n2.Delete from rear\n3.Delete in between\n");
        scanf("%d",&op2);
        switch(op2)
           {case 1:
              deletion_begin();
              break;
            case 2:
              deletion_end();
              break;
            case 3:
              deletion_btw();
              break;
            default:
              printf("invalid operation\n");
            }
        }
    else if (op==3)
        display_ll();
    else
        exit(0);
       printf("\nEnter the next operation\n0.Exit\n1.Insert\n2.Delete\n3.Display\n");
       printf("Enter your choice:");
       scanf("%d",&op);
       }
}




















   
