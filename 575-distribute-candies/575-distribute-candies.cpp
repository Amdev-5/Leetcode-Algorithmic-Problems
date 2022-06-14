class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
      unordered_set<int> set;
      for(int i = 0;i<candyType.size();i++)
      {
        set.insert(candyType[i]);
      }
      if(set.size()>=candyType.size()/2) return candyType.size()/2;
      return set.size();
        
    }
};