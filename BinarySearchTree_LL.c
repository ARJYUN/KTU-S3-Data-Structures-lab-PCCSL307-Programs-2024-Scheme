#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lc,*rc;
};

struct node *root=NULL;

//insert node
void insert(int item){
    struct node *p;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    if(root==NULL){
        root=new;
        return;
    }
    p=root;
    struct node *par=NULL;
    while(p!=NULL){
        par=p;
        if(item<p->data){
            p=p->lc;
        }
        else if(item>p->data){
            p=p->rc;
        }
        else{
            printf("\nValue already exists !");
            return;
        }
    }
    if(item<par->data)
        par->lc=new;
    else
        par->rc=new;
}

//inorder traversal
void inorder(struct node *p){
    if(p!=NULL){
        inorder(p->lc);
        printf("%d ",p->data);
        inorder(p->rc);
    }
    return;
}

//postorder traversal
void postorder(struct node *p){
    if(p!=NULL){
        postorder(p->lc);
        postorder(p->rc);
        printf("%d ",p->data);
    }
    return;
}

//preorder traversal
void preorder(struct node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        preorder(p->lc);
        preorder(p->rc);
    }
    return;
}

//to find inorder successor of a node
struct node* inorder_succ(struct node *p){
    struct node *ptr;
    if(p->rc!=NULL)
        ptr=p->rc;
    while(ptr->lc!=NULL){
        ptr=ptr->lc;
    }
    return ptr;
}

//delete node
void delete(int item){
    struct node *p=root;
    struct node *par=NULL;
    int found=0,c;
    while(p!=NULL && found==0){
        if(item<p->data){
            par=p;
            p=p->lc;
        }
        else if(item>p->data){
            par=p;
            p=p->rc;
        }
        else    
            found=1;
    }
    if(p==NULL){
        printf("Deletion not possible: ");
        return;
    }
    if(p->lc==NULL && p->rc==NULL){
        c=1;
    }
    else if(p->lc!=NULL && p->rc!=NULL){
        c=3;
    }
    else{
        c=2;
    }
    if(c==1){
        if(p==par->lc)
            par->lc=NULL;
        else
            par->rc=NULL;
        free(p);
    }
    if(c==2){
        if(p==par->lc){
            if(p->lc!=NULL){
                par->lc=p->lc;
            }
            else{
                par->lc=p->rc;
            }
        }
        else if(p==par->rc){
            if(p->lc!=NULL){
                par->rc=p->lc;
            }
            else{
                par->rc=p->rc;
            }
        }
        free(p);
    }
    if(c==3){
        struct node *ptr=inorder_succ(p);
        int temp=ptr->data;
        delete(temp);
        p->data=temp;
    }

}

//main function
void main(){
    int c,item;
    struct node *p;
    printf("BST OPERATIONS\n--------------\n1.Insert\n2.Delete\n3.Traverse Inorder\n4. Traverse Post Order\n5. Traverse Pre Order\n6. Exit");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("\nEnter the item you want insert : ");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                printf("\nEnter the item you want delete : ");
                scanf("%d",&item);
                delete(item);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                preorder(root);
                break;
            case 6:
                printf("\nExiting.....");
                break;
            default:
                printf("Invalid Choice !");
        }
    }while(c!=6);
}