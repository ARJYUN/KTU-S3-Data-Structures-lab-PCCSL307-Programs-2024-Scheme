#include<stdio.h>
#include<stdlib.h>
#define n 4

//creating double ended queue(deque)
int arr[n];
int f=-1,r=-1;

//enqueue operation at front
void enqueue_front()
{   int item;
    if(f==(r+1)||(f==0 && r==(n-1)))
       {printf("Queue full");
         exit(0);
       }
    else
       {printf("Enter the element:");
        scanf("%d",&item);
        if(f==0)
           {f=n-1;}
        else if (f==-1)
           {f++;
            r++;
            }
        else
           {f=f-1;}
       }
    arr[f]=item;   
}

//enqueue operation at rear
void enqueue_rear()
{   int item;
    if(f==(r+1)%n)
       {printf("Queue full");
         exit(0);
       }
    else
       {printf("Enter the element:");
        scanf("%d",&item);
        r=(r+1)%n;
        arr[r]=item;
        if(f==-1)
           {f=f+1;}
       }
}

//dequeue operation at front
void dequeue_front()
{int item;
 if(f==-1 && r==-1)
    {printf("Queue empty");
     exit(0);
    }
 else
    {item=arr[f];
     printf("Deleted element:%d\n",item);
     if(f==r)
        {f=r=-1;}
     else
        {f=(f+1)%n;}
    }
}

//dequeue operation at rear
void dequeue_rear()
{int item;
 if(f==-1 && r==-1)
    {printf("Queue empty");
     exit(0);
    }
 else
    {if(r==0)
        {r=n-1;
         printf("deleted element:%d\n",arr[r]);
        }
     else
        {r=r-1;
         printf("deleted element:%d\n",arr[r]);
        }    
    }
}

//displaying elements in deque
void display_dq()
{   if(f==-1 && r==-1)
        {printf("Queue Empty\n");
         exit(0);
        }
    else
        {int i=f;
         while(i!=r)
             {printf("   %d",arr[i]);
              i=(i+1)%n;
             }
         printf("   %d\n",arr[r]);
        }
}

//menu driven main function
void main()
{ int op;
  int op1,op2;
  printf("enter the operation\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\n");
  printf("Enter your choice:");
  scanf("%d",&op);
  while(op)
    {if (op==1)
       {printf("1.Enqueue front\n2.Enqueue rear\n");
        scanf("%d",&op1);
        switch(op1)
           {case 1:
              enqueue_front();
              break;
            case 2:
              enqueue_rear();
              break;
            default: 
              printf("invalid operation\n");
            }
        }
    else if (op==2)
       {printf("1.Dequeue front\n2.Dequeue rear\n");
        scanf("%d",&op2);
        switch(op2)
           {case 1:
              dequeue_front();
              break;
            case 2:
              dequeue_rear();
              break;
            default:
              printf("invalid operation\n");
            }
        }
    else if (op==3)
        display_dq();
    else
        exit(0);
       printf("enter the next operation\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\n");
       printf("Enter your choice:");
       scanf("%d",&op);
       }
}
