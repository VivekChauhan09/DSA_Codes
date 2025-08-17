#include<iostream>
using namespace std;
int main(){
    int i=0,j=0,k=0;
    int n;
    for(i=0;i<5;i++){
        for(j=5-1;j>=5-i;j--){
            cout<<" ";
        }
        for(j=0;j<5-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
