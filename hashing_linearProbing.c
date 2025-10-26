#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int hashTable[SIZE];

int h(int key){
    return key%SIZE;
}

void insert(int key){
    int index=h(key);
    int start=index;
    while(hashTable[index]!=-1){
        index=(index+1)%SIZE;
        if(index==start){
            printf("Hash table is full!\n");
            return;
        }
    }
    hashTable[index]=key;
    printf("Inserted %d at index %d\n",key,index);
}

void search(int key){
    int index=h(key);
    int start=index;
    while(hashTable[index]!=-1){
        if(hashTable[index]==key){
            printf("Element %d found at index %d\n",key,index);
            return;
        }
        index=(index+1)%SIZE;
        if(index==start)
            break;
    }
    printf("Element %d not found\n",key);
}

void display(){
    printf("\nHash Table:\n");
    for(int i=0;i<SIZE;i++){
        if(hashTable[i]!=-1)
            printf("Index %d -> %d\n",i,hashTable[i]);
        else
            printf("Index %d -> NULL\n",i);
    }
}

void main(){
    int choice,key;
    for(int i=0;i<SIZE;i++)
        hashTable[i]=-1;
    while(1){
        printf("\nHashing using Linear Probing \n");
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
