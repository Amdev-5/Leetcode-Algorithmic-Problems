class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;
    for(int i = 0;i<grid.size();i++)
    {
      for(int j = 0;j<grid[0].size();j++)
      {
        if(grid[i][j]=='1')
        {
          res++;
          dfs(grid,i,j,m,n);
        }
      }
    }
    return res;
    
    
  }
  void dfs(vector<vector<char>>& grid, int i,int j, int m,int n)
    {
      if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0') return;
      grid[i][j]='0';
      dfs(grid,i,j+1,m,n);
      dfs(grid,i+1,j,m,n);
      dfs(grid,i,j-1,m,n);
      dfs(grid,i-1,j,m,n);
    }
};  /*
    vector<int> parent;
    vector<int> rank;
    int count = 0;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    //i*n+j
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i<m*n;i++)
        {
            parent.push_back(0);
            rank.push_back(0);
        }
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    parent[i*n+j]=(i*n+j);
                    rank[i*n+j] = 1;;
                    count++;
                }
            }
        }
        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    for(auto t: directions){
                        int r = t[0]+i;
                        int c = t[1]+j;
                        if(r>=0 && r<m && c>=0 && c<n && grid[r][c]=='1')
                        {
                            unio(i*n+j,r*n+c);// curr,new point
                            
                        }
                    }
                }
            }
        }
        return count;
        //so instead of using pair, we will use the count of position ie from 0 to  n^2-1

        
    }
    */
        
    
    /*
    Path compression 
    union by rank
    */
/*
    int find(int x)
    {
        if(parent[x]==x) return x;
        int temp = find(parent[x]);
        parent[x] = temp;
        return temp;
        
    }
    void unio(int x,int y)
    {
        int lx=find(x);
        int ly = find(y);
        if(lx!=ly)
        {
            /*
                If the rank of tree of lx is larger then add lx
                as the leader of ly, as it wont affect its rank
                and vice versa.
                
                If their rank is same, then do the same thing as above,
                but this time increase the rank of the tree you are 
                adding the new node to.
            */
/*
            if(rank[lx]>rank[ly]){
                parent[ly] = lx;
            }
            else if(rank[lx]<rank[ly]){
                parent[lx] = ly;
            }
            else
            {
                parent[lx] = ly;
                rank[ly]++;
            }
            count--;
            
        }
        
        
    }
};
*/
    /*
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        //vector<vector<int>> visited;
        //*for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                visited[i][j] = 0;
            }
        }
        /*
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    result++;
                    dfs(grid,i,j);
                }
            }
        }
        return result;
        
        
    }
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]=='0') return;
        grid[i][j] = '0';
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        
    }
};
*/