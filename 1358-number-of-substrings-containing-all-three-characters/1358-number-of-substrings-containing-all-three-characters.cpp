class Solution {
public:
    int numberOfSubstrings(string s) {
      unordered_map<char,int> m;
      int l = 0,r=0,res=0;
      while(r<s.size())
      {
        m[s[r]]++;
        while(m['a'] && m['b'] && m['c'])
        {
          res+=s.size()-r;
          m[s[l]]--;
          l++;
        }
        r++;
      }
      return res;
    }
};