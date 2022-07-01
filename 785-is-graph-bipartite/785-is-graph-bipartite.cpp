class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n =  graph.size();
    vector<int> color(n,-1);
    for(int i = 0;i<n;i++)
    {
      if(color[i]==-1)
      {
        if(dfs(graph,i,color)==false) return false;
      }
    }
    return true; 
  }
  bool dfs(vector<vector<int>> & graph, int i , vector<int>& color)
  {
    if(color[i]==-1) color[i] = 1;
    for(auto t: graph[i])
    {
      if(color[t]==-1)
      {
        color[t] = 1-color[i];
        if(dfs(graph,t,color)==false) return false;
      }
      if(color[t]==color[i]) return false;
    }
    return true;
  }
};
  /*
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color (graph.size(),0);
        bool visited[graph.size()];
        for(int i = 0;i<graph.size();i++)
        {
            visited[i] = false;
        }
        queue<int> q;
        for(int i = 0;i<graph.size();i++)
        {
            if(!visited[i])
            {
                q.push(i);
        color[i] = 1;
        visited[i] = true;
        
        while(!q.empty())
        {
            int z = q.front();
            q.pop();
            for(int i: graph[z])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                    if(color[z]==1)
                        color[i] = -1;
                    else
                        color[i] = 1;
                }
                else
                {
                    if(color[i]==color[z])
                    return false;
                    
                }
            }
        }
                
            }
        }
        //
        q.push(i);
        color[i] = 1;
        visited[i] = true;
        
        while(!q.empty())
        {
            int z = q.front();
            q.pop();
            for(int i: graph[z])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                    if(color[z]==1)
                        color[i] = -1;
                    else
                        color[i] = 1;
                }
                else
                {
                    if(color[i]==color[z])
                    return false;
                    
                }
            }
        }
        
        
        return true;
        
    }
};
*/