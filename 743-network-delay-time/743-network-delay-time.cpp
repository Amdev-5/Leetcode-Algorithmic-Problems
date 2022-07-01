class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int,int>> adj[n+1];
    for(int i = 0;i<times.size();i++)
    {
      adj[times[i][0]].push_back({times[i][1],times[i][2]});
    }
    vector<int> dist(n+1,INT_MAX);
    queue<int> q;
    dist[k] = 0;
    q.push(k);
    while(!q.empty())
    {
      int z = q.front();
      q.pop();
      for(auto t: adj[z])
      {
        if(dist[z]+t.second<dist[t.first])
        {
          dist[t.first] = dist[z]+t.second;
          q.push(t.first);
        }
      }
    }
    int res = 0;
    for(int i = 1;i<=n;i++)
    {
      res = max(res,dist[i]);
    }
    if(res==INT_MAX) return -1;
    return res;
    
  }
};
  /* Bellman Ford Algorithm
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> res(n+1,INT_MAX);
        res[k] = 0;
        for(int i = 0;i<n-1;i++)
        {
            for(int j = 0;j<times.size();j++)
            {
                if(res[times[j][0]]!=INT_MAX && res[times[j][0]]+times[j][2] < res[times[j][1]])
                {
                    res[times[j][1]] = res[times[j][0]]+times[j][2];
                }
                
            }
        }
        
        int z = INT_MIN;
        for(int i = 1;i<=n;i++)
        {
            if(res[i]>z)
                z = res[i];
        }
        if(z==INT_MAX)
                return -1;
        return z;
        
        
    }
};
*/