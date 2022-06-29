// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> res;
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        /*
        for(int i = 0;i<V;i++)
        {
            cout<<i<<"-";
            for(auto t: adj[i])
            {
                cout<<t<<" ";
            }
            cout<<"\n";
            
        }
        */
        dfs(adj,0,vis);
        return res;
        
        // Code here
    }
    void dfs(vector<int> adj[],int i,vector<bool> & vis)
    {
        
        res.push_back(i);
        vis[i] = true;
        for(auto t: adj[i])
        {
            if(vis[t]==false)
            {
                dfs(adj,t,vis);
            }
        }
    }
    
};

// { Driver Code Starts.
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
}  // } Driver Code Ends