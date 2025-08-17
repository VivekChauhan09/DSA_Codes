#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

void act(vector<pair<int,int>>&activities){
    sort(activities.begin(),activities.end(),compare);
    int j=1,count=0;
    for(int i=0;i<activities.size();i++){
        cout<<activities[i].first<<"    "<<activities[i].second<<endl;
    }
    // int  et=activities[0].second;
    // while(j<activities.size()){
    //     if(activities[j].first>=et){
    //         count++;
    //         et=activities[j].second;
    //     }
    //     j++;
    // }
    // return count++;
}

int main(){
    int n;
    cout<<"Enter number of activities : ";
    cin>>n;
    vector<pair<int,int>>activities(n);
    for(int i=0;i<n;i++){
        cin>>activities[i].first>>activities[i].second;
    }
    act(activities);

    return 0;

}