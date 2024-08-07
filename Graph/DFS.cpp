#include<bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>>&v,vector<bool>&vis,int s)
{
    if(vis[s]==0){
        vis[s]=1; cout<<s<<" ";
    } 
    for(auto neighbour:v[s])
    {
        if(vis[neighbour]==0){
            vis[neighbour]=1;
            DFS(v,vis,neighbour);
        }
    }
}
int main()
{
    cout<<"Enter number of vertices and edges\n";
    int V,E; cin>>V>>E;
    vector<vector<int>> graph(V);
    for(int i=0;i<E;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> visited(V,0);
    DFS(graph,visited,0);
    return 0;
}