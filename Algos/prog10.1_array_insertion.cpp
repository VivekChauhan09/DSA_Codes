#include<iostream>
using namespace std;
int main(){
    int n,i=0,j=0;
    cout<<"enter the number of elements : ";
    cin>>n;
    int arr[n+1];
    cout<<"enter the elements : ";
    for(i=0;i<n;i++){
        cout<<arr[i];
    }
    int key,index;
    cout<<"enter the element to insert : ";
    cin>>key;
    cout<<"enter the index where u want to enter the element : ";
    cin>>index;
    for(i=n;i<=index;i--){
        arr[i+1]=arr[i];
    }
    arr[i]=key;
    for(i=0;i<n+1;i++){
        cout<<arr[i];   
    }    
    return 0;
}