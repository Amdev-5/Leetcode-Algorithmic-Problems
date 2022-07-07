class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.length();
    int n = s2.length();
    if(s3.length()!=m+n) return false;
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
    dp[0][0] = true;
    for(int i = 1;i<=m;i++)
    {
      if(s1[i-1]==s3[i-1]) dp[i][0] = dp[i-1][0];
      else dp[i][0] = false;
    }
    for(int i = 1;i<=n;i++)
    {
      if(s2[i-1]==s3[i-1]) dp[0][i] = dp[0][i-1];
      else dp[0][i] = false;
    }
    for(int i = 1;i<=m;i++)
    {
      for(int j=1;j<=n;j++)
      {
        dp[i][j] = false;
        if(s1[i-1]==s3[i+j-1])
        {
          dp[i][j] = dp[i][j]|| dp[i-1][j];
        }
        if(s2[j-1]==s3[i+j-1])
        {
          dp[i][j] = dp[i][j] || dp[i][j-1];
        }
      }
    }
    return dp[m][n];
    
  }
};
  /*
  bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.length();
    int n2 = s2.length();
    if(n1+n2!=s3.size()) return false;
    //int index = s3.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    //memset(dp,-1,sizeof(dp));
    if(rec(s1,s2,s3,n1,n2,dp)==1) return true;
    return false;
    
  }
  int rec(string s1, string s2, string s3,int i,int j,vector<vector<int>> & dp)
  {
    if(i==0 && j==0)
    {
      return dp[i][j] = 1;
    };
    if(dp[i][j]!=-1)
    {
      return dp[i][j];
    }
    if(i>0 && s1[i-1]==s3[i+j-1] && j>0 && s2[j-1]==s3[i+j-1]) return dp[i][j] = rec(s1,s2,s3,i-1,j,dp)||rec(s1,s2,s3,i,j-1,dp);
    else if(i>0 && s1[i-1]==s3[i+j-1]) return dp[i][j] = rec(s1,s2,s3,i-1,j,dp);
    else if(j>0 && s2[j-1]==s3[i+j-1]) return dp[i][j] = rec(s1,s2,s3,i,j-1,dp);
    else return dp[i][j] = false;
  }
};
*/
  /*
  bool res = false;
  bool isInterleave(string s1, string s2, string s3) {
    if(s3.length()!= s1.length()+s2.length())
      return false;
    int m = s1.length();
    int n = s2.length();
    bool dp[m+1][n+1];
    dp[0][0] = true;
    for(int i = 1;i<=m;i++)
    {
      if(s1[i-1]==s3[i-1])
        dp[i][0] = dp[i-1][0];
      else
        dp[i][0] = false;
    }
    for(int i = 1;i<=n;i++)
    {
      if(s2[i-1]==s3[i-1])
        dp[0][i] = dp[0][i-1];
      else
        dp[0][i] = false;
    }
    for(int i = 1;i<=m;i++)
    {
      for(int j = 1;j<=n;j++)
      {
        dp[i][j] = false;
        if(s3[i+j-1]==s1[i-1])
          dp[i][j] = dp[i-1][j] || dp[i][j];
        if(s3[i+j-1]==s2[j-1])
          dp[i][j] = dp[i][j-1] || dp[i][j];
      }
    }
    return dp[m][n];
  }
};
*/