class Solution {
public:
  int res = 0;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime){
      vector<vector<pair<int,int>>> adj(n);
      for(int i =0;i<manager.size();i++)
      {
        if(manager[i]!=-1)
          adj[manager[i]].push_back({i,informTime[manager[i]]});
      }
      //2-{0,0},{1,0},
      /*
      for(int i = 0;i<adj.size();i++)
      {
        cout<<i<<" ";
        for(auto v: adj)
        {
          cout<<v.first<<" "<<v.second<<" ";
        }
        cout<<"\n";
      }
      */
      dfs(adj,headID,0);
      return res;
      
      
        
    }
  
  void dfs(vector<vector<pair<int,int>>>& adj,int i,int curr_time)
  {
    res = max(res,curr_time);
    for(auto t: adj[i])
    {
      dfs(adj,t.first,curr_time+t.second);
    }
  }
  
};
/*1- {1,2},{2,3},{4,5}
2-{}
*/