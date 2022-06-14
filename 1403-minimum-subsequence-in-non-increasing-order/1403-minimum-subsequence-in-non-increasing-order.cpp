class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
      vector<int> res;
      int sum = 0;
      for(int i=0;i<nums.size();i++)
      {
        sum+=nums[i];
      }
      int temp = 0;
      sort(nums.begin(),nums.end());
      for(int i = nums.size()-1;i>=0;i--)
      {
        temp+=nums[i];
        res.push_back(nums[i]);
        if(temp> sum-temp)
        {
          break;
        }
      }
      return res;
        
    }
};