class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n = matrix.size();
      int m = matrix[0].size();
      int r = n-1;
      while(r>=0 && matrix[r][0]>target)
      {
        r--;
      }
      int j = 0;
      while(r>=0 && j<m)
      {
        if(matrix[r][j]>target) r--;
        else if(matrix[r][j]==target) return true;
        else j++;
      }
      return false;
    }
};