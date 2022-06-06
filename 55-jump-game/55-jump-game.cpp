class Solution {
public:
    bool canJump(vector<int>& nums) {
      int reach = 0;
      for(int i = 0;i<nums.size();i++)
      {
        if(i<=reach)
          reach = max(i+nums[i],reach);
      }
      if(reach>=nums.size()-1)
        return true;
      return false;
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      /*
        int n = nums.size();
        int i = 0;
        int reach = 0;
        while(i < n && i <= reach)
        {
            reach = max(i + nums[i], reach);
            i++;
        }
        return i == n;
        */
        
    }
};