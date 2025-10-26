#include<stdio.h>
#define MAX 10

int key,arr[MAX];

void linearSearch(){
    printf("\nEnter the elements you are searching for : ");
    scanf("%d",&key);
    int found=0,ind;
    for(int i=0;i<MAX;i++){
        if(key==arr[i]){
            found=1;
            ind=i;
            break;
        }
    }
    if(!found){
        printf("\nKey not found");
    }
    else{
        printf("\nKey found at index %d ",ind);
    }
}

void sort(){
    for(int i=0;i<MAX-1;i++){
        for(int j=0;j<MAX-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void binarySearch(){
    printf("\nEnter the elements you are searching for : ");
    scanf("%d",&key);
    sort();
    printf("\nSorted Array : \n--------------");
    for(int i=0;i<MAX;i++){
        printf("%d ",arr[i]);
    }
    int beg=arr[0],end=arr[MAX-1],found=0,ind;
    int mid;
    while(found==0 && beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]>key){
            end=mid-1;
        }else if(arr[mid]<key){
            beg=mid+1;
        }
        else{
            found=1;
            ind=mid;
        }
    }
    if(found){
        printf("\nKey found at index %d ",ind);
    }
    else{
        printf("\nKey not found");
    }
}



void main(){
    printf("Enter the array elements : \n");
    for(int i=0;i<MAX;i++){
        scanf("%d",&arr[i]);
    }
    printf("Linear Search : \n--------------");
    linearSearch();
    printf("\nBinary Search : \n--------------");
    binarySearch();
}
