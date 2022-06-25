class Solution {
public:
    int secondHighest(string s) {
      vector<int> temp;
      for(int i =0;i<s.size();i++)
      {
        if(s[i]-'0'>=0 && s[i]-'0'<=9)
        {
          temp.push_back(s[i]-'0');
        }
      }
      if(temp.size()==1) return -1;
      sort(temp.begin(),temp.end());
      int i = temp.size()-2;
      while(i>=0)
      {
        if(temp[i]!=temp[i+1])
          return temp[i];
        i--;
      }
      return -1;
        
    }
};