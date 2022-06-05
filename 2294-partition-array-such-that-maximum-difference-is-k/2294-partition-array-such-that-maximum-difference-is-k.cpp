class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      int curr_minIndex = 0,count=1;
      for(int i=1;i<nums.size();i++)
      {
        if(nums[i]-nums[curr_minIndex]>k) count++,curr_minIndex = i;
      }
      return count; 
    }
};