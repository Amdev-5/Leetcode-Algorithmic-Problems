class Solution {
public:
  vector<vector<int>> res;
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    rec(0,candidates,target,{});
    return res;
    
    
    
    
    
    
    
    
    
  }
  void rec(int curr,vector<int>& candidates,int target,vector<int> temp)
  {
    if(target==0)
    {
      res.push_back(temp);
      return;
    }
    else if(target<0)
    {
      return;
    }
    else
    {
      for(int i = curr;i<candidates.size();i++)
      {
        temp.push_back(candidates[i]);
        rec(i,candidates,target-candidates[i],temp);
        temp.pop_back();
      }
    }
  }
};
  
  
  
  
  
  
  
  
  
  
  
  
  /*
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int curr = 0;
        back(curr,candidates,target,res,temp);
        return res;
        
        
        
    }
    void back(int curr,vector<int>& candidates,int target,vector<vector<int>>& res,vector<int> temp)
    {
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(target<0)
            return;
        else
        {
            for(int i = curr;i<candidates.size();i++)
            {
                temp.push_back(candidates[i]);
                back(i,candidates,target-candidates[i],res,temp);
                temp.pop_back();
            }
            
        }
            
    }
};
*/