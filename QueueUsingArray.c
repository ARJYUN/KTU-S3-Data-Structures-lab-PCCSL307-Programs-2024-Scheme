#include <stdio.h>
#include <stdlib.h>

#define n 100

//creation of queue
int arr[n];
int front = -1, rear = -1;

//enqueue operation
void enqueue()
{
  int item;
  if (rear == n - 1)
  {
    printf("queue is full");
  }
  else
  {
    printf("enter the element to be added:");
    scanf("%d", &item);
    rear++;
    arr[rear] = item;
  }
  if (front == -1)
    front++;
}

//dequeue operation
void dequeue()
{
  int item;
  if (front == -1 && rear == -1)
  {
    printf("queue is empty");
  }
  else
  {
    item = arr[front];
    printf("deleted item %d", item);
  }
  {
    if (front == rear)
    {
      front = -1;
      rear = -1;
    }
  }
}

//display queue
void display()
{
  if (front == -1)
  {
    printf("queue empty\n");
  }
  else
  {
    for (int i = front; i < rear + 1; i++)
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
  printf("Enter 0 to exit\n");
  printf("Enter 1 for enqueue operation\n");
  printf("Enter 2 for dequeue operation\n");
  printf("Enter 3 to display\n");
  scanf("%d", &op);
  while (op)
  {
    if (op == 1)
      enqueue();
    else if (op == 2)
      dequeue();
    else if (op == 3)
      display();
    else
      exit(0);
    printf("enter the next operation\n");
    printf("Enter 0 to exit\n");
    printf("Enter 1 for enqueue operation\n");
    printf("Enter 2 for dequeue operation\n");
    printf("Enter 3 to display\n");
    scanf("%d", &op);
  }
}
