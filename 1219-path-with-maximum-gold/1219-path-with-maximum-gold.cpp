class Solution {
public:
  int dfs(vector<vector<int>>& g,int i,int j)
  {
    if(i<0 || j<0 || i>=g.size() || j>=g[0].size() || g[i][j]<=0) return 0;
    g[i][j] = -g[i][j];
    int res = max({dfs(g,i+1,j),dfs(g,i,j+1),dfs(g,i-1,j),dfs(g,i,j-1)});
    g[i][j] = -g[i][j];
    return g[i][j]+res;
  }
  int getMaximumGold(vector<vector<int>>& grid) {
    int res = 0;
    for(int i = 0;i<grid.size();i++)
    {
      for(int j = 0;j<grid[0].size();j++)
      {
        res = max(res,dfs(grid,i,j));
      }
    }
    return res;
  }
};
  /* TLE
  int res = 0;
    int getMaximumGold(vector<vector<int>>& grid) {
      vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
      for(int i=0;i<grid.size();i++)
      {
        for(int j = 0;j<grid[0].size();j++)
        {
          if(grid[i][j]!=0 && vis[i][j]==false)
            dfs(grid,i,j,vis,0);
        }
      }
      //dfs(grid,0,0,vis,0);
      return res;
    }
  void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>> vis,int gold)
  {
    if(i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]==true)
    {
      res = max(res,gold);
      return;
    }
    vis[i][j] = true;
    dfs(grid,i+1,j,vis,gold+grid[i][j]);
    dfs(grid,i,j+1,vis,gold+grid[i][j]);
    dfs(grid,i-1,j,vis,gold+grid[i][j]);
    dfs(grid,i,j-1,vis,gold+grid[i][j]);
  }
};
*/