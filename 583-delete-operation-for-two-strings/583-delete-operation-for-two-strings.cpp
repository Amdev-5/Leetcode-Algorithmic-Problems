class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int dp[m+1][n+1];
        dp[0][0] = 0;
        for(int i = 1;i<=m;i++)
        {
            dp[i][0] = i;
        }
        for(int i = 1;i<=n;i++)
        {
            dp[0][i] = i;
        }
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1+ min(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[m][n];
            
    }
};
    
    
    
    
    
    
    
    /* Reccursive 
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        return rec(word1,word2,m,n);
        
        
        
    }
    int rec(string word1,string word2,int i,int j)
    {
        if(i==0)
            return j;
        if(j==0)
            return i;
        if(word1[i-1]==word2[j-1])
            return rec(word1,word2,i-1,j-1);
        return 1+min(rec(word1,word2,i-1,j),rec(word1,word2,i,j-1));
    }
    
};

*/