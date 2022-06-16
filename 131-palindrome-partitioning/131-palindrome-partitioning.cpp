class Solution {
public:
  vector<vector<string>> res;
  bool is_pal(string s)
  {
    int i= 0;
    int j= s.size()-1;
    while(i<j)
    {
      if(s[i]!=s[j]) return false;
      i++;
      j--;
    }
    return true;
  }
  vector<vector<string>> partition(string s) {
    rec(s,{});
    return res;
    
    
  }
  void rec(string s,vector<string> temp)
  {
    if(s.length()==0)
    {
      res.push_back(temp);
      return;
    }
    for(int i = 0;i<s.length();i++)
    {
      string prefix = s.substr(0,i+1);
      string suffix = s.substr(i+1,s.length());
      if(is_pal(prefix))
      {
        temp.push_back(prefix);
        rec(suffix,temp);
        temp.pop_back();
      }
    }
  }
};
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*
  
  
  vector<vector<string>> res;
  bool pal(string s)
  {
    int i = 0;
    int j = s.length()-1;
    while(i<j)
    {
      if(s[i]!=s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }
    vector<vector<string>> partition(string s) {
      vector<string> v;
      solution(s,v);
      return res;
        
    }
  void solution(string str,vector<string> asf)
  {
    if(str.length()==0)
    {
      res.push_back(asf);
      return;
    }
    for(int i = 0;i<str.length();i++)
    {
      string prefix = str.substr(0,i+1);
      string ros = str.substr(i+1,str.length());
      if(pal(prefix))
      {
        asf.push_back(prefix);
        solution(ros,asf);
        asf.pop_back();
      }
    }
  }
};
*/


/*
      a a b
    a t t f
    a * t f
    b * * t
0 1 2
01 2



        a a b a a 
      a t t f f t
      a * t f t f
      b *   t f f
      a *   * t t
      a *     * t
      
      
      a a b a a
      aa b aa
      a aba a
     
*/