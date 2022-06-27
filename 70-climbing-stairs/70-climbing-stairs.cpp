class Solution {
public:
    int climbStairs(int n) {
      if(n==1 || n==2) return n;
      vector<int> dp(n+1);
      dp[0] = 0;
      dp[1]= 1;
      dp[2]  = 2;
      if(n==1 || n==2) return dp[n];
      for(int i = 3;i<=n;i++)
      {
        dp[i] = dp[i-2]+dp[i-1];
      }
      return dp[n];
        /*
      if(n==1 || n==2) return n;
      return climbStairs(n-1) + climbStairs(n-2);
      */
        /*
        int a = 0;
        int b = 1;
        int res  = 0;
        for(int i = 0;i<n;i++)
        {
            res = a+b;
            a = b;
            b = res;

        }
        return res;
        */
      /*
        if(n==1|| n==2)
        {
            return n;
        }
        int dp[n+1];
        dp[2]  = 2;
        dp[1] = 1;
        for(int i = 3;i<=n;i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
        */
        //dp solution
        
    }
};