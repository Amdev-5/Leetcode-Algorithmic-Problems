class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      unordered_map<int,int> m;
      for(int i =0;i<nums.size();i++)
      {
        if(nums[i]&1)
          nums[i]= 1;
        else
          nums[i] = 0;
      }
      int res = 0;
      int sum =0;
      for(int i =0;i<nums.size();i++)
      {
        sum+=nums[i];
        if(sum==k) res++;
        if(m.find(sum-k)!=m.end()) res+=m[sum-k];
        m[sum]++;
      }
      return res;
      
        
    }
};