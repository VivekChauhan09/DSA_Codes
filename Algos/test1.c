#include<bits/stdc++.h>
using namespace std;

string removeStars(string str){
    int len=str.length();
    stack<char>st;
    string ans="";
    for(int i=0;i<len;i++){
        if(!st.empty()&&str[i]=='*')
            st.pop();
        else
            st.push(str[i]);
    }
    while(!st.empty()){
        ans=st.top()+ans;
    }
    return ans;
}

int main(){
    string str;
    cin>>str;
    cout<<removeStars(str);
    return 0;
}