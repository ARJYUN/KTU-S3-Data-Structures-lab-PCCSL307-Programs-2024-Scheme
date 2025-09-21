#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[20];
    int priority;
    struct node *link;
};

struct node *front = NULL;

// adding a customer based on priority
void enqueue()
{
    int p;
    char n[20];
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the name : ");
    scanf("%s", n);
    printf("Enter the priority : ");
    scanf("%d", &p);
    strcpy(new->name, n);
    new->priority = p;
    new->link = NULL;
    if (front == NULL || front->priority < p)
    {
        new->link = front;
        front = new;
    }
    else
    {
        struct node *ptr = front;
        while (ptr->link != NULL && ptr->link->priority >= p)
        {
            ptr = ptr->link;
        }
        new->link = ptr->link;
        ptr->link = new;
    }
}

// serving customer
void dequeue()
{
    if (front == NULL)
    {
        printf("\nNo Customers !! ");
        return;
    }
    struct node *ptr = front;
    front = front->link;
    free(ptr);
}

// display customers in the priority queue
void display()
{
    if (front == NULL)
    {
        printf("\nNo Customers !!\n");
        return;
    }
    struct node *ptr = front;
    while (ptr != NULL)
    {
        printf("%s(%d)->", ptr->name, ptr->priority);
        ptr = ptr->link;
    }
}

// main function
void main()
{
    int c;
    printf("Welcome to Post Office Customer Simulation");
    printf("\n1.Add Customer\n2.Serve Customer\n3.Current Status\n4.Exit");
    do
    {
        printf("\nEnter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {
            enqueue();
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("\nExiting");
            return;
        }

        default:
        {
            printf("\nInvalid Choice ");
            break;
        }
        }
    } while (c != 4);
}