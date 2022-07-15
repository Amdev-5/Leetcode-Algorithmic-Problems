class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = INT_MIN;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                int count = 0;
                dfs(grid,i,j,count);
                res = max(res,count);
                
            }
        }
        return res;
        
    }
    void dfs(vector<vector<int>>& grid,int i ,int j,int& count)
    {
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1)
        {
            count++;
            grid[i][j] = 0;
            dfs(grid,i+1,j,count);
            dfs(grid,i,j+1,count);
            dfs(grid,i-1,j,count);
            dfs(grid,i,j-1,count);
        }
        return;
    }
};
