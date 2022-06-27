class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
      unordered_map<int,int> m;
      for(int i= 0;i<edges.size();i++)
      {
        m[edges[i][0]]++;
        m[edges[i][1]]++;
      }
      for(auto t: m)
      {
        if(t.second!=1)
          return t.first;
      }
      return 0;
        
    }
};