class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      vector<int> res;
      if(nums.size()==1) return res;
      for(int i = 1;i<nums.size();i++)
      {
        if(nums[i]==nums[i-1])
          res.push_back(nums[i]);
      }
      return res;
      
        
    }
};