class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int res = 0;
      int count = 0;
      for(int i= 0;i<nums.size();i++)
      {
        if(nums[i]==0)
        {
          res= max(res,count);
          count = 0;
        }
        else
        {
          count++;
        }
      }
      res = max(res,count);
      return res;
      /*
        int res = 0;
        int count = 0;
        int k = 1;
        for(int i = 0;i<nums.size();i++)
        {
            if(k&nums[i] == 1)
            {
                count++;
                res = max(res,count);
            }
            else
            {
                //res = max(res,count);
                count = 0;
                //res = max(res,count);
                

            }
        }
        return res;
        */
        
    }
};