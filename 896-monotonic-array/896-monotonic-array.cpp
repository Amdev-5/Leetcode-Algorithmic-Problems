class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
      if(nums.size()==1) return true;
      bool asc = false;
      bool desc = false;
      for(int i =1;i<nums.size();i++)
      {
        if(nums[i]>nums[i-1] && desc) return false;
        if(nums[i]<nums[i-1] && asc) return false;
        if(nums[i]>nums[i-1]) asc = true;
        if(nums[i]<nums[i-1]) desc =  true;
      }
      return true;
        
    }
};