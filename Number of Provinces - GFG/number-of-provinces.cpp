//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int n) {
        
        vector<int>adjlist[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j&&adj[i][j]!=0)
                {
                    adjlist[i].push_back(j);
                     adjlist[j].push_back(i);
                    
                }
            }
        }
        int c=0;
        vector<bool>vis(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                queue<int>q;
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    int temp=q.front();
                    q.pop();
                    for(int j=0;j<adjlist[temp].size();j++)
                    {
                        if(!vis[adjlist[temp][j]])
                        {q.push(adjlist[temp][j]);
                            vis[adjlist[temp][j]]=true;
                        }
                        
                    }
                }
                 c++;
            }
        }
       return c; 
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends