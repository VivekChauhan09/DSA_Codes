    #include<bits/stdc++.h>
    using namespace std;

    void computeLPS(string patt,int n,vector<int>&lps){
        int i=1;
        int len=0;
        lps[0]=0;
        while(i<n){
            if(patt[i]==patt[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    len=lps[len-1];
                }
            }
        }
    }

    vector<int>KMP(string text,string patt,int m,int n,vector<int>&lps){
        int i=0,j=0;
        vector<int>sol;
        while(i<m){
            if(text[i]==patt[j]){
                i++;
                j++;
            }
            if(j==n){
                sol.push_back(i-j);
                j=lps[j-1];
            } 
            else if (text[i]!=patt[j]){
                if(j!=0){
                    j=lps[j-1];
                }
                else
                    i++;
            }
            
        }
        return sol;
    }

    int main(){
        string text;
        string patt;
        cin>>text;
        cin>>patt;

        int m=text.size();
        int n=patt.size();

        vector<int>lps(n);

        computeLPS(patt,n,lps);

        vector<int>ans=KMP(text,patt,m,n,lps);
        
        int count=0;
        for(int i:ans)
            count++;
        
        cout<<count;
        return 0;
    }
