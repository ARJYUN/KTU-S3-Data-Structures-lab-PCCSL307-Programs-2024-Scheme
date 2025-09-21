#include <stdio.h>
#include <stdlib.h>

struct node *front = NULL;
struct node *temp = NULL;
struct node *rear = NULL;

struct node
{
   int data;
   struct node *link;
};

// enqueue operation
void enqueue_ll()
{
   int value;
   printf("Enter the value:");
   scanf("%d", &value);
   struct node *new = (struct node *)malloc(sizeof(struct node));
   new->data = value;
   if (front == NULL)
   {
      front = new;
   }
   else
   {
      rear->link = new;
   }
   new->link = NULL;
   rear = new;
}

// dequeue operation
void dequeue_ll()
{
   if (front == NULL)
   {
      printf("Empty queue\n");
      exit(0);
   }
   else
   {
      temp = front;
      printf("Deleted element is:%d\n", front->data);
      front = front->link;
      free(temp);
   }
}

// display queue elements
void display_ll()
{
   if (front == NULL)
   {
      printf("Empty queue\n");
   }
   else
   {
      temp = front;
      printf("\n");
      while (temp != NULL)
      {
         printf("   %d", temp->data);
         temp = temp->link;
      }
   }
}

// main function
void main()
{
   int op;
   printf("Enter the Operation\n1.Enqueue\n2.Dequeue\n3.Diplay\n");
   printf("Enter your choice:");
   scanf("%d", &op);
   while (op)
   {
      if (op == 1)
         enqueue_ll();
      else if (op == 2)
         dequeue_ll();
      else if (op == 3)
         display_ll();
      else
         exit(0);
      printf("\n\nEnter the next Operation\n1.Enqueue\n2.Dequeue\n3.Diplay\n");
      printf("Enter your choice:");
      scanf("%d", &op);
   }
}