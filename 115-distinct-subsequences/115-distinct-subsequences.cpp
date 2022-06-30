class Solution {
public:
  int modulo = (int)1e9 +7;
  int numDistinct(string s, string t) {
    int m = s.size();
    int n = t.size();
    vector<vector<long>> dp(n+1,vector<long>(m+1,0));
    for(int i = 0;i<=m;i++)
    {
      dp[0][i] = 1;
    }
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        dp[i][j] = dp[i][j-1];
        if(t[i-1]==s[j-1])
          dp[i][j] = (dp[i][j]%modulo + dp[i-1][j-1]%modulo)%modulo;
      }
    }
    return dp[n][m];
  }
};
    // either take it or don't afterward traverse  how many t
    /* bit masking giving run time error after 33 bits 
    int n = s.size();
    long long z= 1<<n;
    int res = 0;
    for(long long i= 0;i<z;i++)
    {
      string curr = "";
      for(int j = 0;j<n;j++)
      {
        if((i>>j) & 1)
        {
          curr+=s[j];
        }
      }
      if(curr==t) res++;
    }
    return res;
    
  }
  */
  /*
  int res = 0;
    int numDistinct(string s, string t) {
      rec(s,t,"",0);
      return res;
        
    }
  void rec(string s,string t,string curr,int index)
  {
    cout<<curr<<" ";
    //if(index==s.size()) return;
    if(curr==t)
    {
      res++;
      return;
    }
    if(index==s.size()) return;
    rec(s,t,curr+s[index],index+1);
    rec(s,t,curr,index+1);
    //rec(s,t,curr+s[index],index+1);
  }
  */
