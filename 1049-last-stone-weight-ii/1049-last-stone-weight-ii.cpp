class Solution {
public:
  int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for(int i = 0;i<stones.size();i++)
    {
      sum+=stones[i];
    }
    int n = stones.size();
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    for(int i = 0;i<=n;i++)
    {
      dp[i][0] = true;
    }
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=sum;j++)
      {
        dp[i][j] = dp[i-1][j];
        if(j-stones[i-1]>=0)
        {
          dp[i][j] = dp[i][j] || dp[i-1][j-stones[i-1]];
        }
      }
    }
    int s = sum/2;
    for(int j=s;j>=0;j--)
    {
      if(dp[n][j])
        return sum-2*j;
    }
    return 0;
  }
};
  /*
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int i = 0;i<stones.size();i++)
        {
            sum+=stones[i];
        }
        int n = stones.size();
        bool dp[n+1][sum+1];
        for(int i = 0;i<=n;i++)
        {
            dp[i][0] = true; 
        }
        for(int i = 1;i<=sum;i++)
        {
            dp[0][i] = false;
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=sum;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(stones[i-1]<=j)
                {
                    dp[i][j]= dp[i][j]|| dp[i-1][j-stones[i-1]];
                }
            }
        }
        int res = INT_MAX;
        for(int j = sum/2;j>=0;j--)
        {
            if(dp[n][j])
                return sum-2*j;
                //res = min(res,abs((sum-j)-j));
        }
        return res;
        
    }
};
    
    
    /* Recursive
    int lastStoneWeightII(vector<int>& stones) {
        int res = INT_MAX;
        int sum = 0;
        int s = 0;
        for(int i = 0;i<stones.size();i++)
        {
            s+=stones[i];
        }
        rec(res,stones,0,sum,s);
        return res;
        
    }
    void rec(int& res,vector<int>& stones,int i,int sum,int s)
    {
        if(i==stones.size())
        {
            int z = s-sum;
            res = min(res,abs(z-sum));
        }
        else
        {
            rec(res,stones,i+1,sum,s);
            rec(res,stones,i+1,sum+stones[i],s);
        }
    }
};
*/