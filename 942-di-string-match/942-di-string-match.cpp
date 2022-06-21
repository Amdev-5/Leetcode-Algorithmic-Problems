class Solution {
public:
    vector<int> diStringMatch(string s) {
      int n = s.size();
      int i = 0;
      int j = n;
      vector<int> res;
      for(char c: s)
      {
        if(c=='I')
        {
          res.push_back(i);
          i++;
        }
        else
        {
          res.push_back(j);
          j--;
        }
      }
      res.push_back(j);
      return res;
        
    }
};
/*
unordered_set<int> set;

*/