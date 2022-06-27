class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int res = INT_MIN;
    int curr = 0;
    for(int i = 0;i<nums.size();i++)
    {
      curr+=nums[i];
      res= max(curr,res);
      if(curr<0) curr = 0;
    }
    return res;
    
    
    /*
    int sum = 0;
    int maxi = INT_MIN;
    for(auto it:nums)
    {
      sum+=it;
      maxi = max(sum,maxi);
      if(sum<0) sum = 0;
    }
    return maxi;
    */
    /*if(nums.size()==1)
      return nums[0];
    bool flag = false;
    int m =INT_MIN;
    for(int i = 0;i<nums.size();i++)
    {
      m = max(m,nums[i]);
      if(nums[i]>=0)
        flag = true;
    }
    if(!flag)
      return m;
    int maxi=INT_MIN;
    int sum = max(0,nums[0]);
    for(int i = 1;i<nums.size();i++)
    {
      maxi = max(maxi,sum);
      sum+=nums[i];
      sum = max(0,sum);
    }
    sum = max(0,sum);
    maxi = max(maxi,sum);
    return maxi;
    */
  }

  
  /*
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int res = nums[0];
        int curr = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            curr = max(curr+nums[i],nums[i]);
            res = max(res,curr);
            
        }
        return res;
        
        
        
    }
    */
};