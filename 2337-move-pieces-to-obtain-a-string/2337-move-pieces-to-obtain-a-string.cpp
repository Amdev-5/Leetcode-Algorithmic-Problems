class Solution {
public:
    bool canChange(string s, string t) {
      if(s.size()!=t.size()) return false;
      queue<pair<char,int>> ss,ts;
      for(int i= 0;i<s.size();i++)
      {
        if(s[i]!='_') ss.push({s[i],i});
        if(t[i]!='_') ts.push({t[i],i});
      }
      if(ss.size()!=ts.size()) return false;
      while(!ss.empty())
      {
        pair<char,int> p1,p2;
        p1 = ss.front();
        p2 = ts.front();
        if(p1.first!=p2.first) return false;
        ss.pop();
        ts.pop();
        if(p1.first=='L' && p1.second<p2.second) return false;
        if(p1.first=='R' && p1.second>p2.second) return false;
      }
      return true;
    }
};