#include<bits/stdc++.h>
using namespace std;
bool dfs(int source,vector<bool>&vis,
int parent,vector<vector<int>>&adj)
{
    vis[source]=1;
    for(auto it:adj[source])
    {
        if(!vis[it])
        {
            if(dfs(it,vis,source,adj)== true) return true;
        }
        else if(it!=parent) return true;
    }
    return false;
}


bool isCycle(int vertices,vector<vector<int>>&adj){
    vector<bool> vis(vertices,0);
    for(int i=0;i<vertices;i++){
        if(!vis[i]){
            if(dfs(i,vis,-1,adj)==true) return true;
        } 
    }
    return  false;
}

int main()
{
    cout<<"Enter number of edges and vertices\n";
    int E,V; cin>>E>>V;
    vector<vector<int>>adj(V+1);
    for(int i=0;i<E;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<isCycle(V,adj);
    return 0;
}