class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    int maxi = amount+1;
    vector<int> dp(amount+1,maxi);
    dp[0] = 0;
    for(int i = 1;i<=amount;i++)
    {
      for(int j = 0;j<coins.size();j++)
      {
        if(i-coins[j]>=0)
        {
          dp[i] = min(dp[i],dp[i-coins[j]]+1);
        }
      }
    }
    if(dp[amount]>amount) return -1;
    return dp[amount];
    
  }
};
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*
    int coinChange(vector<int>& coins, int amount) {
      if(amount==0) return 1;
      int res = -1;
      for(int i = 0;i<coins.size();i++)
      {
        if(amount>=coins[i])
        {
          int subres = coinChange(coins,amount-coins[i]);
          if(subres==-1) res = -1;
          else
          {
            min(res,subres+1);
          }
        }
      }
      return res;
      */
      
      /*
        int dp[amount+1];
        dp[0] = 0;
        for(int i=1;i<=amount;i++)
        {
            dp[i] = INT_MAX;
        }
        int n = coins.size();
        for(int i = 1;i<=amount;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(coins[j]<=i)
                {
                    int res = dp[i-coins[j]];
                    if(res!=INT_MAX)
                        dp[i] = min(dp[i],1+res);
                }
            }
        }
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
        */
        
