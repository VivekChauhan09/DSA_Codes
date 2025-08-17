#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>&a,pair<int,int>&b){
    return a.second>b.second;
}

int jobSequencing(vector<pair<int,int>>&jobs,int n){
    sort(jobs.begin(),jobs.end(),compare);

    int maxDeadline=0;
    for(int i=0;i<n;i++){
        if(jobs[i].first>=maxDeadline){
            maxDeadline=jobs[i].first;
        }
    }

    vector<int>scjobs(maxDeadline+1,0);
    int profit=0;

    for(int j=0;j<n;j++){
        int d=jobs[j].first;
        if(scjobs[d]==0){
            scjobs[d]=1;
            profit=profit+jobs[j].second;
        }
        else{
            while(d>0 && scjobs[d]==1){
                d--;
            }
            if(d!=0){
                scjobs[d]=1;
                profit=profit+jobs[j].second;
            }
        }
    }
    return profit;
}

int main(){
    int n;
    cout<<"Enter number of jobs : ";
    cin>>n;
    vector<pair<int,int>>jobs(n);
    for(int i=0;i<n;i++){
        cin>>jobs[i].first>>jobs[i].second;
    } 
    int ans=jobSequencing(jobs,n);
    cout<<ans;
    return 0;
}
