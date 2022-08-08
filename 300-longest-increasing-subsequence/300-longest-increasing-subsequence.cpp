class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    //dp[0] = 1;
    for(int i =1;i<n;i++)
    {
      for(int j = 0;j<i;j++)
      {
        if(nums[j]<nums[i])
        {
          dp[i] = max(dp[i],1+dp[j]);
        }
      }
    }
    int res = dp[0];
    for(int i = 0;i<n;i++)
    {
      res = max(res,dp[i]);
    }
    return res;
  }
};/*
    //binary search approach in LIS
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1;i<n;i++)
        {
            if(nums[i]>temp[temp.size()-1])
                temp.push_back(nums[i]);
            else
            {
                int z = ceil(nums[i],temp,0,temp.size());
                temp[z] = nums[i];
            }
        }
        return temp.size();
        
    }
    int ceil(int z,vector<int>& temp,int l,int r)
    {
        while(l<r)
        {
            int mid = l + (r-l)/2;
        if(temp[mid]>=z)
            r = mid;
        else
            l = mid+1;
            
        }
        return r;
    }
};
*/

/*
temp 10
     9
     2
     2 5
     2 3
     2 3 7
     2 3 7 101
     2 3 7 18
     return temp.size();
     */    
    /* dp approach
    int lengthOfLIS(vector<int>& nums) {
        int lis[nums.size()];
        lis[0]= 1;
        for(int i = 1;i<nums.size();i++)
        {
            lis[i] = 1;
            for(int j = 0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    lis[i] = max(lis[i],lis[j]+1);
                }
            }
        }
        int res = lis[0];
        for(int i = 1;i<nums.size();i++)
        {
            if(lis[i]>res)
                res = lis[i];
        }
        return res;
        
    }
};
*/