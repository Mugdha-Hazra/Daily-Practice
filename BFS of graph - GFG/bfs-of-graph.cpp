//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        bool vis[n]={false};
        vector<int>ans;
        queue<int>q;
        q.push(0);
        ans.push_back(0);
        vis[0]=true;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int i=0;i<adj[temp].size();i++)
            {
                if(!vis[adj[temp][i]]){
                    q.push(adj[temp][i]);
                    vis[adj[temp][i]]=true;
                    ans.push_back(adj[temp][i]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends