class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      vector<int> v(nums.size()+1,0);
      for(int i = 0;i<nums.size();i++)
      {
        v[nums[i]] = 1;
      }
      vector<int> res;
      for(int i = 1;i<v.size();i++)
      {
        if(v[i]==0)
        {
          res.push_back(i);
        }
      }
      return res;
        
    }
};