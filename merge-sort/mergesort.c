#include<stdio.h>

void merge(int arr[],int left,int mid,int right){
    int left_length= mid-left+1;
    int right_length=right-mid;

    int L[100],R[100];

    for(int i=0;i<left_length;i++){
        L[i]=arr[left+i];
    }
    for(int j=0;j<right_length;j++){
        R[j]=arr[mid+j+1];
    }
    int i=0,j=0,k=left;
    

    while(i<left_length && j<right_length){
        if(L[i]<R[j]){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
    }

    while(i<left_length){
        arr[k++]=L[i++];
    }
    while (j<right_length)
    {
      arr[k++]=R[j++];
    }
    
    

}

void mergesort(int arr[],int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    

}

int main(){
    int n,arr[100];
    printf("Enter the no.of elements:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter the %d th element",i+1);
        scanf("%d",&arr[i]);
    }

    printf("sorted array:\n");
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
