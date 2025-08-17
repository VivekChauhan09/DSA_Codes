#include<bits/stdc++.h>
#include<iostream> 
using namespace std; 
void findElementSumEqualToK(vector<int>nums,int k){ 
    sort(nums.begin(),nums.end()); 
    int i=0,j=nums.size()-1; 
    while(i<j){ 
        if(nums[i]+nums[j]==k){ 
 
            cout<<"Output : "<<nums[i]<<" "<<nums[j]<<endl; 
            return ; 
        } 
        else if(nums[i]+nums[j]<k)i++; 
        else j--; 
    } 
    cout<<"Output:"<<"No Such Element Exist."<<endl; 
} 
 
int main(){ 
    int t,n=0,k=0; 
    cin>>t; 
    while(t){ 
        t--; 
        cin>>n; 
        vector<int>nums(n,0); 
        for(int i=0;i<n;i++){ 
            cin>>nums[i]; 
        } 
        cin>>k; 
        findElementSumEqualToK(nums,k); 
    } 
     
}  