#include<iostream>
using namespace std;
int main(){
    int i=0,j=0;
    int n;
    cout<<"enter the limit of pattern:";
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}