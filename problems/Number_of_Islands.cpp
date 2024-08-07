//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

    void bfs(int row,int col,vector<vector<int>> &visited,
    vector<vector<char>>& grid,int n,int m){
        visited[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();
            for(int delr=-1;delr<=1;delr++){
                for(int delc=-1;delc<=1;delc++){
                    int nrow= row+delr;
                    int ncol= col+delc;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                            visited[nrow][ncol]=1;
                            q.push({nrow,ncol});
                    }
                }
            }
        }

    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int count=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]=='1' 
                && !visited[row][col]){
                    bfs(row,col,visited,grid,n,m);
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends