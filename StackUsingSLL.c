#include <stdio.h>
#include <stdlib.h>

struct node *top = NULL;
struct node *temp = NULL;

struct node
{
   int data;
   struct node *link;
};

// push operation
void push_ll()
{
   int value;
   printf("Enter the value:");
   scanf("%d", &value);
   struct node *new = (struct node *)malloc(sizeof(struct node));
   new->data = value;
   new->link = top;
   top = new;
}

// pop operation
void pop_ll()
{
   if (top == NULL)
   {
      printf("Empty stack\n");
   }
   else
   {
      temp = top;
      printf("Deleted element is:%d\n", temp->data);
      top = top->link;
      free(temp);
   }
}

// display the stack elements
void display_ll()
{
   if (top == NULL)
   {
      printf("Empty list\n");
   }
   else
   {
      temp = top;
      while (temp != NULL)
      {
         printf("  %d", temp->data);
         temp = temp->link;
      }
   }
}

//main function
void main()
{
   int op;
   printf("Enter the operation\n1.push\n2.pop\n3.diplay\n");
   printf("Enter your choice:");
   scanf("%d", &op);
   while (op)
   {
      if (op == 1)
         push_ll();
      else if (op == 2)
         pop_ll();
      else if (op == 3)
         display_ll();
      else
         exit(0);
      printf("Enter the next operation\n1.push\n2.pop\n3.diplay\n");
      printf("Enter your choice:");
      scanf("%d", &op);
   }
}