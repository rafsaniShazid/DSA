class Solution
{
    private:
    void dfs(int node,vector<int>adj[],vector<bool>&vis,stack<int>&st)
    {
        vis[node]=1;
        for(int neighbour:adj[node])
        {
            if(!vis[neighbour])
            {
                dfs(neighbour,adj,vis,st);                
            }
            
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>vis(V+1,0);
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	            
	            }
	    }
	vector<int> ans;
	while(!st.empty())
	{
	    ans.push_back(st.top());
	    st.pop();
	}
	return ans;
	}

};