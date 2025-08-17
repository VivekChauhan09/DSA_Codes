#include<iostream>
using namespace std;
int main()
{
    int matrix[3][3];
    int i,j;
    cout<<endl;
    cout<<"enter the numbers for matrix"<<endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"----THE MATRIX----"<<endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}