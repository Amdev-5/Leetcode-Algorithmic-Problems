class Solution {
public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<int> dict(26,0);
    for(int i = 0;i<words2.size();i++)
    {
      vector<int> temp(26,0);
      for(char c: words2[i])
      {
        temp[c-'a']++;
      }
      for(int j = 0;j<26;j++)
      {
        dict[j] = max(dict[j],temp[j]);
      }
    }
    vector<string> res;
    for(int i = 0;i<words1.size();i++)
    {
      vector<int> temp(26,0);
      for(char c: words1[i])
      {
        temp[c-'a']++;
      }
      bool flag = true;
      for(int j = 0;j<26;j++)
      {
        if(temp[j]<dict[j])
        {
          flag = false;
          break;
        }
      }
      if(flag) res.push_back(words1[i]);
      
    }
    return res;
    
    
  }
};
  /*
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
      vector<unordered_map<char,int>> m1(words1.size());
      vector<unordered_map<char,int>> m2(words2.size());
      for(int i = 0;i<words1.size();i++)
      {
        for(char c: words1[i])
        {
          m1[i][c]++;
        }
      }
      for(int i = 0;i<words2.size();i++)
      {
        for(char c: words2[i])
        {
          m2[i][c]++;
        }
      }
      vector<string> res;
      for(int i = 0;i<words1.size();i++)
      {
        bool flag = true;
        for(int j = 0;j<words2.size();j++)
        {
          
          for(auto t:m2[j])
          {
            if(m1[i][t.first]<t.second) flag= false;
          }
        }
        if(flag) res.push_back(words1[i]);
      }
      return res;
      
      
        
    }
};
*/