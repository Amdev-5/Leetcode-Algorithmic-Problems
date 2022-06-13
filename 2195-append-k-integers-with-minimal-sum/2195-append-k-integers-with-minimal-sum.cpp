class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
        long long limit=1, remove=0;
        for(int i=0, prev=1; i<nums.size() && k; prev = nums[i]+1, ++i) {
            if(nums[i] >= prev)  remove += nums[i];
            if(k <= nums[i]-prev) remove -= nums[i], limit = prev+k-1, k = 0;
            else k -= max(0,nums[i]-prev);
        }
        if(k) limit = nums.back()+k;
        return ((limit*(limit+1))/2) - remove;
        
    }
};