class Solution {
public:
    string longestPalindrome(string s) {
      int n = s.size();
      bool dp[n][n];
      memset(dp,false,sizeof(dp));
      int g = 0;
      int res = 1;
      pair<int,int> p;
      for(int g=0;g<n;g++)
      {
        for(int i=0,j=g;j<n;i++,j++)
        {
          if(g==0)
          {
            dp[i][j] = true;
            p = {i,j};
          }
          else if(g==1)
          {
            if(s[i]==s[j])
            {
              dp[i][j] = true;
              res = 2;
              p = {i,j};
            }
          }
          else
          {
            if(s[i]==s[j] && dp[i+1][j-1]==true)
            {
              dp[i][j] = true;
              if(j-i+1>res)
              {
                res = j-i+1;
                p = {i,j};
              }
              //res = max(res,j-i+1);
            }
          }
        }
      }
      return s.substr(p.first,p.second-p.first+1);
                    
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      /*
        int n = s.length();
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        pair<int,int> res;
        for(int g = 0;g<s.length();g++)
        {
            for(int i = 0,j=g;j<n;i++,j++)
            {
                if(g==0)
                {
                    dp[i][j] = true;
                    res = {0,0};
                    
                }
                else if(g==1 && s[i]==s[j])
                {
                    dp[i][j] = true;
                    res = {i,j};
                }
                else
                {
                    if(s[i]==s[j] && dp[i+1][j-1]==true)
                    {
                        dp[i][j] = true;
                        res = {i,j};
                    }
                }
                    
            }
        }
        string ou = "";
        for(int i = res.first;i<=res.second;i++)
        {
            ou+=s[i];
        }
        return ou;
        */
        
        
    }
};

/*
every single element is paindrome


when gap =0 true
when gap = 1 and curr element is eual to previous then true
when gap = 2 if(s[0] = curr char && dp[1][curr index-1]) then true
     b a b a d
   b t f t f f
   a * t f t f
   b * * t f f 
   a * * * t f
   d * * * * t
   
     b b
   b t 
   b * t
    

*/