class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      unordered_map<int,int> m;
      int res = 0;
      int sum = 0;
      for(int i = 0;i<nums.size();i++)
      {
        sum+=nums[i];
        if(sum==goal) res++;
        if(m.find(sum-goal)!=m.end()) res+=m[sum-goal];
        m[sum]++;
      }
      return res;
        
    }
};