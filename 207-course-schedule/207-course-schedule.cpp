class Solution {
public:
  bool res = true;
    bool canFinish(int n, vector<vector<int>>& pre) {
      vector<vector<int>> adj(n);
      vector<int> indegree(n,0);
      for(int i = 0;i<pre.size();i++)
      {
        adj[pre[i][1]].push_back(pre[i][0]);
        indegree[pre[i][0]]++;
      }
      queue<int> q;
      for(int i = 0;i<n;i++)
      {
        if(indegree[i]==0)
        {
          q.push(i);
        }
      }
      int count = 0;
      while(!q.empty())
      {
        int z = q.front();
        q.pop();
        count++;
        for(auto t: adj[z])
        {
          indegree[t]--;
          if(indegree[t]==0)
          {
            q.push(t);
          }
        }
      }
      if(count==n) return true;
      return false;
    }
  
      
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
      /*
        vector<vector<int>> adj(n,vector<int>());
        vector<int> indegree(n,0);
        for(int i =0;i<pre.size();i++)
        {
            indegree[pre[i][0]]++;
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        queue<int> q;
        for(int i = 0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            n--;
            for(auto z: adj[u])
            {
                if(--indegree[z]==0)
                    q.push(z);
            }
        }
        if(n==0)
            return true;
        return false;
        */
        
};