class Solution {
public:
  set<vector<int>> set;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      rec(nums,{},nums.size());
      vector<vector<int>> res;
      for(auto t: set)
        res.push_back(t);
      //sort(res.begin(),res.end());
      return res;
      
      
    }
  void rec(vector<int>& nums,vector<int> temp,int N)
  {
    if(N==0)
    {
      //sort(temp.begin(),temp.end());
      set.insert(temp);
    }
    else
    {
      rec(nums,temp,N-1);
      temp.push_back(nums[N-1]);
      rec(nums,temp,N-1);
    }
    
  }
};
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      /*
        set<vector<int>> s;
        unsigned int pow_set_size = pow(2, nums.size());
        int counter, j;
        for(counter = 0;counter<pow_set_size;counter++)
        {
            vector<int> temp;
            for(j=0;j<nums.size();j++)
            {
                if(counter&(1<<j))
                {
                    temp.push_back(nums[j]);
                    

                }
            }
            s.insert(temp);
        }
        vector<vector<int>> res;
        for (auto it = s.begin();
         it != s.end();
         it++) {
  
        res.push_back(*it);
    }
        return res;
        */
        
