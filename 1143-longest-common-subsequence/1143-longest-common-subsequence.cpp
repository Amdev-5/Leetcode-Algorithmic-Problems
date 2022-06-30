class Solution {
public:
    /* Recursive
    int longestCommonSubsequence(string text1, string text2) {
        return lcs(text1,text2,text1.length(),text2.length());
    }
    int lcs(string s1,string s2,int i,int j)
    {
        if(i==0 || j==0)
            return 0;
        else
        {
        //if one character common 1++ and move in both string by -1
            if(s1[i-1]==s2[j-1])
                return 1+ lcs(s1,s2,i-1,j-1);
            else
            //max of one taken one not taken and vice versa
                return max(lcs(s1,s2,i-1,j),lcs(s1,s2,i,j-1));
        }
    }
};
*/

    
    
    
//dp solution
    
    
    
    
    
    
    
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text1.size()+1][text2.size()+1];
        for(int i = 0;i<text1.size()+1;i++)
        {
            dp[i][0] = 0;
        }
        for(int i = 0;i<text2.size()+1;i++)
        {
            dp[0][i] = 0;
        }
        for(int i = 1;i<text1.size()+1;i++)
        {
            for(int j = 1;j<text2.size()+1;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
        
    }
};
