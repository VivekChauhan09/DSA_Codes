#include<iostream>
using namespace std;
int main()
{
    int i=1;
    for(i=0;i<6;i++){
        cout<<i<<" ";
    }
    
    cout<<endl;
    while(i<12){
        cout<<i<<" ";
        i++;
    }

    cout<<endl;
    do{
        cout<<i<<" ";
        i++;
    }while(i<17);

    return 0;
}

