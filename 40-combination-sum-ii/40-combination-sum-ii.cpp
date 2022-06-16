class Solution {
public:
  vector<vector<int>> res;
   vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     sort(candidates.begin(),candidates.end());
     rec(0,candidates,target,{});
     return res;
     
   }
  void rec(int curr, vector<int>& candidates,int target,vector<int> temp)
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
        if(i==curr || candidates[i]!=candidates[i-1])
        {
          temp.push_back(candidates[i]);
          rec(i+1,candidates,target-candidates[i],temp);
          temp.pop_back();
          
        }
        
      }
    }
  }
};
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        int index = 0;
        back(0,res,temp,candidates,target);
        return res;
        
        
    }
    void back(int curr,vector<vector<int>>& res,vector<int> temp,vector<int>& candidates,int target)
    {
        if(target==0)
        {
            res.push_back(temp);
        }
        else if(target<0)
            return;
        else
        {
            for(int i = curr;i<candidates.size();i++)
            {
                if(i==curr || candidates[i]!=candidates[i-1])
                {
                    temp.push_back(candidates[i]);
                    back(i+1,res,temp,candidates,target-candidates[i]);
                    temp.pop_back();
                    
                }
            }
        }
    }
};
*/