#include <vector>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int original = nums.size();
      int current = 0;
      for(int i = 1;i<original;i++)
      {
        if(nums[i]==nums[i-1])
        {
          //count of duplicacy
          current++;
        }
        //going current times back because current duplicate numbers 
        nums[i-current] = nums[i];
      }
      return original-current;
      /*
        int original = nums.size();
        int current = 0;
        for(int i=1;i<original;i++)
        {
            if(nums[i]==nums[i-1])
            {
                current++;
            }
            nums[i-current] = nums[i];
        }
        return original-current;
        */
        
        
        
        
    }
};