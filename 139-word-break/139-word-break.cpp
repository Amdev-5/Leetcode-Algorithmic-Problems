class Solution {
public:
    bool wordBreak(string str, vector<string>& wordDict) {
      int n= str.size();
      if(n==0) return false;
      unordered_set<string> st;
      for(string s: wordDict) st.insert(s);
      vector<bool> dp(n+1,false);
      dp[0] = true;
      for(int i = 1;i<=n;i++)
      {
        for(int j = i-1;j>=0;j--)
        {
          if(dp[j])
          {
            string word = str.substr(j,i-j);
            if(st.count(word))
            {
              dp[i] = true;
              break;
            }
          }
        }
      }
      return dp[n];

        
    }
};