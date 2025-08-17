#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>adj[],int vis[],vector<int>&ls){
    vis[node]=1;
    ls.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}

vector<int>dfsofGraph(int V,vector<int>adj[]){
    int vis[V]={0};
    int start;
    cout<<"Enter the starting vertex : ";
    cin>>start;
    vector<int>ls;
    dfs(start,adj,vis,ls);
    return ls;
}

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V,a,b,E;
    cout<<"Enter number of vertices : ";
    cin>>V;
    vector<int>adj[5];
    cout<<"Enter number of edges : ";
    cin>>E;
    cout<<"Enter data : "<<endl;

    for(int i=0;i<E;i++){
        cin>>a;
        cin>>b;
        addEdge(adj,a,b);
    }
    vector<int>ans = dfsofGraph(V,adj);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"  ";
    }
    return 0;
}
