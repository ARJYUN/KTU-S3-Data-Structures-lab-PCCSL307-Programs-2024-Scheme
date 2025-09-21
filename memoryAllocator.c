#include<stdio.h>
#include<stdlib.h>
struct block{
    int id;
    int start_address;
    int size;
    int used;
    struct block *next;
    struct block *prev;
};
typedef struct block block;
block *head=NULL,*end=NULL;

//add memory block
void add_block(int s,int i){
    int start_add;
    block *new=(block*)malloc(sizeof(block));
    printf("Enter the starting Address: ");
    scanf("%d",&start_add);
    new->next=NULL;
    new->prev=NULL;
    new->start_address=start_add;
    new->size=s;
    new->id=i;
    if(head==NULL){
        head=new;
        end=new;}
    else{
        end->next=new;
        new->prev=end;
        end=new;
    }
}

//first fit
void first_fit(){
    int processSize;
    printf("Enter process size: ");
    scanf("%d",&processSize);
    block *ptr=head;
    while(ptr!=NULL){
        if(ptr->size==processSize){
            printf("Perfectly fit on block %d, deleted block %d",ptr->id,ptr->id);
            if(ptr->prev==NULL){
                head=head->next;
                head->prev=NULL;
            }
            else if(ptr->next==NULL){
                (ptr->prev)->next=NULL;
            }
            else{
                (ptr->prev)->next=ptr->next;
                (ptr->next)->prev=ptr->prev;
            }
            free(ptr);
            return;
        }
        else if(ptr->size>processSize){
            ptr->start_address+=processSize;
            ptr->size-=processSize;
            printf("Process allocated to block %d. Remaining size in block %d is %d.",ptr->id,ptr->id,ptr->size);
            return;
        }
        ptr=ptr->next;
    }
    printf("\nNo No suitable block found for size %d(First Fit).\n", processSize);
}

//best fit
void best_fit(){
    int processSize;
    printf("Enter process size: ");
    scanf("%d",&processSize);
    block *ptr=head,*best=NULL;
    while(ptr!=NULL){
        if(ptr->size>=processSize) {
            if(best== NULL||ptr->size<best->size)
                best=ptr;
        }
        ptr=ptr->next;
    }
    if(best!=NULL){
        if(best->size==processSize){
            printf("Perfectly fit on block %d, deleted block %d",best->id,best->id);
            if(best->prev==NULL){
                head=head->next;
                head->prev=NULL;
            }
            else if(best->next==NULL){
                (best->prev)->next=NULL;
            }
            else{
                (best->prev)->next=best->next;
                (best->next)->prev=best->prev;
            }
            free(best);
            return;
        }
        else{
            best->start_address+=processSize;
            best->size-=processSize;
            printf("Process allocated to Block %d using Best Fit. \nRemaining size in block %d is %d\n", best->id,best->id,best->size);
        }
    }else{
        printf("No suitable block found for size %d(Best Fit).\n", processSize);
    }
}

//worst fit
void worst_fit(){
    int processSize;
    printf("Enter process size: ");
    scanf("%d",&processSize);
    block *ptr=head,*worst=NULL;
    while(ptr!=NULL){
        if(ptr->size>=processSize) {
            if(worst== NULL||ptr->size>worst->size)
                worst=ptr;
        }
        ptr=ptr->next;
    }
    if(worst!=NULL){
        if(worst->size==processSize){
            printf("Perfectly fit on block %d, deleted block %d",worst->id,worst->id);
            if(worst->prev==NULL){
                head=head->next;
                head->prev=NULL;
            }
            else if(worst->next==NULL){
                (worst->prev)->next=NULL;
            }
            else{
                (worst->prev)->next=worst->next;
                (worst->next)->prev=worst->prev;
            }
            free(worst);
            return;
        }
        else{
            worst->start_address+=processSize;
            worst->size-=processSize;
            printf("Process allocated to Block %d using worst Fit. \nRemaining size in block %d is %d\n", worst->id,worst->id,worst->size);
        }
    }else{
        printf("No suitable block found for size %d(worst Fit).\n", processSize);
    }
}

//print memory
void print_memory(){
    block *ptr=head;
    printf("\nMemory State:\n");
    printf("ID\tSize\tStarting Address\n");
    while (ptr!=NULL) {
        printf("%d\t%d\t%d\n", ptr->id, ptr->size,ptr->start_address);
        ptr=ptr->next;
    }
}

//main function
void main(){
    int n,size,c;
    printf("Enter no. of memory blocks: ");
    scanf("%d",&n);
    printf("Enter sizes of each block:\n");
    for(int i=1;i<=n;i++){
        scanf("%d",&size);
        add_block(size,i);
    }
    do{
        printf("\nMemory Allocator Menu\n---------------------");
        printf("\n1. First Fit Allocation\n2. Best Fit Allocation\n3. Worst Fit Allocation\n4. Show Memory State\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c){
            case 1:
                first_fit();
                break;
            case 2:
                best_fit();
                break;
            case 3:
                worst_fit();
                break;
            case 4:
                print_memory();
                break;
            case 5:
                printf("Exiting....");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }while(c!=5);
}