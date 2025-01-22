//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        // vector<int>res;
        // int vis[adj.size()]={0};
        // queue<int>q;
        // q.push(0);
        // while(!(q.empty())){
        //     int node=q.front();
        //     q.pop();
        //     vis[node]=1;
        //     res.push_back(node);
        //     for(int i=0;i<adj[node].size();i++){
        //         if(!vis[adj[node][i]]){
        //             q.push(adj[node][i]);
        //         }
        //     }
            
        // }
        // return res;
          vector<int> res;                  // Result to store BFS traversal
    vector<int> vis(adj.size(), 0);   // Visited array, initialized to 0
    queue<int> q;
    
    q.push(0);                        // Assuming BFS starts from node 0
    vis[0] = 1;                       // Mark node 0 as visited
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);
        
        // Traverse all adjacent nodes
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];
            if (!vis[neighbor]) {
                q.push(neighbor);     // Push the unvisited node to the queue
                vis[neighbor] = 1;    // Mark it as visited
            }
        }
    }
    
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

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends