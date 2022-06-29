class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int i = 0;i<nums.size();i++)
    {
      sum+=nums[i];
    }
    if(sum%2!=0) return false;
    sum = sum/2;
    int n = nums.size();
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    for(int i =0;i<=n;i++) dp[i][0] = true;
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=sum;j++)
      {
        dp[i][j] = dp[i-1][j];
        if(j-nums[i-1]>=0)
          dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
      }
    }
    return dp[n][sum];
    
    
  }
};

  /*
  bool res = false;
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int i = 0;i<nums.size();i++)
    {
      sum+=nums[i];
    }
    if(sum%2!=0) return false;
    sum = sum/2;
    int n = nums.size();
    rec(nums,n,sum);
    return res;
    
    
  }
  void rec(vector<int>& nums,int i, int sum)
  {
    if(sum<0 || i<=0) return;
    if(sum==0)
    {
      res = true;
      return;
    }
    rec(nums,i-1,sum-nums[i-1]);
    rec(nums,i-1,sum);
  }
};
*/
/*
    bool canPartition(vector<int>& nums) {
         if(nums.size()==1)
         {
             return false;
         }
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;
        sum/=2;
        //problem become subset sum equals to sum/2 
        bool dp[n+1][sum+1];
        dp[0][0] = true;
    
    for (int i = 1; i < n+1; i++) {
        dp[i][0] = true;
    }
    for (int j = 1; j < sum+1; j++) {
        dp[0][j] = false;
    }
        for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < sum+1; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= nums[i-1]) {
                dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
            }
        }
    }
        return dp[n][sum];
        
        
        
        
        
    }
};
*/
    
    
    /*
    Recursive
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int i = 0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;
        int z = sum/2;
        int n = nums.size();
        return subsetsum(nums,z,n);
        
        
    }
    bool subsetsum(vector<int>& nums,int z,int n)
    {
        if(z==0)
            return true;
        if(n==0)
            return false;
        else
        {
            if(nums[n-1]>z)
                return subsetsum(nums,z,n-1);
            else
                return (subsetsum(nums,z,n-1) || subsetsum(nums,z-nums[n-1],n-1));
        }
    }
};
*/