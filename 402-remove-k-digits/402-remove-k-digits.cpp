class Solution {
public:
    string removeKdigits(string num, int k) {
      if(k==0) return num;
      stack<char> s;
      for(int i = 0;i<num.size();i++)
      {
        if(s.empty()==true)
          s.push(num[i]);
        else
        {
          while(!s.empty() && s.top()>num[i] && k>0)
          {
            s.pop();
            k--;
          }
          s.push(num[i]);
        }
      }
      while(k>0 && !s.empty())
        s.pop(),k--;
      
      string res = "";
      while(!s.empty())
      {
        res+=s.top();
        s.pop();
      }
      for(int i = res.size()-1;i>0;i--)
      {
        if(res[i]=='0')
          res.pop_back();
        else
          break;
          
      }
      reverse(res.begin(),res.end());
      if(res=="") return "0";
      return res;
      
      
        
    }
};