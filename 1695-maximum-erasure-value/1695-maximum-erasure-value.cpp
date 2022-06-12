class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
      unordered_set<int> set;
      int i = 0;
      int j = 0;
      int n = nums.size();
      int res = 0;
      int sum = 0;
      while(i<n && j<n)
      {
        if(set.find(nums[j])==set.end())
        {
          set.insert(nums[j]);
          sum+=nums[j];
          j++;
        }
        else
        {
          res = max(res,sum);
          while(i<j && set.find(nums[j])!=set.end())
          {
            sum-=nums[i];
            set.erase(nums[i]);
            i++;
          }
        }
      }
      res = max(res,sum);
      return res;
        
    }
};