class Solution {
public:
    bool wordPattern(string pattern, string s) {
      unordered_map<char,string> m;
      unordered_set<string> set;
      vector<string> v;
      string curr = "";
      for(int i = 0;i<s.size();i++)
      {
        if(s[i]==' ')
        {
          v.push_back(curr);
          curr = "";
        }
        else
        {
          curr+=s[i];
        }
      }
      v.push_back(curr);
      int i = 0;
      int j = 0;
      if(pattern.size()!=v.size()) return false;
      while(i<pattern.size() && j<v.size())
      {
        if(m.find(pattern[i])==m.end())
        {
          if(set.find(v[j])!=set.end()) return false;
          m[pattern[i]] = v[j];
          set.insert(v[j]);
          i++;
          j++;
        }
        else
        {
          if(m[pattern[i]]!=v[j]) return false;
          i++;
          j++;
        }
      }
      return true;
    }
};