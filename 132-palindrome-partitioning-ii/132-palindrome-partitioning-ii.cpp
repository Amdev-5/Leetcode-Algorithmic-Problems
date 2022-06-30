class Solution {
public:
  int minCut(string s) {
    int n = s.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = -1;       //act as a sentinel
        for(int i = 0; i < n; i++){
	//palindrome of length 1,3,5...
            for(int len = 0; i-len >= 0 && i+len < n && s[i-len] == s[i+len]; len++)
                dp[i+len+1] = min(dp[i+len+1], dp[i-len]+1);
	//palindrome of lenght 2,4,6...
            for(int len = 0; i-len >= 0 && i+len+1 < n && s[i-len] == s[i+len+1]; len++)
                dp[i+len+2] = min(dp[i+len+2], dp[i-len]+1);
        }
        return dp[n];

  }
  
  /*
  int f(int i, int n, string & curr,vector<int> & dp,vector<vector<bool>> pal)
  {
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int min_cost = INT_MAX;
    for(int j=i;j<n;j++)
    {
      if(pal[i][j]==true)
      {
        int cost = 1 + f(j+1,n,curr,dp,pal);
        min_cost = min(min_cost,cost);
      }
    }
    return dp[i] = min_cost;
  }
    int minCut(string s) { 
      int n = s.size();
      vector<vector<bool>> pal(n,vector<bool> (n,false));
      for(int g=0;g<n;g++)
      {
        for(int i=0,j=g;i<n,j<n;i++,j++)
        {
          if(g==0)
          {
            pal[i][j] = true;
          }
          else if(g==1)
          {
            if(s[i]==s[j])
            {
              pal[i][j] = true;
            }
          }
          else
          {
            if(s[i]==s[j] && pal[i+1][j-1]==true)
            {
              pal[i][j] = true;
            }
          }
        }
      }
      vector<int> dp(s.size(),-1);
      return f(0,s.size(),s,dp,pal)-1;
      
    }
    */
};