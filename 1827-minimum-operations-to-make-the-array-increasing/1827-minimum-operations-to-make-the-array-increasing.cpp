class Solution {
public:
    int minOperations(vector<int>& nums) {
      if(nums.size()==1) return 0;
      int res = 0;
      int limit = nums[0];
      for(int i = 1;i<nums.size();i++)
      {
        if(nums[i]>limit)
        {
          limit = nums[i];
          continue;
        }
        res+=(limit+1-nums[i]);
        limit = limit+1;
      }
      return res;
        
    }
};