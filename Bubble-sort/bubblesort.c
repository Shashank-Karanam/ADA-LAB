#include<stdio.h>

void bubblesort(int arr[],int n){
    int temp;
    for(int i=0; i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int a,n;
    int arr[100];
    printf("Enter the no. of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the %d th element:",i+1);
        scanf("%d",&a);
        arr[i]=a;
    }
    bubblesort(arr,n);
    printf("The sorted arr:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}
