class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int num = strs.size();
        string temp = strs[0];
        for(int i = 0;i<strs.size();i++)
        {
            if(strs[i].length()<temp.length())
            {
                temp = strs[i];
            }
        }
        int n = temp.length();
        for(int i =0;i<n;i++)
        {
            
            for(int j = 1;j<num;j++)
            {
                if(strs[0][i]!=strs[j][i])
                {
                    return res;
                    
                    
                }
                
                
                
            }
            res = res+ strs[0][i];
        }
        return res;
        
    }
};