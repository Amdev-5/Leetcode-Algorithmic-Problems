class Solution {
public:
  int maxprod = 1;
  bool is_pal(string s)
  {
    int i = 0;
    int j = s.size()-1;
    while(i<=j)
    {
      if(s[i]!=s[j]) return false;
      i++;
      j--;
    }
    return true;
  }
    int maxProduct(string s) {
      string s1 = "";
      string s2 = "";
      dfs(s,s1,s2,0);
      return maxprod;
    }
  void dfs(string& s, string& s1, string& s2,int i)
  {
    if(i>=s.length())
    {
      if(is_pal(s1) && is_pal(s2))
      {
        maxprod = max(maxprod,(int(s1.size())*int(s2.size())));
      }
      return;
    }
    
    s1.push_back(s[i]);
    dfs(s,s1,s2,i+1);
    s1.pop_back();
    
    s2.push_back(s[i]);
    dfs(s,s1,s2,i+1);
    s2.pop_back();
    
    dfs(s,s1,s2,i+1);
    
  }
  /* 198/226 testcase passed and then TLE
  void rec1(string s, vector<bool> vis,int curr,string prepal)
  {
    for(int i = curr;i<s.size();i++)
    {
      if(vis[i]==false)
      {
        prepal+=s[i];
        vis[i]= true;
        if(is_pal(prepal)) rec2(s,vis,0,"",prepal);
        rec1(s,vis,i+1,prepal);
        vis[i] = false;
        prepal.pop_back();
      }
      
    }
  }
  void rec2(string s, vector<bool> vis,int post_ind,string postpal,string prepal)
  {
    if(is_pal(postpal))
    {
      int z = prepal.size()*postpal.size();
      maxprod = max(maxprod,z);
    }
    for(int i = post_ind;i<s.size();i++)
    {
      if(vis[i]==false)
      {
        postpal+=s[i];
        vis[i] = true;
        rec2(s,vis,i+1,postpal,prepal);
        postpal.pop_back();
        vis[i] = false;
      }
    }
    
  } 
  */
};
//doing knasack on string, marking if character visited, if palindrome then call rest of the char, if rest is palindrome update maxproduct

//knapsack to only check if palindromic subsequences find it will return size