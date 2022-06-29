class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      int n = nums.size();
      if(n==0) return {};
      sort(nums.begin(),nums.end());
      int max_idx= 0;
      vector<int> dp(n,1);
      vector<int> pre_index(n,-1);
      for(int i = 1;i<n;i++)
      {
        for(int j = 0;j<i;j++)
        {
          if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
          {
            dp[i] = dp[j]+1;
            pre_index[i] = j;
          }
          if(dp[i]>dp[max_idx])
            max_idx = i;
        }
      }
      vector<int> res;
      while(max_idx>=0)
      {
        res.push_back(nums[max_idx]);
        max_idx = pre_index[max_idx];
      }
      return res;
      
      
        
    }
};


    