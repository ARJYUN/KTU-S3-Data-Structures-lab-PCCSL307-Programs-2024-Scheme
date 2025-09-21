#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *front = NULL, *rear = NULL, *header = NULL;

// enqueue operation
void enqueue()
{
    int item;
    printf("Enter the data : ");
    scanf("%d", &item);
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *ref = (struct node *)malloc(sizeof(struct node));
    header = ref;
    new->data = item;
    new->link = NULL;
    if (front == NULL && rear == NULL)
    {
        front = new;
        rear = new;
    }
    else
    {
        rear->link = new;
    }
    rear = new;
    rear->link = header;
    header->link = front;
}

// dequeue operation
void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("\nEmpty List !! ");
        return;
    }
    struct node *ptr = front;
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
        header->link = NULL;
    }
    else
    {
        front = front->link;
        header->link = front;
    }
    free(ptr);
}

// display elements
void display()
{
    if (front == NULL)
    {
        printf("\nEmpty list\n");
        return;
    }
    struct node *ptr = front;
    while (ptr != header)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
}

// main function
void main()
{
    int c;
    printf("Circular Linked List");
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
    do
    {
        printf("\nEnter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return;

        default:
            printf("\nInvalid Choice ");
            break;
        }
    } while (c != 4);
}