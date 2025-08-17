#include<iostream>
#include<string>
using namespace std;
void rev(char *str){
    int i=0,j,len=0;
    char temp;
    while(*(str+i)!='\0'){
        len++;
        i++;
    }
    j=len-1;
    for(i=0;i<len/2;i++){
        temp=*(str+i);
        *(str+i)=*(str+j);
        *(str+j)=temp;
        j--;
    }
}
int main(){
    char str[100];
    cout<<"enter the string ";
    cin>>str;
    rev(str);
    cout<<str;
    return 0;
}