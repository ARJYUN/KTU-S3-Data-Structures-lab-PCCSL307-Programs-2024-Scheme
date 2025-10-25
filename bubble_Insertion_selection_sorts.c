#include<stdio.h>
#define MAX 10

void bubble_sort(int arr[MAX]){
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

void insertion_sort(int arr[MAX]){
    int temp,j;
    for(int i=1;i<=MAX-1;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}


void selection_sort(int arr[MAX]){
    int min, ind,temp;
    for(int i=0;i<MAX-1;i++){
        min=arr[i];
        ind=i;
        for(int j=i+1;j<=MAX-1;j++){
            if(arr[j]<min){
                min=arr[j];
                ind=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[ind];
        arr[ind]=temp;
    }
}
 
void main(){
    int bubble[MAX], selection[MAX], insertion[MAX];
    printf("Enter the array elements : \n");
    for(int i=0;i<MAX;i++){
        scanf("%d",&bubble[i]);
        selection[i]=bubble[i];
        insertion[i]=bubble[i];
    }

    printf("\nBubble sort : \n--------------\n");
    bubble_sort(bubble);
    for(int i=0;i<MAX;i++){
        printf("%d ",bubble[i]);
    }

    printf("\n\nInsertion sort : \n--------------\n");
    insertion_sort(insertion);
    for(int i=0;i<MAX;i++){
        printf("%d ",insertion[i]);
    }

    printf("\n\nSelection sort : \n--------------\n");
    selection_sort(selection);
    for(int i=0;i<MAX;i++){
        printf("%d ",selection[i]);
    }
    
}