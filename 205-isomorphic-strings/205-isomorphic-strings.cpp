class Solution {
public:
    bool isIsomorphic(string s, string t) {
      unordered_map<char,char> m;
      if(s.size()!=t.size()) return false;
      unordered_set<char> set;
      for(int i = 0;i<s.size();i++)
      {
        if(m.find(s[i])==m.end())
        {
          if(set.find(t[i])!=set.end()) return false;
          m[s[i]] = t[i];
          set.insert(t[i]);
        }
        else
        {
          if(m[s[i]]!=t[i]) return false;
        }
      }
      return true;
        
    }
};