#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class graph{
    int v;
    vector<list<int>>adj;
public:
    graph(int V):v(V){adj.resize(V);}

    void readGraph(int E){
        cout<<"Enter the edges \n";
        for(int i=0;i<E;i++)
        {
            int v,e;
            cin>>v>>e;
            adj[v].push_back(e);
            adj[e].push_back(v);
        }
    }
    void bfs(int s){
        vector<bool> visited;
        visited.resize(v,false);
        visited[s]=true;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int node= q.front();
            cout<<node<<" ";
            q.pop();
            for(auto adjacency: adj[node])
            {
                if(!visited[adjacency]){
                    visited[adjacency]=true;                   
                    q.push(adjacency);
                    }
            }
        }
    }
};

int main()
{
std::ios_base::sync_with_stdio(false);
    cout<<"Enter number of vertices and edges \n";
    int V,E; cin>>V>>E;
    graph graph(V);
    graph.readGraph(E);
    graph.bfs(5);
    return 0;
}