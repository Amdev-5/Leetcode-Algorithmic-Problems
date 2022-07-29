class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
      vector<string> result;
      for(auto t: words)
      {
        unordered_map<char,char> m1;
        unordered_map<char,char> m2;
        bool flag  = true;
        for(int i = 0;i<t.size();i++)
        {
          if(m1.find(t[i])!=m1.end())
          {
            if(m1[t[i]]!=pattern[i])
            {
              flag = false;
              break;
            }
          }
          else if(m2.find(pattern[i])!=m2.end())
          {
            if(m2[pattern[i]]!=t[i])
            {
              flag = false;
              break;
            }
          }
          else
          {
            m1[t[i]] = pattern[i];
            m2[pattern[i]] = t[i];
          }
        }
        if(flag) result.push_back(t); 
      }
      return result;
      
        
    }
};