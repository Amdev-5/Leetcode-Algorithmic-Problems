class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n =  graph.size();
    vector<int> color(n,-1);
    queue<int> q;
    for(int i=0;i<n;i++)
    {
      if(color[i]==-1)
      {
        q.push(i);
        color[i] =1;
        while(!q.empty())
      {
        int z = q.front();
        q.pop();
        if(color[z]==-1) color[z]=1;
        for(auto t: graph[z])
        {
          if(color[t]==-1)
          {
            color[t]= 1-color[z];
            q.push(t);
          }
          else if(color[t]!=-1 && color[t]==color[z]) return false;
        }
      }
      }
    }
    return true;
  }
};
/* DFS
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
*/