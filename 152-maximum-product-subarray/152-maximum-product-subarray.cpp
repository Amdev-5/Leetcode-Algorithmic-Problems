class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int ans = nums[0];
    int ma= ans;
    int mi= ans;
    for(int i = 1;i<nums.size();i++)
    {
      if(nums[i]<0)
      {
        swap(ma,mi);
      }
      ma = max(nums[i],ma*nums[i]);
      mi = min(nums[i],mi*nums[i]);
      ans = max(ans,ma);
    }
    return ans;
    
  }
  /*
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int l = 1;
        int r = 1;
        for(int i = 0;i<nums.size();i++)
        {
            l = l*nums[i];
            r = r*nums[nums.size()-1-i];
            res = max(res,r);
            res = max(res,l);
            
            if(l==0)
                l=1;
            if(r==0)
                r = 1;
        }
        return res;
        
    }
    */
};