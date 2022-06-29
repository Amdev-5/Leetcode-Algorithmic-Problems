class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
      unordered_map<int,int> m;
      for(int i = 0;i<nums.size();i++)
      {
        m[nums[i]]++;
      }
      vector<pair<int,int>> v;
      for(auto t: m)
      {
        v.push_back({t.first,t.second});
      }
      sort(v.begin(),v.end());
      /*
      for(int i = 0;i<v.size();i++)
      {
        cout<<v[i].first<<" "<<v[i].second;
        cout<<"\n";
      }*/
      int n = v.size();
      vector<int> dp(n,0);
      dp[0] = v[0].second*v[0].first;
      if(v.size()==1) return dp[0];
      dp[1] = v[1].second*v[1].first;
      if(v[1].first-v[0].first!=1) dp[1]+=dp[0];
      else dp[1] = max(dp[0],dp[1]);
      if(v.size()==2) return dp[1];
      for(int i = 2;i<n;i++)
      {
        /* dp[i]+dp[i-2], dp[i]+dp[*/
        dp[i] = v[i].first*v[i].second;
        if(v[i].first-v[i-1].first!=1)
        {
          dp[i] = max(dp[i-2]+dp[i],dp[i-1]+dp[i]);
        }
        else
        {
          dp[i] = max(dp[i-1],dp[i-2]+dp[i]);
        }
      }
      /*
      for(int i = 0;i<n;i++)
      {
        cout<<dp[i]<<" ";
      }
      */
      return dp[n-1];
      
        
    }
};
    /*
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> m{0};
        for(int i = 0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        sort(nums.begin(),nums.end());
        vector<int> s;
        s.push_back(nums[0]);
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                s.push_back(nums[i]);
            }
        }
        int dp[s.size()+1];
        dp[0] = s[0]*m[s[0]];
        if(s.size()==1)
        {
            return dp[0];
        }
        if(s[1]-s[0]==1)
        {
            dp[1] = max(s[1]*m[s[1]],s[0]*m[s[0]]);
        }
        else
        {
            dp[1] = dp[0] + s[1]*m[s[1]];
        }
        if(s.size()==2)
        {
            return dp[1];
        }
        for(int i = 2;i<s.size();i++)
        {
            if(s[i]-s[i-1]==1)
            {
                dp[i] = max(s[i]*m[s[i]] + dp[i-2], dp[i-1]); 
            }
            else
            {
                dp[i] = s[i]*m[s[i]] + dp[i-1];
            }
        }
        return dp[s.size()-1];
        
        
    }
};
*/