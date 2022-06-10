class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int i = 0;
    int j = 0;
    int res = 0;
    int n = s.size();
    //i is left j is right when we encounters a  character that is already present while i++
    while(i<n && j<n)
    {
      if(!set.count(s[j]))
      {
        set.insert(s[j]);
        j++;
        res = max(res,j-i);
      }
      else
      {
        set.erase(s[i]);
        i++;
      }
    }
    return res;
    
    
    
    
    
    
    
  }
};
    
    
    
    
    
    
    
    
    
    
    /*
    int i = 0,j = 0,res = 0,n =s.size();
    unordered_set<char> set;
    while(i<n && j<n)
    {
      if(set.find(s[j])==set.end())//if set doesn't contain this new element then add this element and increment j by 1 update the res by max(j-i+1,res)
      {
        set.insert(s[j]);
        res = max(res,j-i+1);
        j++;
      }
      else
      {//if new element is already present in set then slide the window by one ie increment i by 1
        set.erase(s[i]);
        i++;
      }
    }
    return res;
  }
};
      
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
        
    */
        
