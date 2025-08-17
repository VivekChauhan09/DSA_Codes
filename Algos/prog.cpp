#include<bits/stdc++.h> 
#include<iostream> 
using namespace std; 
 
int findMajority(vector<int>nums){ 
    sort(nums.begin(),nums.end()); 
    int n=nums.size(),elem=nums[n/2],freq=0; 
    double median; 
    if(n%2==1) 
        median=nums[n/2]; 
    else  
        median=((double)nums[n/2]+nums[n/2-1])/2; 
    for(int i=0;i<n;i++){ 
        if(nums[i]==elem) 
        freq++; 
    } 
    cout<<"\nOUTPUT:\n"; 
    if(freq>n/2)
        cout<<"Yes"<<endl; 
    else 
        cout<<"No"<<endl; 
    cout<<median; 
} 
int main(){ 
    int n=0; 
    cin>>n; 
    vector<int>nums(n,0); 
    for(int i=0;i<n;i++)cin>>nums[i]; 
    findMajority(nums); 
} 