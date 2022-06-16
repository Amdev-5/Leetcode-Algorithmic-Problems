class Solution {
public:
  vector<vector<int>> res;
  vector<vector<int>> permute(vector<int>& nums){
    rec(0,nums);
    return res;
    
  }
  void rec(int index,vector<int>& nums)
  {
    if(index==nums.size())
    {
      res.push_back(nums);
      return;
    }
    for(int i = index;i<nums.size();i++)
    {
      swap(nums[i],nums[index]);
      rec(index+1,nums);
      swap(nums[i],nums[index]);
    }
  }
};
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*
    vector<vector<int>> permute(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> visited(n,false);
        back(res,temp,nums,0,n,visited);
        return res;
        
        
    }
    void back(vector<vector<int>>& res,vector<int>& temp,vector<int> nums,int index,int n,vector<bool>& visited)
    {
        if(index==n)
        {
            res.push_back(temp);
            return;
        }
        for(int i =0;i<n;i++)
        {
            if(!visited[i])
            {
                temp.push_back(nums[i]);
                visited[i] = true;
                back(res,temp,nums,index+1,n,visited);
                temp.pop_back();
                visited[i] = false;
                
            }
        }
        
    }
};
*/