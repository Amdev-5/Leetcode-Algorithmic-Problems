class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
      //return rec(s1,s2,s1.size(),s2.size());
      int m = s1.size();
      int n = s2.size();
      vector<vector<int>> dp(m+1,vector<int>(n+1,0));
      for(int i = 1;i<=m;i++)
      {
        dp[i][0] = dp[i-1][0]+int(s1[i-1]);
      }
      for(int i = 1;i<=n;i++)
      {
        dp[0][i] = dp[0][i-1]+int(s2[i-1]);
      }
      //for(int i =0;i<=m;i++) cout<<dp[i][0]<<" ";
      //cout<<"\n";
      //for(int j = 0;j<=n;j++) cout<<dp[0][j]<<" ";
      for(int i= 1;i<=m;i++)
      {
        for(int j = 1;j<=n;j++)
        {
          if(s1[i-1]==s2[j-1])
          {
            dp[i][j] = dp[i-1][j-1];
          }
          else
          {
            dp[i][j] = min((int(s1[i-1])+dp[i-1][j]) , (int(s2[j-1])+dp[i][j-1]));
          }
        }
      }
      return dp[m][n];
        
    
  /* recursivesolution
  int rec(string s1,string s2, int i, int j)
  {
    if(i==0 && j==0) return 0;
    if(i==0)
    {
      int sum = 0;
      while(j!=0)
      {
        sum+=int(s2[j-1]);
        j--;
      }
      return sum;
    }
    if(j==0)
    {
      int sum = 0;
      while(i!=0)
      {
        sum+=int(s1[i-1]);
        i--;
      }
      return sum;
    }
    if(s1[i-1]==s2[j-1]) return rec(s1,s2,i-1,j-1);
    else 
    {
      return min(int(s1[i-1])+rec(s1,s2,i-1,j),int(s2[j-1])+rec(s1,s2,i,j-1));
    }
    */
  }
};