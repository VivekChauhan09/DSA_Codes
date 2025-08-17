#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
}

int ActSel(vector<pair<int,int>>&activities){
    sort(activities.begin(),activities.end(),comp);
    int et=activities[0].second;
    int j=1,count=1;
    while(j<activities.size()){
        if(activities[j].first>=et){
            count++;
            et=activities[j].second;
        }
        j++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> activities(n);
    for(int i=0;i<n;i++){
        cin>>activities[i].first>>activities[i].second;
    }
    int ans = ActSel(activities);
    cout<<ans;
    return 0;
}