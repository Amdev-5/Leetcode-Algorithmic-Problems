class Solution {
public:
    string removeDuplicateLetters(string s) {
      stack<char> st;
      unordered_set<char> present;
      vector<int> last_index(26,-1);
      for(int i = 0;i<s.size();i++)
      {
        last_index[s[i]-'a'] = i;
      }
      for(int i = 0;i<s.size();i++)
      {
        char c = s[i];
        if(st.empty())
        {
          st.push(c);
          present.insert(c);
        }
        else
        {
          if(present.find(c)!=present.end()) continue;
          while(!st.empty() && st.top()>c && last_index[st.top()-'a']>i){
            char ch = st.top();
            st.pop();
            present.erase(ch);
          }
          if(present.find(c)==present.end())
          {
            st.push(c);
            present.insert(c);
          }
        }
      }
      string res = "";
      while(!st.empty())
      {
        res+=st.top();
        st.pop();
      }
      reverse(res.begin(),res.end());
      return res;
      
      
        
    }
};
