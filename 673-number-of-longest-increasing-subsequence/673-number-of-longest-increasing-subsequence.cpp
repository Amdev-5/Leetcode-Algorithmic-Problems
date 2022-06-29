class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    vector<int> count(n,1);
    int maxi = 1;
    for(int i = 0;i<n;i++)
    {
      for(int j = 0;j<i;j++)
      {
        if(nums[i]>nums[j] && dp[i]<dp[j]+1)
        {
          dp[i]=1+dp[j];
          count[i]  = count[j];
        }
        else if(nums[i]>nums[j] && dp[i]==dp[j]+1)
        {
          count[i]+=count[j];
          //maxi =max(maxi,count[i]);
        }
      }
      maxi = max(maxi,dp[i]);
    }
    
    int res = 0;
    for(int i =0;i<n;i++)
    {
      if(dp[i]==maxi) res+=count[i];
    }
    return res;
  }
};
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*
    int findNumberOfLIS(vector<int>& nums) {
      if(nums.size()==1)
        return 1;
      vector<int> lis(nums.size(),1);
      vector<int> cnt(nums.size(),1);
      int max_len = 1,ans=0;
      for(int i=1;i<nums.size();i++)
      {
        for(int j =0;j<i;j++)
        {
          if(nums[j]<nums[i])
          {
            if(lis[j]+1>lis[i]){
              lis[i] = lis[j]+1;
              cnt[i] = cnt[j];
            }
            else if(lis[j]+1==lis[i])
              cnt[i]+=cnt[j];
          }
        }
        max_len = max(max_len,lis[i]);
      }
      for(int i = 0;i<nums.size();i++)
      {
        cout<<lis[i]<<" ";
      }
      for(int i = 0;i<nums.size();i++)
      {
        if(lis[i]==max_len)
          ans+=cnt[i];
      }
      return ans;
        
    }
};

*/