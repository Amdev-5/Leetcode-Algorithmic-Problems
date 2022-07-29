class Solution {
public:
    int findMin(vector<int>& nums)
    {
      if (nums.size() <= 0) { return 0; }
        
        int aLo = 0;
        int aHi = nums.size() - 1;
        int aMid = 0;
        
        while (aLo < aHi) {
            aMid = (aLo + aHi) / 2;
            if (nums[aMid] > nums[aHi]) {
                //Top is definitely rotated.
                aLo = aMid + 1;
            } else {
                //Bottom might be rotated.
                aHi = aMid;
            }    
        }
        
        return nums[aLo];
    }
};