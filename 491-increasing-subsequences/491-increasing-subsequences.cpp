class Solution {
public:
  vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      vector<int> temp;
      dfs(nums,temp,0);
      return res;
        
    }
  void dfs(vector<int>& nums, vector<int> & temp,int curr)
  {
    if(temp.size()>1) res.push_back(temp);
    unordered_set<int> hash;
    for(int i=curr;i<nums.size();i++)
    {
      if((temp.empty() || nums[i]>=temp.back()) && hash.find(nums[i])==hash.end())
      {
        temp.push_back(nums[i]);
        dfs(nums,temp,i+1);
        temp.pop_back();
        hash.insert(nums[i]);
      }
    }
    
  }
};