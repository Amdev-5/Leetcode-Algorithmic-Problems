class Solution {
public:
    int longestPalindrome(string s) {
      int res = 0;
      unordered_map<char,int> m;
      for(int i = 0;i<s.size();i++)
      {
        m[s[i]]++;
      }
      bool flag = true;
      for(auto t: m)
      {
        if(t.second%2==0)
        {
          res+=t.second;
        }
        else
        {
          if(flag)
          {
            flag = false;
            res+=t.second;
          }
          else
          {
            res+=t.second-1;
          }
        }
      }
      return res;
        
    }
};