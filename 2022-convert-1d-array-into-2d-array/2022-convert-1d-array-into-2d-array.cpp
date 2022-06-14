class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& mat, int r, int c) {
      int m = mat.size();
      int n = 1;
      vector<vector<int>> v(r,vector<int>(c,0));
      int o = m*n;
      if(r*c!=o) return {};
      for(int i = 0;i<m*n;i++)
      {
        v[i/c][i%c] = mat[i/n];
        
      }
      return v;
        
    }
};