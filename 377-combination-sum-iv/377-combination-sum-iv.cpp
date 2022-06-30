class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target+1);
    dp[0] = 1;
    for(int i = 1;i<=target;i++)
    {
      for(int j = 0;j<nums.size();j++)
      {
        if(i-nums[j]>=0)
        {
          dp[i]+=dp[i-nums[j]];
        }
      }
    }
    return dp[target];
    
  }
  /*
    int combinationSum4(vector<int>& nums, int target) {
      vector<int> dp(target+1,INT_MAX);
      dp[0] = 1;
      return f(nums,target,dp);

    }
  int f(vector<int> & nums,int target,vector<int>& dp)
  {
    if(dp[target]!=INT_MAX) return dp[target];
      //if(target<0) return dp[target] = -1;
      int count = 0;
      for(int i = 0;i<nums.size();i++)
      {
        if(target>=nums[i]){
          int subres = combinationSum4(nums,target-nums[i]);
          if(subres!=-1)
          count+=subres;
        }
      }
      return dp[target] = count;
  }
  */
};