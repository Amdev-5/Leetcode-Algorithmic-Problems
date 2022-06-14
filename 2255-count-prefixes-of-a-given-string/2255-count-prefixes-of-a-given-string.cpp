class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
      int res = 0;
      for(int i = 0;i<words.size();i++)
      {
        int j = 0;
        while(j<words[i].size())
        {
          if(words[i][j]!=s[j])
            break;
          j++;
        }
        if(j==words[i].size()) res++;
      }
      return res;
      
        
    }
};