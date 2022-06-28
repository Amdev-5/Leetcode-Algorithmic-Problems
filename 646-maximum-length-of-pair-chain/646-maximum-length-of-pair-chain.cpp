class Solution {
public:
  bool static cmp(const vector<int> & a,const vector<int> & b)
  {
    return a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]);
  }
    int findLongestChain(vector<vector<int>>& pairs) {
      int n = pairs.size();
      if(n==1) return 1;
      sort(pairs.begin(),pairs.end(),cmp);
      vector<int> dp(n,1);
      for(int i = 1;i<n;i++)
      {
        for(int j = 0;j<i;j++)
        {
          if(pairs[i][0]>pairs[j][1])
            dp[i] = max(dp[i],dp[j]+1);
        }
      }
      int res = 1;
      for(int i = 0;i<n;i++)
      {
        res = max(dp[i],res);
      }
      return res;
        
    }
};