#include<iostream>
#include<stack>
using namespace std;
int prec(char a){
    switch (a){
        case '-' :return 1;
        case '+' :return 1;
        case '*' :return 2;
        case '/' :return 2;
        case '(' :return 0;
    }
}
int main(){
    stack<char> st;
    string s="a+b/)c-d*e";
    string ans=" ";
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]>='a'&&s[i]<='z'){
            ans+=s[i];
        }
        else{
            if(st.empty()||s[i]=='(')
                st.push(s[i]);
            else{
                if(s[i]==')'){
                    while(st.top()!='('){
                        ans+=st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else{
                    while(!st.empty()&&(prec(s[i]))<=prec(st.top())){
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout<<ans<<endl;
    return 0;
}