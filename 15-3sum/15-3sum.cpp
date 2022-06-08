class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> v;
      if(nums.size()<3) return v;
      sort(nums.begin(),nums.end());
      unordered_set<int> s;
      for(int i = 0;i<nums.size()-2;i++)
      {
        if(i>0 && nums[i]==nums[i-1]) continue;
        int left = i+1;
        int right = nums.size()-1;
        int f = -nums[i];
        while(left<right)
        {
          if(nums[left]+nums[right]<f)
          {
            left++;
          }
          else if(nums[left]+nums[right]>f)
          {
            right--;
          }
          else
          {
            v.push_back({nums[i],nums[left],nums[right]});
            left++;
            while(left<nums.size() && nums[left]==nums[left-1]) left++;
          }
        }
      }
      return v;
      /*
        vector<vector<int>> res;
        sort(begin(nums),end(nums));
        int n = nums.size();
        for(int i = 0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;

            }
            int start = i+1;
            int end = n-1;
            int requiredsum = 0 - nums[i];
            
            while(start<end)
            {
                int sum = nums[start]+nums[end];
                
                if(sum<requiredsum){
                    start++;
                }
                else if(sum>requiredsum){
                    end--;
                }
                else
                {
                    res.push_back(vector<int>{nums[i],nums[start],nums[end]});
                    start++;
                    while(start<end && nums[start]==nums[start-1]){
                        start++;

                    }
                }
            }
            
        
        }
        return res;
        */
        
        
        
    }
};