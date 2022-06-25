class Solution {
public:
    int minMoves(vector<int>& nums) {
      int n = nums.size();
      if(n<=1) return 0;
      int mini = nums[0];
      long int sum =nums[0];
      for(int i=1;i<n;i++)
      {
        sum+=nums[i];
        mini = min(mini,nums[i]);
      }
      return sum-long(mini)*long(n);
      
        
    }
};