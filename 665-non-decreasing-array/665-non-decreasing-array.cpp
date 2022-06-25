class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
      if(nums.size()==1) return true;
      vector<int> temp(nums);
      int modifications = 0;
      bool left = true;
      bool right = true;
      for(int i = 1;i<nums.size();i++)
      {
        if(nums[i]<nums[i-1])
        {
          if(modifications>0)
          {
            left = false;
            break;
          }
          else
          {
            modifications++;
            nums[i] = nums[i-1];
          }
        }
      }
      modifications = 0;
      for(int i = nums.size()-2;i>=0;i--)
      {
        if(temp[i]>temp[i+1])
        {
          if(modifications>0)
          {
            right = false;
            break;
          }
          else
          {
            modifications++;
            temp[i] = temp[i+1];
          }
        }
      }
      //for(int i = )
      return left || right;
        
    }
};