class Solution {
public:
    int countSubstrings(string s) {
      int n = s.length();
      vector<vector<bool>> dp(n,vector<bool>(n,false));
      int count = 0;
      for(int g = 0;g<n;g++)
      {
        for(int i=0,j=g;i<n,j<n;i++,j++)
        {
          if(g==0) dp[i][j] = true;
          else if(g==1)
          {
            if(s[i]==s[j]) dp[i][j] = true;
          }
          else
          {
            if(s[i]==s[j] && dp[i+1][j-1]==true)
            {
              dp[i][j] = true;
            }
          }
          if(dp[i][j]==true)
            count++;
        }
        
      }
      return count;
        
    }
};


/* Gap Method 
            a   b   c   b   a
         a  0   1   2   3   4
         b  *   0   1   2   3
         c  *   *   0   1   2
         b  *   *   *   0   1
         a  *   *   *   *   0
so if gap is 0 then put true
if gap 1 and char[i]==char[j] then dp[i][j] = true
else check if i==j and then dp[++i][--j]  \
* because it's substring can't start from j>i
*/