class Solution {
public:
  vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      vector<int> temp;
      temp.push_back(0);
      dfs(graph,temp,0);
      return res;  
    }
  void dfs(vector<vector<int>>& graph, vector<int>& temp,int i)
  {
    if(i==graph.size()-1)
    {
      res.push_back(temp);
      return;
    }
    for(auto t: graph[i])
    {
      temp.push_back(t);
      dfs(graph,temp,t);
      temp.pop_back();
    }
    
  }
};