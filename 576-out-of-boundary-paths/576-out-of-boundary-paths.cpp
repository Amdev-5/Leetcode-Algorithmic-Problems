class Solution {
public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    int mod = 1e9 +7;
    int dp[maxMove+1][m][n];
    memset(dp,0,sizeof(dp));
    //vector<vector<vector<int>>> dp(maxMove+1,vector<vector<int>>(m,vector<int>(n,0)));
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    for(int step = 1;step<=maxMove;step++)
    {
      for(int x = 0;x<m;x++)
      {
        for(int y = 0;y<n;y++)
        {
          for(int d=0;d<4;d++)
          {
            int a = x+dir[d][0],b = y+dir[d][1];
            if(a<0 || b<0 || a==m || b==n) dp[step][x][y] = (dp[step][x][y]+1)%mod;
            else
            {
              dp[step][x][y] = (dp[step][x][y]%mod+dp[step-1][a][b]%mod)%mod;
            }
          }
        }
      }
    }
    return dp[maxMove][startRow][startColumn];
    /*
    for(int i = maxMove;i>=0;i--)
    {
      for(int j=m;j>=0;j--)
      {
        for(int k = n;k>=0;k--)
        {
          dp[i][j][k] = dp[i+1][j+1][k]+dp[i+1][j][k+1];
        }
      }
    }
    */
    return dp[maxMove][startRow+1][startColumn+1];
    
    
  }
  /* Memoize
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<vector<int>>> dp(maxMove+2,(vector<vector<int>>(m+2,vector<int>(n+2,-1))));
    return helper(dp,m,n,maxMove,startRow+1,startColumn+1);
      
    }
  int helper(vector<vector<vector<int>>> & dp,int m,int n,int maxMove,int startRow,int startColumn)
  {
    if(startRow==0 || startColumn==0 || startRow==m+1 || startColumn==n+1) return dp[maxMove][startRow][startColumn] = 1;
    if(maxMove==0) return dp[maxMove][startRow][startColumn] = 0;
    int res = 0;
    res+=helper(dp,m,n,maxMove-1,startRow-1,startColumn);
    res+= helper(dp,m,n,maxMove-1,startRow,startColumn-1);
    res+=helper(dp,m,n,maxMove-1,startRow+1,startColumn);
    res+=helper(dp,m,n,maxMove-1,startRow,startColumn+1);
    return dp[maxMove][startRow][startColumn] = res;
    
  }
  */
  /* 4^N Recursive
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
      if(startRow<0 || startColumn<0 || startRow==m || startColumn==n) return 1;
      if(maxMove==0) return 0;
      int res = 0;
      res+=findPaths(m,n,maxMove-1,startRow-1,startColumn);
      res+= findPaths(m,n,maxMove-1,startRow,startColumn-1);
      res+=findPaths(m,n,maxMove-1,startRow+1,startColumn);
      res+=findPaths(m,n,maxMove-1,startRow,startColumn+1);
      return res; 
    }
    */

};