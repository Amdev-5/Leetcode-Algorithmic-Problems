class Solution {
public:
    int balancedStringSplit(string s) {
      int count_r=0;
      int count_l = 0;
      int res = 0;
      for(int i = 0;i<s.size();i++)
      {
        if(s[i]=='R') count_r++;
        else count_l++;
        if(count_r==count_l) res++;
      }
      return res;
        
    }
};