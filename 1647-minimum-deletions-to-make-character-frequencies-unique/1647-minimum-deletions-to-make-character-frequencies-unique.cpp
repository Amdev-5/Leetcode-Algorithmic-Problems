class Solution {
public:
    int minDeletions(string s) {
      unordered_map<char,int> m;
      for(int i= 0;i<s.size();i++)
      {
        m[s[i]]++;
      }
      unordered_map<int,int> count;
      for(auto t: m)
      {
        count[t.second]++;
      }
      int res = 0;
      for(auto t: count)
      {
        if(t.second>1)
        {
          for(int i=2;i<=t.second;i++)
          {
            int j = t.first;
            while(count[j]!=0 && j!=0)
            {
              j--;
              res++;
            }
            count[j]++;
          }
        }
      }
      return res;
        
    }
};