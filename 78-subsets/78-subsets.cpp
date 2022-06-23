class Solution {
public:
    //bit manipulation
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> res;
      int n = nums.size();
      int p = 1<<n;
      for(int i =0;i<p;i++)
      {
        vector<int> temp;
        for(int j = 0;j<nums.size();j++)
        {
          if((i>>j) & 1)
            temp.push_back(nums[j]);
        }
        res.push_back(temp);
      }
      return res;
        
    }
};
    
    
    /*
    using recursion
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        vector<int> temp;
        knapsack(nums,res,temp,n);
        return res;
        
        
        
    }
    void knapsack(vector<int>& nums,vector<vector<int>>& res,vector<int> temp,int n)
    {
        if(n==0)
            res.push_back(temp);
        else
        {
            vector<int> t(temp);
            temp.push_back(nums[n-1]);
            knapsack(nums,res,temp,n-1);
            knapsack(nums,res,t,n-1);
        }
    }
};
*/