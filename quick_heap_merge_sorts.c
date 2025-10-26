#include<stdio.h>
#define MAX 10

void quick_sort(int a[],int start,int end){
    if(start<end){
        int pivot=a[start];
        int l=start,r=end;
        while(l<r){
            while((a[l]<=pivot)&&(l<=end)){
                l++;
            }
            while((a[r]>pivot)&&(l>=start)){
                r--;
            }
            if(l<r){
                int temp=a[l];
                a[l]=a[r];
                a[r]=temp;
            }
        }
        int temp=a[r];
        a[r]=a[start];
        a[start]=temp;
        quick_sort(a,start,r-1);
        quick_sort(a,r+1,end);
    }
    
}

void heapify(int a[],int i,int n){
    int largest=i;
    int l=2*i+1,r=2*i+2;
    if(l<=n-1 && a[l]>a[largest])
        largest=l;
    if(r<=n-1 && a[r]>a[largest])
        largest=r;
    if(largest!=i){
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,largest,n);
    }
}

void heap_sort(int a[],int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(a,i,n);
    for(int i=n-1;i>=1;i--){
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,0,i-1);
    }
}

void merge(int x[],int y[],int l,int m,int n){
    int i=l,j=m+1,k=l;
    while(i<=m && j<=n){
        if(x[i]<x[j]){
            y[k]=x[i];
            i++;
        }
        else{
            y[k]=x[j];
            j++;
        }
        k++;
    }
    if(i>m){
        for(int t=j;t<=n;t++){
            y[k]=x[t];
            k++;
        }
    }
    else{
        for(int t=i;t<=m;t++){
            y[k]=x[t];
            k++;
        }
    }
}

void mpass(int x[],int y[],int n,int l){
    int i=0;
    while(i<=n-2*l){
        merge(x,y,i,i+l-1,i+2*l-1);
        i=i+2*l;
    }
    if(i+l<n)
        merge(x,y,i,i+l-1,n-1);
    else{
        for(int t=i;t<=n;t++)
            y[t]=x[t];
    }
}

void merge_sort(int x[],int n){
    int y[MAX];
    int l=1;
    while(l<n){
        mpass(x,y,n,l);
        l=2*l;
        mpass(y,x,n,l);
        l=2*l;
    }
}


void main(){
    int quick[MAX], heap[MAX], merge[MAX];
    printf("Enter the array elements : \n");
    for(int i=0;i<MAX;i++){
        scanf("%d",&quick[i]);
        heap[i]=quick[i];
        merge[i]=quick[i];
    }

    printf("\nquick sort : \n--------------\n");
    quick_sort(quick,0,MAX-1);
    for(int i=0;i<MAX;i++){
        printf("%d ",quick[i]);
    }

    printf("\n\nheap sort : \n--------------\n");
    heap_sort(heap,MAX);
    for(int i=0;i<MAX;i++){
        printf("%d ",heap[i]);
    }

    printf("\n\nmerge sort : \n--------------\n");
    merge_sort(merge,MAX);
    for(int i=0;i<MAX;i++){
        printf("%d ",merge[i]);
    }
}

