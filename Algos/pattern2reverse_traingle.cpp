#include<iostream>
using namespace std;
int main(){
    int i=0,j=0;
    int n;
    cout<<"enter the number : ";
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=n;j>=i;j--){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}