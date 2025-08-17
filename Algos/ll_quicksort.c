#include<stdio.h>
#include<stdlib.h>

void swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}

int partition(char arr[],int low,int high){
    char pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quicksort(char arr[],int low , int high){
    if(low<high){
        int p=partition(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}

int main(){
    int n;
    printf("Enter the number of characters to insert : ");
    scanf("%d",&n);
    char arr[n];
    for(int i=0;i<n;i++){
        scanf(" %c",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("Sorted array is ");
    for(int i=0;i<n;i++){
        printf("%c ",arr[i]);
    }
    return 0;

}