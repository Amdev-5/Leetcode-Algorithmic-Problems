class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
      multiset<int> m;
      int j = 0;
      int res = 1;
      for(int i = 0;i<nums.size();i++)
      {
        m.insert(nums[i]);
        while(!m.empty() && *m.rbegin()-*m.begin()>limit)
          m.erase(m.find(nums[j++]));
        res = max(res,i-j+1);
      }
      return res;
        
    }
};
