#include<stdio.h>
#include<stdlib.h>
#define n 4

//creating circular queue
int arr[n];
int f=-1,r=-1;

//enqueue operation on circular queue
void cenqueue()
{   int item;
    if(f==(r+1)%n)
        {printf("queue full");
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

//dequeue operation on circular queue
void cdequeue()
{   int item;
    if(f==-1 && r==-1)
        {printf("queue empty\n");
         exit(0);
        }
    else
        {item=arr[f];
         printf("Deleted item:%d\n",item);
         if(f==r)
             {f=r=-1;}
         else
             {f=(f+1)%n;}
        }    
}        

//displaying circular queue elements
void cdisplay()
{   if(f==-1 && r==-1)
        {printf("Queue Empty\n");
         exit(0);
        }
    else
        {int i=f;
         while(i!=r)
             {printf("%d\n",arr[i]);
              i=(i+1)%n;
             }
         printf("%d\n",arr[r]);
        }
}

//menu driven main function
void main()
{ int op;
  printf("enter the operation\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\n");
  scanf("%d",&op);
  while(op)
     {if (op==1)
        cenqueue();
      else if (op==2)
        cdequeue();
      else if (op==3)
        cdisplay();
      else
        exit(0);
       printf("enter the next operation\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\n");
       scanf("%d",&op);}
}
                             
           
