class Solution {
public:
    vector<vector<string>> res;
    bool is_val(vector<string>& board,int row,int col)
    {
        //check for column
        for(int i = row;i>=0;i--)
        {
            if(board[i][col]=='Q')
                return false;
        }
        //check for left upper diagonal
        for(int i = row,j=col;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        //check for right upper diagonal
        for(int i = row,j=col;i>=0&&j<board.size();i--,j++)
        {
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
    void dfs(vector<string>& board,int row)
    {
        if(row==board.size())
        {
            res.push_back(board);
            return;
        }
        for(int i=0;i<board.size();i++)
        {
            if(is_val(board,row,i))
            {
                board[row][i] = 'Q';
                dfs(board,row+1);
                board[row][i] = '.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        dfs(board,0);
        return res;   
    }
};


/* Dry Run
dfs(board,0)





*/

/*
we can vector<vector<int>> as vectors containing each index having which queen 
ie one of the vector 2 3 1 4   
and finally traverse and make a vector<vector<string>> and return 

different permutation we need to set but exclusively need to find that in that permutation if diagonally some queen is not attacking other queen 
1 2 3 4 is not valid because of diagonal attack

how can we chack diagonal attack?
2 4 3 1
if basically these are coordiante 1,2 2,4 3,3 4,1
1,2 make sure 2,1 2,3 3,4 can't fill
ie m,n ensures if m+i,n+i || m-i,n-i || m+i,n-i ||  m-i,n-i
so like when we are pushing 3,3 we need to check if 


1 2 3 4 
1 2 4 3
1 3 2 4
1 3 4 2 
1 4 2 3 
1 4 3 2
let suppose x,y coordinate
for(int i=x,j=y;i<=m,j<=n;i++,j++)
{
   if(i,j already present)
   {
     not valid 
   }
}
     


*/