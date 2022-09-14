class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int curr = 0;
        for(int i = 0;i<nums.size();i++)
        {
            curr+=nums[i];
            res = max(curr,res);
            if(curr<0) curr=0;
        }
        return res;
        
    }
};