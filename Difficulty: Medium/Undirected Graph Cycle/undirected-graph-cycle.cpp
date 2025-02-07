//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here 
    //     vector<int> vis(adj.size(), 0);
    // queue<pair<int, int>> q;
    // int n = adj.size();
    
    // for (int i = 0; i < n; i++) {
    //     if (vis[i] == 0) {
    //         q.push({i, -1});  // Push the node with parent -1
    //         vis[i] = 1;  // Mark as visited

    //         while (!q.empty()) {
    //             auto ele = q.front();
    //             q.pop();
    //             int node = ele.first;
    //             int parent = ele.second;

    //             for (int neighbor : adj[node]) {
    //                 if (!vis[neighbor]) {  // If not visited
    //                     vis[neighbor] = 1;
    //                     q.push({neighbor, node});
    //                 } else if (neighbor != parent) {
    //                     return true;  // Cycle detected
    //                 }
    //             }
    //         }
    //     }
    // }
    // return false;
    
        vector<int>vis(adj.size(),0);
        queue<pair<int,int>>q;
        int n=adj.size();
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i]=1;
                q.push({i,-1});
                while(!q.empty()){
                  auto ele=q.front();
                  q.pop();
                  int node=ele.first;
                  int root=ele.second;
                  for(int j=0;j<adj[node].size();j++){
                      if(vis[adj[node][j]]!=0 && adj[node][j]!=root)return true;
                      else if (adj[node][j]!=root){
                          q.push({adj[node][j],node});
                          vis[adj[node][j]]=1;
                      }
                  }
                }
                
            }
        }
        return false;
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends