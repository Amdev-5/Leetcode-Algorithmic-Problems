class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
      int res = 0;
      sort(allowed.begin(),allowed.end());
      for(int i = 0;i<words.size();i++)
      {
        bool flag = true;
        for(int j = 0;j<words[i].size();j++)
        {
          if(!count(allowed.begin(),allowed.end(),words[i][j])){
            flag = false;
            break;
          }
        }
        if(flag)
        {
          cout<<i<<" ";
          res++;
        }
      }
      return res;
        
    }
};