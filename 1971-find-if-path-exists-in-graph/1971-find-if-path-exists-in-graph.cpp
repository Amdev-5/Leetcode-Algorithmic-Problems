class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      vector<bool> vis(n,false);
      vector<vector<int>> adj(n);
      for(int i = 0;i<edges.size();i++)
      {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
      }
      dfs(adj,source,destination,vis);
      if(vis[destination]==true) return true;
      return false;
    }
  void dfs(vector<vector<int>>& adj, int i,int destination,vector<bool>& vis)
  {
    vis[i] = true;
    if(i==destination) return;
    for(auto t:adj[i])
    {
      if(vis[t]==false)
      {
        dfs(adj,t,destination,vis);
      }
    }
  }
};