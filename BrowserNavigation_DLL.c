#include<stdio.h>
#include<stdlib.h>
struct page{
    char url[50];
    struct page *next;
    struct page *prev;
};
typedef struct page page;
page *current=NULL;

//visit new site
void visitNew(){
    page *new=(page*)malloc(sizeof(page));
    printf("Enter the url: ");
    scanf("%s",new->url);
    new->prev=NULL;
    new->next=NULL;
    if(current!=NULL){
        current->next=new;
        new->prev=current;
    }
    current=new;
}

//go back
void back(){
    if(current->prev==NULL){
        printf("No previous page available !\n");
        return;
    }
    current=current->prev;
    printf("Went back to: %s\n",current->url);
}

//go forward
void forward(){
    if(current->next==NULL){
        printf("No next page available !\n");
        return;
    }
    current=current->next;
    printf("Went forward to: %s\n",current->url);
}

//view current page
void view(){
    if(current==NULL){
        printf("No page visited !\n");
        return;
    }
    printf("Current page is: %s\n",current->url);
}

//main function
void main(){
    int c;
    printf("Browser Navigation Simulation\n-----------------------------");
    do{
        printf("\n1. Visit New Page\n2. Go Back\n3. Go Forward\n4. View Current Page\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&c);
        switch(c){
            case 1:
                visitNew();
                break;
            case 2:
                back();
                break;
            case 3:
                forward();
                break;
            case 4:
                view();
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice !");
            }
    }while(c!=5);
}