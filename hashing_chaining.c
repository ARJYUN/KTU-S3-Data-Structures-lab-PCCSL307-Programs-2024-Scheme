#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct Node{
    int data;
    struct Node*next;
};

struct Node*hashTable[SIZE];

int hash(int key){
    return key%SIZE;
}

void insert(int key){
    int index=hash(key);
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=key;
    newNode->next=NULL;

    if(hashTable[index]==NULL)
        hashTable[index]=newNode;
    else{
        struct Node*temp=hashTable[index];
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }
    printf("Inserted %d at index %d\n",key,index);
}

void search(int key){
    int index=hash(key);
    struct Node*temp=hashTable[index];
    while(temp!=NULL){
        if(temp->data==key){
            printf("Element %d found at index %d\n",key,index);
            return;
        }
        temp=temp->next;
    }
    printf("Element %d not found\n",key);
}

void display(){
    printf("\nHash Table:\n");
    for(int i=0;i<SIZE;i++){
        printf("Index %d: ",i);
        struct Node*temp=hashTable[i];
        if(temp==NULL)
            printf("NULL");
        else{
            while(temp!=NULL){
                printf("%d -> ",temp->data);
                temp=temp->next;
            }
            printf("NULL");
        }
        printf("\n");
    }
}

void main(){
    int choice,key;
    for(int i=0;i<SIZE;i++)
        hashTable[i]=NULL;
    while(1){
        printf("\n--- Hashing using Chaining ---\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter key to insert: ");
                scanf("%d",&key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d",&key);
                search(key);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
