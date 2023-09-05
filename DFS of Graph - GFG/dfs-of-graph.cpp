//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfsTraversal(vector<int>&ans,vector<int> adj[],bool vis[],int start){
        vis[start]=true;
        ans.push_back(start);
        for(int i=0;i<adj[start].size();i++)
        {
            if(!vis[adj[start][i]]){
                dfsTraversal(ans,adj,vis,adj[start][i]);
            }
        }
    }
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        vector<int>ans;
        bool vis[n]={false};
        int start=0;
        dfsTraversal(ans,adj,vis,start);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends