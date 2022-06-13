class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      if(triangle.size()==1)
        return triangle[0][0];
      vector<vector<int>> dp;
      dp.push_back({triangle[0][0]});
      for(int i = 1;i<triangle.size();i++)
      {
        dp.push_back({});
        for(int j= 0;j<triangle[i].size();j++)
        {
          if(j==0)
          {
            int z = dp[i-1][0]+triangle[i][j];
            dp.back().push_back(z);
          }
          else if(j==triangle[i].size()-1)
          {
            int y = dp[i-1][j-1]+triangle[i][j];
            dp.back().push_back(y);
          }
          else
          {
            int x= min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
            dp.back().push_back(x);
          }
        }
        
      }
      int res = INT_MAX;
      for(int i = 0;i<triangle.size();i++)
      {
        res = min(res,dp[triangle.size()-1][i]);
      }
      return res;
        
    }
};

/*
    to reach any place there is  3 either from left from right or from top


dp[n-1][0] = dp[n-2][0]+triangle[n-1][0];
dp[n-1][n-1] = dp[n-2][n-2]+triangle[n-1][n-1]
for others dp[n-1][i] = min(dp[n-2][i-1],dp[n-2][i])+traingle[n-1][i];
for other columns we have four options 
min([i-1][j-1] [i-1][j]) + triangle[i][j]
*/