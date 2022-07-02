class Solution {
public:
  int res = 0;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
      vector<vector<pair<int,int>>> adj(n+1);
      for(int i = 0;i<edges.size();i++)
      {
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
      }
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
      pq.push({0,n}) ;//dist,node
      vector<int> dist(n+1,INT_MAX);
      dist[n] = 0;
      while(!pq.empty())
      {
        pair<int,int> p = pq.top();
        pq.pop();
        for(auto t: adj[p.second])
        {
          if(p.first+t.second<dist[t.first])
          {
            dist[t.first] = p.first+t.second;
            pq.push({dist[t.first],t.first});
          }
        }
      }
      /*
      for(int i = 0;i<dist.size();i++)
      {
        cout<<dist[i]<<" ";
      }
      */
      //vector<int> vis(n+1,false);
      vector<int> dp(n+1,-1);
      return dfs(adj,n,dp,dist);     
    }
  int dfs(vector<vector<pair<int,int>>>& gp, int s, vector<int>& dp, vector<int>& dist) {
        int mod = 1e9+7;
        if (s == 1) return 1;
        if (dp[s] != -1) return dp[s];
        int sum = 0, weight, val;
        for (auto& n : gp[s]) {
            weight = dist[s];
            val = dist[n.first];
            if (val > weight) {
                sum = (sum % mod + dfs(gp, n.first, dp, dist) % mod) % mod;
            }
        }
        return dp[s] = sum % mod;
    }
};
/*
make a vector store distance from lastnode to each node using dijkstras
now make a dfs from find all paths from lastnode to first node where the distance for node(i) to last node >node(i+1)
*/