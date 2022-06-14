class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
      int m = mat.size();
      int n = mat[0].size();
      vector<vector<int>> v(r,vector<int>(c,0));
      int o = m*n;
      if(r*c!=o) return mat;
      for(int i = 0;i<m*n;i++)
      {
        v[i/c][i%c] = mat[i/n][i%n];
        
      }
      return v;
      //r = 1, c = 4
      // 3%1 3/4
        
    }
};