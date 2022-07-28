class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> ans;
      vector<int> hash(26,0);
      vector<int> phash(26,0);
      int m = s.size();
      int n = p.size();
      if(m<n) return ans;
      int left = 0;
      int right = 0;
      while(right<n)
      {
        phash[p[right]-'a']++;
        hash[s[right]-'a']++;
        right++;
      }
      right--;
      while(right<m)
      {
        if(phash==hash) ans.push_back(left);
        right++;
        if(right!=m)
        {
          hash[s[right]-'a']++;
        }
        hash[s[left]-'a']--;
        left++;
      }
      return ans;
      
      
        
    }
};

  /*
    vector<int> findAnagrams(string s, string p) {
      if(s.size()<p.size()) return {};
      vector<int> res;
      int n = p.size();
      for(int i =0;i<=s.size()-n;i++)
      {
        string temp = s.substr(i,n);
        cout<<temp<<" ";
        if(isAnagram(s.substr(i,n),p)) res.push_back(i);
      }
      return res; 
    }
  bool isAnagram(string s, string t) {
      if(s.size()!=t.size())  return false;
      unordered_map<char,int> m;
      for(int i=0;i<s.size();i++)
      {
        m[s[i]]++;
      }
      for(int i =0;i<t.size();i++)
      {
        if(m.find(t[i])==m.end() || m[t[i]]==0)return false;
        m[t[i]]--;
      }
      return true;
        
    }
    */