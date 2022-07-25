class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size()-1;
        int l = -1;
        int r = -1;
        vector<int> res = {-1,-1};
        if(nums.empty())
        {
            return res;
        }
        //searching floor index
        while(first<last)
        {
            int middle = first+(last-first)/2;
            if(nums[middle]<target)
            {
                first = middle+1;
            }
            else
            {
                last=middle;
            }
        }
        if(nums[first]!=target)
        {
            return res;
        }
        res[0] = first;
        last = nums.size()-1;
        //searching for ceil
        while(first<last)
        {
            int middle = first+(last-first +1)/2;
            if(nums[middle]>target)
            {
                last = middle-1;
            }
            else
            {
                first = middle;
            }
        }
        res[1] = first;
        
        return res;
        
        
    }
};