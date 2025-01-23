//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
  void dfs(vector<vector<int>>&adj,vector<int>&res,int node, vector<int>&vis){
     res.push_back(node);
    //  vis[node]=1;
     for(int i=0;i<adj[node].size();i++){
         if(!vis[adj[node][i]]){
             vis[adj[node][i]]=1;
             dfs(adj,res,adj[node][i],vis);
         }
     }
  }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        vector<int>vis(adj.size(),0);
        vis[0]=1;
        vector<int>res;
        dfs(adj,res,0,vis);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends