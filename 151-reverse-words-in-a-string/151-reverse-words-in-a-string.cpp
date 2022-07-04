class Solution {
public:
    string reverseWords(string s) {
      reverse(s.begin(),s.end());
      //cout<<s;
      int j = 0;
      string res = "";
      while(j<s.size())
      {
        while(s[j]==' ') j++;
        string temp = "";
        while(j<s.size() && s[j]!=' ')
        {
          temp+=s[j];
          j++;
        }
        reverse(temp.begin(),temp.end());
        res+=temp;
        res+=" ";
        while(s[j]==' ' && j<s.size())
        {
          j++;
        }
        //j++;
      }
      res.pop_back();
      
      //reverse(s.substr(i,j-i+1).begin(),s.substr(i,j-i+1).end());
      //if(s[0]==' ') s.pop_front();
      return res;
      
        
    }
};