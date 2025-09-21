#include <stdio.h>
#include <stdlib.h>

#define n 100

//creation of stack
int top = -1;
int arr[n];

//push operation
void push()
{
  int item;
  printf("enter the item:");
  scanf("%d", &item);
  if (top == n - 1)
  {
    printf("stack overflow\n");
  }
  else
  {
    top++;
    arr[top] = item;
    printf("item added\n");
  }
}


//pop operation
void pop()
{
  int item;
  if (top == -1)
  {
    printf("stack underflow\n");
  }
  else
  {
    item = arr[top];
    printf("deleted item %d\n", item);
    top--;
  }
}

//displaying stack elements
void display()
{
  if (top == -1)
  {
    printf("stack empty\n");
    exit(0);
  }
  else
  {
    for (int i = top; i >= 0; i--)
    {
      printf("%d\n", arr[i]);
    }
  }
}

//menu driven main function
int main()
{
  int op;
  printf("enter the operation\n");
  printf("Enter 1 for push operation\n");
  printf("Enter 2 for pop operation\n");
  printf("Enter 3 to display\n");
  printf("Enter 0 to exit\n");
  scanf("%d", &op);
  while (op)
  {
    if (op == 1)
      push();
    else if (op == 2)
      pop();
    else if (op == 3)
      display();
    else
      exit(0);
    printf("enter the next operation\n");
    printf("Enter 0 to exit\n");
    printf("Enter 1 for push operation\n");
    printf("Enter 2 for pop operation\n");
    printf("Enter 3 to display\n");
    scanf("%d", &op);
  }
}
