class Solution {
public:
  int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> alpha(26);
    for(int i=0;i<s.length();i++) alpha[s[i]-'a'].push_back(i);
    int res = 0;
    for(int i = 0;i<words.size();i++)
    {
      int idx = -1;
      bool found = true;
      for(int j = 0;j<words[i].size();j++)
      {
        auto it = upper_bound(alpha[words[i][j]-'a'].begin(),alpha[words[i][j]-'a'].end(),idx);
        if(it==alpha[words[i][j]-'a'].end()) found = false;
        else idx = *it;
      }
      if(found) res++;
    }
    return res;
  }
//     int numMatchingSubseq(string s, vector<string>& words) {
//       int res = 0;
//       for(string word: words)
//       {
//         int l = 0;
//         int r = 0;
//         while(l<s.size())
//         {
//           if(word[r]==s[l]) r++;
//           l++;
//         }
//         if(r==word.size()) res++;
//       }
//       return res;
        
//     }
};