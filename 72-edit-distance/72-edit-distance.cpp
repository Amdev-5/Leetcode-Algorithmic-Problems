class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n= word2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i = 0;i<=m;i++)
    {
      dp[i][0]=i;
    }
    for(int j = 0;j<=n;j++)
    {
      dp[0][j] = j;
    }
    for(int i =1;i<=m;i++)
    {
      for(int j = 1;j<=n;j++)
      {
        if(word1[i-1]==word2[j-1])
        {
          dp[i][j] = dp[i-1][j-1];
        }
        else
        {
          dp[i][j] = 1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
        }
      }
    }
    return dp[m][n];
    /*
    int m = word1.length();
    int n = word2.length();
    int dp[m+1][n+1];
    dp[0][0] = 0;
    for(int i = 1;i<=m;i++)
    {
      dp[i][0] = i;
    }
    for(int i = 1;i<=n;i++)
    {
      dp[0][i] = i;
    }
    for(int i = 1;i<=m;i++)
    {
      for(int j =1;j<=n;j++)
      {
        if(word1[i-1]==word2[j-1])
          dp[i][j] = dp[i-1][j-1];
        else
          dp[i][j] = 1+ min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);
      }
    }
    return dp[m][n];
    */
    
  }
}; 
  
  /* Recursive Solution
    int minDistance(string word1, string word2) {
      return rec(word1,word2,word1.length(),word2.length());
    }
  int rec(string word1,string word2,int i,int j)
  {
    if(i==0 || j==0)
      return max(i,j);
    if(word1[i-1]==word2[j-1])
      return rec(word1,word2,i-1,j-1);
    else
      return 1+min(min(rec(word1,word2,i-1,j-1),rec(word1,word2,i-1,j)),rec(word1,word2,i,j-1));
  }
};


*/