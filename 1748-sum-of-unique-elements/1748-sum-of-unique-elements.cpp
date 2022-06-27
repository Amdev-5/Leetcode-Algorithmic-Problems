class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
      unordered_map<int,int> m;
      for(int i= 0;i<nums.size();i++)
      {
        m[nums[i]]++;
      }
      int res = 0;
      for(auto t: m)
      {
        if(t.second==1)
          res+=t.first;
      }
      return res;
        
    }
};