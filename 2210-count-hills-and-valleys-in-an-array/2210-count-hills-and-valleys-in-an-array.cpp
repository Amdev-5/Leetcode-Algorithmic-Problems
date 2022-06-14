class Solution {
public:
    int countHillValley(vector<int>& nums) {
      int res = 0;
      //if(nums.size()<3) return 0;
      vector<int> temp;
      for(int i =0;i<nums.size();i++)
      {
        if(i==0)
          temp.push_back(nums[i]);
        else if(nums[i]!=nums[i-1])
          temp.push_back(nums[i]);
      }
      for(int i = 0;i<temp.size();i++)
      {
        cout<<temp[i]<<" ";
      }
      if(temp.size()<3) return res;
      
      for(int i =1;i<temp.size()-1;i++)
      {
        if((temp[i]>temp[i+1] && temp[i]>temp[i-1]) || (temp[i]<temp[i-1] && temp[i]<temp[i+1])) res++;
      }
      return res;
        
    }
};