class Solution {
public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    int len = strs.size();
    int dp[len+1][m+1][n+1];
    memset(dp,0,sizeof(dp));
    //vector<vector<vector<int>>> dp(len+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
    for(int i = 1;i<=len;i++)
    {
      for(int j = 0;j<=m;j++)
      {
        for(int k = 0;k<=n;k++)
        {
          int count0= count(strs[i-1].begin(),strs[i-1].end(),'0');
          int count1 = strs[i-1].size()-count0;
          int res = dp[i-1][j][k];
          if(j>=count0 && k>=count1)
          {
            res=max(1+dp[i-1][j-count0][k-count1],res);
          }
          dp[i][j][k] = res;
        }
      }
    }
    return dp[len][m][n];
    
  }
};
  /*
  int findMaxForm(vector<string>& strs, int m, int n) {
    int len = strs.size();
    vector<vector<vector<int>>> dp(len+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
    //bool dp[len+1][m+1][n+1];
    //memset(dp,0,sizeof(dp));
    return rec(0,strs,m,n,dp);  
  }
  int rec(int ind,vector<string>& strs,int m,int n, vector<vector<vector<int>>> & dp)
  {
    if(ind==strs.size() or m+n==0) return 0;
    if(dp[ind][m][n]!=-1) return dp[ind][m][n];
    int count0 = count(strs[ind].begin(),strs[ind].end(),'0');
    int count1 = strs[ind].size()-count0;
    int take =0;
    //int not_take = 0;
    if(count0<=m and count1<=n)
    {
      take = 1+rec(ind+1,strs,m-count0,n-count1,dp);
    }
    int not_take = rec(ind+1,strs,m,n,dp);
    return dp[ind][m][n] = max(take,not_take);
  }

};
*/
  /*
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        int dp[len+1][m+1][n+1];
        memset(dp, 0, sizeof dp);
        for(int i = 1;i<=len;i++)
        {
            for(int j = 0;j<=m;j++)
            {
                for(int k = 0;k<=n;k++)
                {
                    int ones = count(strs[i-1].begin(),strs[i-1].end(),'1');
                    int zeros = strs[i-1].size()-ones;
                    int res = dp[i-1][j][k];
                    if(zeros<=j && ones<=k)
                    {
                        res = max(res,dp[i-1][j-zeros][k-ones]+1);
                    }
                    dp[i][j][k] = res;
                }
            }
        }
      return dp[len][m][n];
    }
};*/