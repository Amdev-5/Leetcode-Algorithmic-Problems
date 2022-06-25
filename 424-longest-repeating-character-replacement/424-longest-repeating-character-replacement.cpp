class Solution {
public:
    int characterReplacement(string s, int k) {
      int start = 0;
      int end = 0;
      int res = 0;
      vector<int> count(26,0);
      int localMaxFreq = 0;
      for(;end<s.size();end++)
      {
        count[s[end]-'A']+=1;
        localMaxFreq = max(localMaxFreq,count[s[end]-'A']);
        if((end-start+1)-localMaxFreq>k){
          res = max(res,(end-start));
          count[s[start]-'A']-=1;
          start+=1;
          localMaxFreq = *(max_element(count.begin(),count.end()));
        }
        
      }
      return max(res,end-start);
      
    }
};
/*
A
AA
AAA
AAAA





*/