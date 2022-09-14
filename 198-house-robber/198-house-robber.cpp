class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        if(nums.size()==1) return dp[0];
        dp[1] = max(nums[1],nums[0]);
        if(nums.size()==2) return max(dp[0],dp[1]);
        for(int i = 2;i<nums.size();i++)
        {
            dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[nums.size()-1];
        
     }

//     int rob(vector<int>& nums) {
//         vector<int> dp(nums.size(),-1);
//         return rec(nums.size()-1,nums,dp);
        
//     }
//     int rec(int index,vector<int> & nums,vector<int> & dp)
//     {
//         if(index==0 || index==1) return dp[index] = nums[index];
//         if(dp[index]!=-1) return dp[index];
//         return dp[index] = max(rec(index-1,nums,dp),nums[index]+rec(index-2,nums,dp));
//     }
};