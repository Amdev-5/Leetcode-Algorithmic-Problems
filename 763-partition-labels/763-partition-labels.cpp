class Solution {
public:
    vector<int> partitionLabels(string s) {
      vector<int> last_idx(26,0);
      for(int i= 0;i<s.size();i++)
      {
        last_idx[s[i]-'a'] = i;
      }
      vector<int> res;
      int first=0;
      int last = -1;
      for(int i = 0;i<s.size();i++)
      {
        last = max(last,last_idx[s[i]-'a']);
        if(last==i)
        {
          res.push_back(last-first+1);
          first = i+1;
        }
      }
      return res;
      
      
        
    }
};