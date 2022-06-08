class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
      if(nums.size()==1) return 1;
      int up =1;
      int down = 1;
      // if current element is greater than last element than we need to update that up is down +1 viceversa
      for(int i=1;i<nums.size();i++)
      {
        if(nums[i]>nums[i-1]) up = down+1;
        if(nums[i]<nums[i-1]) down = up+1;
      }
      return max(up,down);
        
    }
};