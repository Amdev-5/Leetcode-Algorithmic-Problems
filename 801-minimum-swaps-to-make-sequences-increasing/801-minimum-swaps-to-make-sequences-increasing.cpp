class Solution {
public:
  int minSwap(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> swap(n,1);
    vector<int> noswap(n,0);
    for(int i = 1;i<n;i++)
    {
      noswap[i] = swap[i]= n;
      if(nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1])
      {
        swap[i] = swap[i-1]+1;
        noswap[i] = noswap[i-1];
      }
      if(nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1])
      {
        swap[i] = min(noswap[i-1]+1,swap[i]);
        noswap[i]= min(swap[i-1],noswap[i]); 
      }
    }
    return min(swap[n-1],noswap[n-1]);
  }
  /*
    int res = INT_MAX;
    bool isincreasing(vector<int> nums)
    {
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])
                return false;
        }
        return true;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        rec(nums1,nums2,nums1.size(),0);
        return res;   
    }
    void rec(vector<int> nums1,vector<int> nums2,int index,int swap)
    {
        if(index==0)
        {
            if(isincreasing(nums1) && isincreasing(nums2))
            {
                res = min(res,swap);
            }
            return;
        }
        rec(nums1,nums2,index-1,swap);
        int z = nums1[index-1];
        nums1[index-1]=nums2[index-1];
        nums2[index-1] = z;
        rec(nums1,nums2,index-1,swap+1);
        int y = nums1[index-1];
        nums1[index-1] = nums2[index-1];
        nums2[index-1] = y;
    }
    */
};