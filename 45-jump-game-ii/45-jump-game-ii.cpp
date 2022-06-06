class Solution {
public:
    int jump(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n,INT_MAX);
      dp[n-1] = 0;
      for(int i =n-2;i>=0;i--)
      {
        for(int j=i+1;j<=i+nums[i] && j<n;j++)
        {
          if(dp[j]!=INT_MAX && dp[j]+1<dp[i])
            dp[i] = dp[j]+1;
          //since last one is reachable so checking how much min steps from last to 0 
          //dp[n-1] = 0;
          //now iterating from n-2 to 0 and i=j+1 to i+nums[i]&&n
          //checking if it is reachable than min(dp[j]+1,dp[i])
        }
      }
      return dp[0];
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      /*
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        dp[n-1] = 0;
        for(int i = n-2;i>=0;i--)
        {
            for(int j = i;j<=i+nums[i] && j<n;j++)
            {
                if(dp[j]!=INT_MAX && dp[j]+1 < dp[i])
                    dp[i] = dp[j]+1;
            }
        }
        return dp[0];
        */
    } 
};
    
    
    
    
    
    
    
    
    
  






















    
    
    
    
    /*
    int jump(vector<int>& nums) {
        unordered_map<int,int> m;
        m[0] = 0;
        for(int i = 1;i<nums.size();i++)
        {
            m[i] = INT_MAX;
        }
        for(int i = 0;i<nums.size();i++)
        {
            int z = i+nums[i];
            if(m[i]!=INT_MAX)
            {
                for(int j = i;j<=z && j<nums.size();j++)
                {
                    if(m[j] = min(m[j],m[i]+1));
                }
                
            }
        }
        return m[nums.size()-1];
        
    }
};
*/