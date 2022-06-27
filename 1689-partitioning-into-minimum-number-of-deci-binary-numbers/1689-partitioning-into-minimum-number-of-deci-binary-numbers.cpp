class Solution {
public:
    int minPartitions(string n) {
      int max_dig = 0;
      for(int i = 0;i<n.size();i++)
      {
        if((n[i]-'0')>max_dig) max_dig = n[i]-'0';
      }
      return max_dig;
        
    }
};